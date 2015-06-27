/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mapLogicVSLAM.cpp
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

#include "mapLogicVSLAM.h"

/**
* Constructor of mapLogicVSLAM.
*/

MapLogicVSLAM::MapLogicVSLAM(Map * map, virtualRosbee * virtualrosbee, virtualLidar * virtuallidar){
	this->map = map;
	this->virtualrosbee = virtualrosbee;
	this->virtuallidar = virtuallidar;
}

/**
* Destructor of mapLogicVSLAM.
*/

MapLogicVSLAM::~MapLogicVSLAM(){
	// Destructor
}

/**
* Function to set tiles that are in the range of the virtual lidar on scanned.
*/

void MapLogicVSLAM::setTilesInRangevirtuallidar(){
	// Create temp variable to save degrees that are occupied by objects.
	std::vector<float> skip = {};
	// Draw a circle with the radius of the virtualLidar.
	for (int i = 1; i < virtuallidar->getRange(); i++){
		// Set tiles that are in the range of the circle on scanned.
		skip = map->addHalfValuedCircle(virtualrosbee->getVirtualRosbeeLocationX(), virtualrosbee->getVirtualRosbeeLocationY(), i, 5, skip);
	}
}

/**
* Function to get an unscanned tile in map.
*/

int * MapLogicVSLAM::getUnscannedTile(){
	// Create temp variable.
	static int tileLocation[1];
	// Search through the map for a unscanned tile.
	for (int iiy = 0; iiy < map->getScaledHeight(); iiy++){
		for (int iix = 0; iix < map->getScaledWidth(); iix++){
			// Check if the tile is unscanned (0).
			if (map->getScaledLocationValue(iix, iiy) == 0){
				// Set x value in temp variable.
				tileLocation[0] = iix;
				// Set y value in temp variable.
				tileLocation[1] = iiy;
				std::cout << tileLocation[0] << tileLocation[1] << std::endl;
				// Return the tile location.
				return tileLocation;
			}
		}
	}
	// When there is no tile found return -1 (error message).
	tileLocation[0] = -1;
	tileLocation[1] = -1;
	return tileLocation;
}