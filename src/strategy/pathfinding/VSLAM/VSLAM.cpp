/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VSLAM.cpp
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

#include "VSLAM.h"

/**
 * Constructor of VSLAM.
 */

VSLAM::VSLAM(map *Map, Rosbee *rosbee,Route* route, Lidar *lidar){
    
    
    this->Map = Map;
    this->rosbee = rosbee;
    this->mapSearchNode = new MapSearchNode(Map, route);
    this->route = route;
	this->MapLogicVSLAM = new mapLogicVSLAM(Map, rosbee, lidar);
	this->lidar = lidar;
}

/**
 * Destructor of VSLAM.
 */

VSLAM::~VSLAM(){
    // Destructor
}

/**
 * Function for scanning a unknown area with VSLAM. First will be checked if the map is fully scanned. When the map is not fully scanned.
 * We need to set the tiles on scanned which are in the range of the LIDAR. When there is no route (Container::route.getSize()) we need to
 * get a new route for the rosbee. Now we check if there is on the map a tile which is not scanned. When we find a tile and the map is not
 * fully scanned we get the route to the unscanned tile with a a star algorithm. Each move will be stored in a vector.
 * When we have a route we get the first tile location in the vector and we say to the rosbee go to that location. When the tile location 
 * is not accessible we clear the vector and get a new route for a new unscanned tile.
 */

void VSLAM::run(){
	// Check if the map is fully scanned.
	if (!MapLogicVSLAM->isMapFullyScanned()){
		//Map->print();
		// Set the tiles in range of the lidar to scanned with the function below.
		MapLogicVSLAM->setTilesInRangeLidar();
		// Do this when there is no route.
		if (!Container::route.getSize()){
			// Get the tile location of a unscanned tile with the function below.
			tileLocation = MapLogicVSLAM->getUnscannedTile();
			std::cout << "tile location x " << tileLocation[0] << " tile location y " << tileLocation[1] << std::endl;
			std::cout << "rosbee location x " << rosbee->getRosbeeLocationX() << " rosbee location y " << rosbee->getRosbeeLocationY() << std::endl;
			// When the map is still not fully scanned get the path with a star to the unscanned tile.
			if (!MapLogicVSLAM->isMapFullyScanned()){
				mapSearchNode->Search(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), int(tileLocation[0]), int(tileLocation[1]));
			}
		}
		// Do this when there is a route.
		if (Container::route.getSize() >= 1){
			// Get the new destination for the rosbee from the vector that contains the route to the unscanned tile.
			newRosbeeLocation = Container::route.getNewTile();
			// Checks if the new destination for the rosbee is accessible.
			// When it's not accessible clear the route else send the rosbee to the new location.
			if (wholeRouteInRangeLidar()){
				std::cout << "in range lidar" << std::endl;
				Container::route.clearRoute();
			}
			if (Map->getScaledHeuristicLocationValue(newRosbeeLocation[0], newRosbeeLocation[1]) == 9){
				Container::route.clearRoute();
			}			
			else{
				rosbee->moveTo((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()), (newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
				rosbee->setRosbeeLocationX((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()));
				rosbee->setRosbeeLocationY((newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
				std::cout << "Rosbee Location: " << rosbee->getRosbeeLocationX() << " , " << rosbee->getRosbeeLocationY() << std::endl;
				Map->setScaledLocationValue(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), 3);
			}
		}
	}
}

bool VSLAM::wholeRouteInRangeLidar(){
	for (WayPoint *i : Container::route.wayPoints){
		if(Map->getScaledLocationValue(i->x, i->y) == 0){
			return false;
		}
	}
	return true;
}

