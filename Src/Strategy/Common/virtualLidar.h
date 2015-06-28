/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VirtualLidar.h
* @date Created: 4/28/2015
* @version 1.0
*
* @author Coen Andriessen
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

#ifndef VIRTUALLIDAR_H
#define VIRTUALLIDAR_H

#include "Lidar.h"

class virtualLidar
{
public:
	/**
	* @fn	virtualLidar();
	*
	* @brief	Constructor of the class VirtualLidar.
	*/
	virtualLidar();
	/**
	* @fn	virtualLidar(Lidar* actualLidar);
	*
	* @brief	Constructor of the class VirtualLidar.
	*/
	virtualLidar(Lidar* actualLidar);
	/**
	* @fn	virtualLidar(Lidar* actualLidar);
	*
	* @brief	Constructor of the class VirtualLidar.
	*/
	~virtualLidar();
	/**
	* @fn	int getRange();
	*
	* @brief	Function to get the range of the VirtualLidar.
	*
	* @param	range
	*/
	int getRange();
	/**
	* @fn	void start(int x, int y,int angle);
	*
	* @brief	Function to start the VirtualLidar.
	*
	* @param	x
	* @param	y
	* @param	angle
	*/
	void start(int x, int y,int angle);
	/**
	* @fn	void sendLidarLocationStatus(int rosbeeX, int rosbeeY, int degrees);
	*
	* @brief	Function to send the VirtualLidar the rosbee location and his direction.
	*
	* @param	rosbeeX
	* @param	rosbeeY
	* @param	degrees
	*/
	void sendLidarLocationStatus(int rosbeeX, int rosbeeY, int degrees);
	/**
	* @brief actualLidar object.
	*/
	Lidar* actualLidar;
private:
	/**
	* @brief int range. Range of the VirtualLidar.
	*/
	int range = 7;
};

#endif // VIRTUALLIDAR_H
