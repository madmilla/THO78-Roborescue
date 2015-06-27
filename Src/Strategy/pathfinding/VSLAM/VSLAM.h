/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VSLAM.h
* @date Created: 6/21/2015
* @version 1.0
*
* @author Coen Andriessen
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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

#ifndef VSLAM_H
#define VSLAM_H

#include <iostream>
#include "Map.hpp"
#include "virtualRosbee.h"
#include "mapLogicVSLAM.h"
#include "route.h"
#include "MapSearchNode.h"
#include "virtualLidar.h"

class VSLAM
{
public:
	/**
	* @fn	VSLAM(Map map, virtualrosbee *rosbee, MapSearchNode mapSearchNode, Route *route, MapLogicVSLAM mapLogicVSLAM, virtuallidar *virtuallidar);
	*
	* @brief	Constructor of the class VSLAM.
	*/
	VSLAM(Map* map, virtualRosbee *rosbee, Route *route, virtualLidar *virtuallidar);
	/**
	* @fn	~VSLAM();
	*
	* @brief	Destructor of the class VSLAM.
	*/
	~VSLAM();
	/**
	* @fn	void run();
	*
	* @brief	Function for scanning a unknown area with VSLAM. Each time run is called the rosbee receives a waypoint. 
	*/
    void run();
	/**
	* @fn	wholeRouteInRangevirtuallidar();
	*
	* @brief	Function to check if the whole route is in the range of the lidar.
	* We want to check this to guarantee that we have the most efficient route
	* to scan the unknown area. The distances to walls and objects is now the lidar range.
	*
	* @return bool iswholeRouteInRangeVirtualLidar
	*/
	bool wholeRouteInRangevirtuallidar();
	/**
	* @brief bool_isVSLAMDone variable
	*/
	bool bool_isVSLAMDone = false;
	/**
	* @fn	void changeDirection();
	*
	* @brief	Function to check if the direction of the rosbee is changed.
	* When SLAM start make sure that the direction of the rosbee is N.
	*/
	void changeDirection();
	/**
	* @fn	void run();
	*
	* @brief	Function to send the rosbee to the next way point of the route.
	* We needs to convert the waypoint because the rosbee wants a relative way point.
	*
	* @param int x
	* @param int y
	*/
	void moveRosbeeTo(int x, int y);
private:
	/**
	* @brief Map object.
	*/
    Map* map;
	/**
	* @brief virtualrosbee object.
	*/
	virtualRosbee *virtualrosbee;
	/**
	* @brief MapSearchNode object.
	*/
    MapSearchNode* mapSearchNode;
	/**
	* @brief MapLogicVSLAM object.
	*/
	MapLogicVSLAM* mapLogicVSLAM;
	/**
	* @brief route object.
	*/
    Route * route;
	/**
	* @brief virtualvirtuallidar object.
	*/
	virtualLidar * virtuallidar;
	/**
	* @brief int * newRosbeeLocation variable to store the new location of the rosbee.
	*/
	int * newRosbeeLocation;
	/**
	* @brief int * tileLocation variable to store a tile location.
	*/
	int * tileLocation;
	/**
	* @brief char direction variable to store direction of rosbee.
	*/
	char direction = 'N';
};

#endif // VSLAM_H
