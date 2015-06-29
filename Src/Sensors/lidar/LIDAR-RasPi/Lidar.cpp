/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Lidar.cpp
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

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
#include <math.h>
#include "Lidar.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif

using namespace rp::standalone::rplidar;

Lidar::Lidar(const char *opt_com_path):
    opt_com_path(opt_com_path),
    opt_com_baudrate(115200), 	// Default baudrate of 115200 is recommended
    drv(RPlidarDriver::CreateDriver(RPlidarDriver::DRIVER_TYPE_SERIALPORT))
{
	connectDriversLidar();
}

void Lidar::connectDriversLidar()
{
    if (!drv) {
        fprintf(stderr, "insufficent memory, exit\n");
        exit(-2);
    }

    // make connection...
    if (IS_FAIL(drv->connect(opt_com_path, opt_com_baudrate))) {
        fprintf(stderr, "Error, cannot bind to the specified serial port %s.\n"
            , opt_com_path);
        disposeLidarDriver();
    }
}

std::vector<scanDot> Lidar::startSingleLidarScan()
{
    std::vector<scanDot> tempData;

    // check health...
    if (!checkRPLIDARHealth()) {
        fprintf(stderr, "rplidar not healthy");
        disposeLidarDriver();
    }
    else {

        // start scan...
        drv->startScan();

        // fetch result and print it out...
		const int nodeArrSize = 720;
        rplidar_response_measurement_node_t nodes[nodeArrSize]; 	
        size_t count = _countof(nodes);

        op_result = drv->grabScanData(nodes, count);

        if (IS_OK(op_result)) {
            drv->ascendScanData(nodes, count);

            for (int pos = 0; pos < (int)count ; ++pos) {

                if (nodes[pos].distance_q2) {
                    scanDot dot;

                    dot.quality = (nodes[pos].sync_quality >> RPLIDAR_RESP_MEASUREMENT_QUALITY_SHIFT);
                    dot.angle = (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT)/64.0f;
                    dot.dist = nodes[pos].distance_q2/4.0f;

                    tempData.push_back(dot);
                }
            }
            scanData.insert(scanData.end(),tempData.begin(),tempData.end());
        }
    }

    return tempData;
}

void Lidar::stopLidarScan()
{
    drv->stop();
}

void Lidar::disposeLidarDriver()
{
    drv->DisposeDriver(drv);
}

bool Lidar::checkRPLIDARHealth()
{
    u_result op_result;
    rplidar_response_device_health_t healthinfo;

    op_result = drv->getHealth(healthinfo);

    if (IS_OK(op_result)) { // the macro IS_OK is the preperred way to judge whether the operation is succeed.
        printf("RPLidar health status : %d\n", healthinfo.status);
        if (healthinfo.status == RPLIDAR_STATUS_ERROR) {
            fprintf(stderr, "Error, rplidar internal error detected. Please reboot the device to retry.\n");
            // enable the following code if you want rplidar to be reboot by software
            drv->reset();
            return false;
        } else {
            return true;
        }

    } else {
        fprintf(stderr, "Error, cannot retrieve the lidar health code: %x\n", op_result);
        return false;
    }
}

void Lidar::writeScanDataToFile(std::string fname)
{
    FILE *outputfile = fopen(fname.c_str(), "w");
    fprintf(outputfile, "#RPLIDAR SCAN DATA\n#COUNT=%d\n#Angule\tDistance\tQuality\n",scanData.size());
    for (int pos = 0; pos < (int)scanData.size(); ++pos) {
        fprintf(outputfile, "%.4f %.1f %d\n", scanData[pos].angle, scanData[pos].dist, scanData[pos].quality);
    }
    fclose(outputfile);
}

void Lidar::writeScanCoordsToFile(std::string fname)
{
    convertToCoordinates(scanData);

    FILE *outputfile = fopen(fname.c_str(), "w");
    fprintf(outputfile, "#RPLIDAR SCAN COORD\n#COUNT=%d\n#Xcoord\tYcoord\n",scanCoord.size());
    for (int pos = 0; pos < (int)scanCoord.size(); ++pos) {
        fprintf(outputfile, "%d %d\n", scanCoord[pos].x, scanCoord[pos].y);
    }
    fclose(outputfile);
}

std::vector<scanDot> Lidar::getScanData()
{
    return scanData;
}

void Lidar::printScanData()
{
    for (int pos = 0; pos < (int)scanData.size(); ++pos) {
        fprintf(stderr, "%.4f %.1f %d\n", scanData[pos].angle, scanData[pos].dist, scanData[pos].quality);
    }
}

std::vector<scanCoordinate> Lidar::convertToCoordinates(std::vector<scanDot> data)
{
    std::vector<scanCoordinate> tempData;

    for(int i = 0; i < (int)data.size(); ++i) {
        scanCoordinate tempCoord;
        tempCoord.y = (cos((data[i].angle * M_PI)/180)) * data[i].dist; // Devide by 180 to Convert Degrees to Radians
        tempCoord.x = (sin((data[i].angle * M_PI)/180)) * data[i].dist; // Devide by 180 to Convert Degrees to Radians

        scanCoord.push_back(tempCoord);
        tempData.push_back(tempCoord);
    }
    return tempData;
}

std::vector<Line> Lidar::start(float pX, float pY, float orientation){
	ShapeDetector sD;
	Pointcloud pCloud;
	std::vector<scanDot> data = startSingleLidarScan();

	if (!data.empty()) {
		std::vector<scanCoordinate> scanCoorde = convertToCoordinates(data);

		for (int pos = 0; pos < (int)scanCoorde.size(); ++pos) {
			if (scanCoorde[pos].x < 4000 & scanCoorde[pos].x > -4000 && scanCoorde[pos].y < 4000 && scanCoorde[pos]x > -4000){
				pCloud.setPoint(scanCoorde[pos].x, scanCoorde[pos].y);
			}
		}
	}
	Pointcloud::Point point;
	point.X = pX;
	point.Y = pY;
	pCloud.rotate(orientation);
	pCloud.setOffset(point);
	const Mat & image = sD.createImage(pCloud, SCALE);
	std::vector<Line> lines = sD.searchLines(image);
	std::vector<Circle> circles;
	sD.showObjects(lines, circles, image, image, Pointcloud::Point{ pCloud.getMinValues().X, pCloud.getMinValues().Y })

	for (auto l : lines){
		Line::Point begin{(l.getLine().begin_pos.x * SCALE) - pCloud.getMinValues().X, (l.getLine().begin_pos.y * SCALE) - pCloud.getMinValues().Y};
		Line::Point end{(l.getLine().end_pos.x * SCALE) - pCloud.getMinValues().X, (l.getLine().end_pos.y * SCALE) - pCloud.getMinValues().Y};
		l.setLine(begin,end);
	}
	sD.writeLinesToConsole(lines);

	return lines;
}
