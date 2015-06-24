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

mapLogicVSLAM::mapLogicVSLAM(map * Map, virtualRosbee * rosbee, Lidar * lidar){
	this->Map = Map;
	this->rosbee = rosbee;
	this->lidar = lidar;
	
}

mapLogicVSLAM::~mapLogicVSLAM(){
	// Destructor
}

/**
* Set the tiles is the LIDAR range on scanned. Get the location where the rosbee is on that moment.
* When the location is decided pull the range of the LIDAR from the rosbee location.
* We have now the tile location (0,0) of the tiles in the LIDAR range.
* Apply now the LIDAR range with 1 by the tile location of (0,0) and we get the location (max,0).
* When we do this x times(LIDAR range) we get the final the location (max, max) for the tiles in the LIDAR range.
*/

void mapLogicVSLAM::setTilesInRangeLidar(){
	/*int x = rosbee->getRosbeeLocationX() - lidar->getRange();
	int y = rosbee->getRosbeeLocationY() - lidar->getRange();
	for (int i = 0; i < ((lidar->getRange() * 2) + 1); i++){
		for (int ii = 0; ii < ((lidar->getRange() * 2) + 1); ii++){
			if ((x + ii) >= 1 && (x + ii) <= (Map->getScaledWidth()-1) && (y + i) >= 1 && (y + i) <= (Map->getScaledHeight()-1)){
				if (Map->getScaledLocationValue((x + ii), (y + i)) == 0){
					Map->setScaledLocationValue((x + ii), (y + i), 2);
				}				
			}
		}
	}*/
	Map->addLIDARCircle(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), 2);
}

/**
* We loops trough the whole map. For each tile check if the value is 0. 0 is the value of a tile which is not scanned.
* When we don't find any unscanned tiles return (-1,-1). When we find a unscanned tile return (x,y) of the tile.
*/

int * mapLogicVSLAM::getUnscannedTile(){
	static int tileLocation[1];
	for (int iiy = 0; iiy < Map->getScaledHeight(); iiy++){
		for (int iix = 0; iix < Map->getScaledWidth(); iix++){
			if (Map->getScaledLocationValue(iix, iiy) == 0){
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

/**
* We loops trough the whole map. For each tile check if the value is 0. 0 is the value of a tile which is not scanned.
* When we see an unscanned tile return false. When we don't find a unscanned tile the map must be fully scanned
* so we can return true.
*/

bool mapLogicVSLAM::isMapFullyScanned(){
	for (int iiy = 0; iiy < Map->getScaledHeight(); iiy++){
		for (int iix = 0; iix < Map->getScaledWidth(); iix++){
			if (Map->getScaledLocationValue(iix, iiy) == 0){
				return false;
			}
		}
	}
	return true;
}