/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Lidar.h
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

#ifndef LIDAR_H
#define LIDAR_H
#include "rplidar.h"
#include <vector>
#include <string>

using namespace rp::standalone::rplidar;

//! Data structure for scan point
/*!
    The data structure for a single point scanned by the lidar
*/
struct scanDot
{
    uint8_t quality; //! Quality of the point scanned
    float angle; //! Angle of the lidar (0-360)
    float dist; //! Distance of the point scanned
};

//! Data structure for x and y coordinate
/*!
    The data structure for a single scanned point coordinate
*/
struct scanCoordinate
{
    int x; //! The X coordinate
    int y; //! The Y coordinate
};

class Lidar
{
public:
    //! The Contructor for the Lidar
    /*!
        Initialize the Lidar and set the default settings (baudrate)
        @param opt_com_path: Path to the com port which the lidar is attached to.
    */
    Lidar(const char *opt_com_path);
    //! Check the health of the RPLidar
    /*!
        Check the health and if an error is detected execute a software reboot.
        @return bool: true if OK false otherwise
    */
    bool checkRPLIDARHealth();
    //! Start a single scan with the lidar
    /*!
        A 360deg scan with the lidar which output the points found, points with quality 0
        will be filtered out. Also stores the scanData in a vector
        which contains all the data from single scans made.
        @return std::vector<scanDot>: vector with the scandata (angle,distance,quality)
    */
    std::vector<scanDot> startSingleLidarScan();
    //! Stop a lidar scan
    /*!
        Ask the RPLIDAR core system to stop the current scan operation and enter idle state
    */
    void stopLidarScan();
    //! Dispose the Lidar Driver
    /*!
        Dispose the RPLIDAR Driver Instance specified by the drv parameter in order to free memory
    */
    void disposeLidarDriver();
    //! Connect the drivers with lidar
    /*!
        Open the specified serial port and connect to a target RPLIDAR device
    */
    void connectDriversLidar();
    //! Write (multiple) scan data to a file
    /*!
        Write all the data present in the scanData vector to a file
        @param fname The name of the output file (will be created)
    */
    void writeScanDataToFile(std::string fname);
    //! Write (multiple) scan coordinates to a file
    /*!
        Write all the data present in the scanCoord vector to a file
        @param fname The name of the output file (will be created)
    */
    void writeScanCoordsToFile(std::string fname);
    //! Get the scanData
    /*!
        Retrieve all the scanData present (can be from multiple scans)
        @return vector a vector with all the scandata
    */
    std::vector<scanDot> getScanData();
    //! Get the scan coordinates
    /*!
        Retrieve all the scan coordinates present (can be from multiple scans)
        @return vector a vector with a struct(x,y) containing all the scan coordinates
    */
    std::vector<scanCoordinate> getScanCoords();
    //! Print the scandata to the console
    /*!
        Print all the scanData to the console (stderr)
    */
    void printScanData();
    //! Convert a ScanDot to X and Y coordinates
    /*!
        Convert Angle and distance from a scanDot
        to X and Y coordinates
    */
    std::vector<scanCoordinate> convertToCoordinates(std::vector<scanDot>);

private:
    //! Path to the com port which the lidar is attached to.
    const char *opt_com_path;
    //! The baudrate used (For most RPLIDAR models, the baudrate should be set to 115200)
    _u32 opt_com_baudrate;
    //! Store results lidar operations
    u_result op_result;
    //! create the driver instance
    RPlidarDriver *drv;
    //! vector to store the scandata (angle,distance,quality)
    std::vector<scanDot> scanData;
    //! vector to store x and y coordinates
    std::vector<scanCoordinate> scanCoord;
};

#endif // LIDAR_H
