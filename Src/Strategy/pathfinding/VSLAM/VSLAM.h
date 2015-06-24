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
#include "../../../map/MapStructure/map.hpp"
#include "../../Common/virtualRosbee.h"
#include "mapLogicVSLAM.h"
#include "../../Common/route.h"
#include "../AStar/MapSearchNode.h"
#include "../../Common/virtualLidar.h"

class VSLAM
{
public:
	/**
	* @fn	VSLAM(map *Map, virtualrosbee *rosbee, MapSearchNode *mapSearchNode, Route *route, mapLogicVSLAM *MapLogicVSLAM, virtuallidar *virtuallidar);
	*
	* @brief	Constructor of the class VSLAM.
	*/
	VSLAM(map *Map, virtualRosbee *rosbee, Route *route, virtualLidar *virtuallidar);
	/**
	* @fn	~VSLAM();
	*
	* @brief	Destructor of the class VSLAM.
	*/
	~VSLAM();
	/**
	* @fn	void run();
	*
	* @brief	Function to start the scanning of the unknown area. The function is not recursive. Each time the funcion is 
	* called the virtualrosbee wil get a new destination from the function. 
	*/
    void run();
	bool wholeRouteInRangevirtuallidar();
	bool bool_isVSLAMDone = false;
private:
	/**
	* @brief Map object.
	*/
    map *Map;
	/**
	* @brief virtualrosbee object.
	*/
	virtualRosbee *virtualrosbee;
	/**
	* @brief mapSearchNode object.
	*/
    MapSearchNode *mapSearchNode;
	/**
	* @brief MapLogicVSLAM object.
	*/
	mapLogicVSLAM *MapLogicVSLAM;
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
};

#endif // VSLAM_H
