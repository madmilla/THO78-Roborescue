/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file MapLogicVSLAM.cpp
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

MapLogicVSLAM::MapLogicVSLAM(Map * map, virtualRosbee * virtualrosbee, virtualLidar * virtuallidar){
	this->map = map;
	this->virtualrosbee = virtualrosbee;
	this->virtuallidar = virtuallidar;
}

MapLogicVSLAM::~MapLogicVSLAM(){
	// Destructor
}

/**
* Set the tiles is the virtuallidar range on scanned. Get the location where the virtualrosbee is on that moment.
* When the location is decided pull the range of the virtuallidar from the virtualrosbee location.
* We have now the tile location (0,0) of the tiles in the virtuallidar range.
* Apply now the virtuallidar range with 1 by the tile location of (0,0) and we get the location (max,0).
* When we do this x times(virtuallidar range) we get the final the location (max, max) for the tiles in the virtuallidar range.
*/

void MapLogicVSLAM::setTilesInRangevirtuallidar(){
	std::vector<float> skip = {};
	for (int i = 1; i < virtuallidar->getRange(); i++){
		skip = map->addHalfValuedCircle(virtualrosbee->getVirtualRosbeeLocationX(), virtualrosbee->getVirtualRosbeeLocationY(), i, 5, skip);
	}
}

/**
* We loops trough the whole Map. For each tile check if the value is 0. 0 is the value of a tile which is not scanned.
* When we don't find any unscanned tiles return (-1,-1). When we find a unscanned tile return (x,y) of the tile.
*/

int * MapLogicVSLAM::getUnscannedTile(){
	static int tileLocation[1];
	for (int iiy = 0; iiy < map->getScaledHeight(); iiy++){
		for (int iix = 0; iix < map->getScaledWidth(); iix++){
			if (map->getScaledLocationValue(iix, iiy) == 0){
				tileLocation[0] = iix;
				tileLocation[1] = iiy;
				std::cout << tileLocation[0] << tileLocation[1] << std::endl;
				return tileLocation;
			}
		}
	}
	tileLocation[0] = -1;
	tileLocation[1] = -1;
	return tileLocation;
}