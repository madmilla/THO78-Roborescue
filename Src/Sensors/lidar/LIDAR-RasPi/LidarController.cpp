/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file LidarController.cpp
* @date Created: 29-04-2015
*
* @author Robbin van den Berg
* 
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#include "LidarController.h"
#include "PointCloud.h"

LidarController::LidarController(Lidar &l, ShapeDetector & sD, Pointcloud & pCloud) :
	pCloud(pCloud),
	sD( sD ),
    Stop(false),
    isPaused(false),
    lidar(l),
    numberOfScans(1),
    scanCount(0)
{
    lidar.connectDriversLidar();
}

void LidarController::run()
{
    resetScanCount();

    while(!Stop) {

        if(scanCount >= numberOfScans && numberOfScans != -1) {
			const Mat & image = sD.createImage(pCloud);
			std::vector<Line> lines = sD.searchLines(image);
			sD.writeLinesToConsole(lines);
            pause();
        }

        // Check if thread needs to be paused
        {
            std::unique_lock<std::mutex> lck(csync);
            if(isPaused){
                cpauseCond.wait(lck);
            }
        }

        std::vector<scanDot> data = lidar.startSingleLidarScan();

        if(!data.empty()) {
            std::vector<scanCoordinate> scanCoorde = lidar.convertToCoordinates(data);

            for (int pos = 0; pos < (int)scanCoorde.size(); ++pos) {
                pCloud.setPoint(scanCoorde[pos].x, scanCoorde[pos].y);
                fprintf(stderr,"scan: %d | x: %d , y: %d\n", scanCount, scanCoorde[pos].x, scanCoorde[pos].y);
            }
        }
        ++scanCount;
    }
    // reset the number of scans to make because scanning has stopped
    resetNumberOfScans();
}

void LidarController::resume()
{
    csync.lock();
    isPaused = false;
    csync.unlock();
    cpauseCond.notify_all();
}

void LidarController::pause()
{
    csync.lock();
    isPaused = true;
    csync.unlock();
}

void LidarController::setNumberOfScans(int number)
{
    resetScanCount();
    numberOfScans = number;
}

void LidarController::resetNumberOfScans()
{
    numberOfScans = 0;
}

void LidarController::resetScanCount()
{
    scanCount = 0;
}

