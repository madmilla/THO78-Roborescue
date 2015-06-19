/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file LidarController.h
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

#ifndef LIDARCONTROLLER_H
#define LIDARCONTROLLER_H

#include "Lidar.h"
#include "PointCloud.h"
#include <mutex>
#include <condition_variable>
#include "shapedetector.h"

class LidarController
{
public:
    //! The Contructor for the LidarThread
    /*!
        Initialize the LidarThread and set the lidar reference. QThread must be used
        to keep the GUI responsive to user input while scanning with the lidar
        @param &l: Reference to a Lidar instance
    */
	LidarController(Lidar &l, ShapeDetector & sD, Pointcloud & pCloud);
    //! Run the thread
    /*!
        Lidar scans will be performed untill user stops or pause it in the GUI. Scan output
        will be shown in the GUI.
    */
    void run();
    //! Resume the thread
    /*!
        Resume the thread which will start the lidar to scan
    */
    void resume();
    //! Pause the thread
    /*!
        Pause the thread which will also will pause the lidar with scanning
    */
    void pause();
    //! Set counter which contains the number of scans to execute
    /*!
        Set the counter which contains the number of scans to execute
        if set to -1 the lidar w
    */
    void setNumberOfScans(int number);
    //! Reset counter which contains the number of scans to execute
    /*!
        Reset the counter which contains the number of scans to execute
    */
    void resetNumberOfScans();
    //! Reset counter which contains the number of scans that are executed
    /*!
        Reset the counter which contains the number of scans that are executed
    */
    void resetScanCount();
    //! A boolean to stop the thread
    /*!
        Default to false, when set to true the thread will be stopped an terminated
        (after current lidar is finished)
    */
    bool Stop;

private:
    //! Reference to a lidar instance
    Lidar &lidar;
    //! Provide access serialization between threads
    std::mutex csync;
    //! Provide a condition variable for synchronizing threads
    std::condition_variable cpauseCond;
    //! True if thread is paused, false otherwise
    bool isPaused;
    //! Pointcloud object
    Pointcloud & pCloud;
    //! Number of scans to execute
    int numberOfScans;
    //! Amount of scans that are executed
    int scanCount;

	ShapeDetector & sD;
};

#endif // LIDARCONTROLLER_H
