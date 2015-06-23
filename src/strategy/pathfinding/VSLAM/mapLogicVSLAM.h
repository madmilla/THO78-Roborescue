/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mapLogicVSLAM.h
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

#ifndef MAPLOGICVSLAM_H
#define MAPLOGICVSLAM_H

#include "../../../map/MapStructure/map.hpp"
#include "../../Common/Rosbee.h"
#include "../../Common/lidar.h"

class mapLogicVSLAM
{
public:
	/**
	* @fn	mapLogicVSLAM(map * Map, Rosbee * rosbee, Lidar * lidar);
	*
	* @brief	Constructor of the class mapLogicVSLAM.
	*/
	mapLogicVSLAM(map * Map, Rosbee * rosbee, Lidar * lidar);
	/**
	* @fn	~mapLogicVSLAM();
	*
	* @brief	Destructor of the class mapLogicVSLAM.
	*/
	~mapLogicVSLAM();
	/**
	* @fn	void setTilesInRangeLidar();
	*
	* @brief	Function to set the tiles in range of the LIDAR.
	*/
	void setTilesInRangeLidar();
	/**
	* @fn	int * getUnscannedTile();
	*
	* @brief	Function that returns the x and y of a unscanned tile in the map.
	*
	* @return	int * with the x and y of the unscanned tile in the map.
	*			x = tileLocation[0] and y = tileLocation[1].
	*/
	int * getUnscannedTile();
	/**
	* @fn	bool isMapFullyScanned();
	*
	* @brief	Function that checks if the map is fully scanned and returns the value.
	*
	* @return	bool true of false if the map is fully scanned.
	*/
	bool isMapFullyScanned();
	/**
	* @brief Map object.
	*/
	map * Map;
	/**
	* @brief rosbee object.
	*/
	Rosbee * rosbee;
	/**
	* @brief lidar object.
	*/
	Lidar * lidar;
};

#endif // MAPLOGICVSLAM_H
