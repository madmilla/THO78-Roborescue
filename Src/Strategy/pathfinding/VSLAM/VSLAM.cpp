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

VSLAM::VSLAM(Map *map, virtualRosbee *virtualrosbee, Route* route, virtualLidar *virtuallidar){
    this->map = map;
	this->virtualrosbee = virtualrosbee;
    this->mapSearchNode = new MapSearchNode(map, route);
    this->route = route;
	this->mapLogicVSLAM = new MapLogicVSLAM(map, virtualrosbee, virtuallidar);
	this->virtuallidar = virtuallidar;
}

/**
 * Destructor of VSLAM.
 */

VSLAM::~VSLAM(){
    // Destructor
}

/**
 * Function for scanning a unknown area with VSLAM. Each time run is called the rosbee receives a waypoint.
 */

void VSLAM::run(){
	// Check if the Map is full scanned. 0 is a unscanned tile. When the maps has no unscanned tiles it means
	// that the whole map is scanned.
	if (map->contains(0)){
		// Set the tiles in range of the virtuallidar to scanned with the function below.
		mapLogicVSLAM->setTilesInRangevirtuallidar();
		// When we don't have a route we have to get a new route if this is possible of course.
		if (!Container::route.getSize()){
			// Get the tile location of a unscanned tile with the function below.
			tileLocation = mapLogicVSLAM->getUnscannedTile();
			std::cout << "tile location x " << tileLocation[0] << " tile location y " << tileLocation[1] << std::endl;
			std::cout << "virtualrosbee location x " << virtualrosbee->getVirtualRosbeeLocationX() << " virtualrosbee location y " << virtualrosbee->getVirtualRosbeeLocationY() << std::endl;
			// When the Map is still not full scanned get the path with a star to the unscanned tile.
			// The route will be saved in a vector of the class Route.
			if (map->contains(0)){
				mapSearchNode->Search(virtualrosbee->getVirtualRosbeeLocationX(), virtualrosbee->getVirtualRosbeeLocationY(), int(tileLocation[0]), int(tileLocation[1]));
			}
		}
		// Check if a star have found a route. When there is no route SLAM is done.
		if (mapSearchNode->notFindRoute == true){
			this->bool_isVSLAMDone = true;
		}
		// When we have a route we can send the next way point in the route to the rosbee.
		if (Container::route.getSize() >= 1){
			// Get the new destination for the virtualrosbee from the vector that contains the route to the unscanned tile.
			newRosbeeLocation = Container::route.getNewTile();
			// Check if the whole route is in the range of the lidar. When this is true we can clear the route. We don't 
			// want moving on scanned tiles.
			if (wholeRouteInRangevirtuallidar()){
				std::cout << "in range virtuallidar" << std::endl;
				Container::route.clearRoute();
			}
			// Checks if the new destination for the virtualrosbee is accessible.
			// When it's not accessible clear the route else send the virtualrosbee to the new location.
			if (map->getScaledHeuristicLocationValue(newRosbeeLocation[0], newRosbeeLocation[1]) == 9){
				Container::route.clearRoute();
			}			
			else{
				// Move the rosbee to next waypoint in the route.
				moveRosbeeTo((newRosbeeLocation[0] - virtualrosbee->getVirtualRosbeeLocationX()), (newRosbeeLocation[1] - virtualrosbee->getVirtualRosbeeLocationY()));
				// Function to change the direction of the rosbee.
				changeDirection();
				//virtualrosbee->moveTo((newRosbeeLocation[0] - virtualrosbee->getVirtualRosbeeLocationX())*map->getScale(), ((newRosbeeLocation[1] - virtualrosbee->getVirtualRosbeeLocationY())*map->getScale()));
				// Set the new x location of the rosbee.
				virtualrosbee->setVirtualRosbeeLocationX((newRosbeeLocation[0] - virtualrosbee->getVirtualRosbeeLocationX()));
				// Set the new y location of the rosbee.
				virtualrosbee->setVirtualRosbeeLocationY((newRosbeeLocation[1] - virtualrosbee->getVirtualRosbeeLocationY()));
				std::cout << "VirtualRosbee Location: " << virtualrosbee->getVirtualRosbeeLocationX() << " , " << virtualrosbee->getVirtualRosbeeLocationY() << std::endl;
				// Set the rosbee location on the map.
				map->setScaledLocationValue(virtualrosbee->getVirtualRosbeeLocationX(), virtualrosbee->getVirtualRosbeeLocationY(), 3);
			}
		}
	}
}

/**
 * Function to check if the whole route is in the range of the lidar.
 * We want to check this to guarantee that we have the most efficient route
 * to scan the unknown area. The distances to walls and objects is now the lidar range.
 */

bool VSLAM::wholeRouteInRangevirtuallidar(){
	// Loop through the route.
	for (WayPoint *i : Container::route.wayPoints){
		// If we found a unscanned tile return false.
		if(map->getScaledLocationValue(i->x, i->y) == 0){
			return false;
		}
	}
	// When we don't find a unscanned tile return true.
	return true;
}

/**
 * Function to check if the direction of the rosbee is changed.
 * When SLAM start make sure that the direction of the rosbee is N.
 */

void VSLAM::changeDirection(){
	// Check if the rosbee is moving west. True? Set direction to west.
	if ((newRosbeeLocation[0] - virtualrosbee->getVirtualRosbeeLocationX()) < 0){
		direction = 'W';
	} // Check if the rosbee is moving east. True? Set direction to east.
	else if ((newRosbeeLocation[0] - virtualrosbee->getVirtualRosbeeLocationX()) > 0){
		direction = 'E';
	} // Check if the rosbee is moving south. True? Set direction to south.
	else if ((newRosbeeLocation[1] - virtualrosbee->getVirtualRosbeeLocationY()) > 0){
		direction = 'S';
	} // Check if the rosbee is moving north. True? Set direction to north.
	else if ((newRosbeeLocation[1] - virtualrosbee->getVirtualRosbeeLocationY()) < 0){
		direction = 'N';
	}
}

/**
 * Function to send the rosbee to the next way point of the route.
 * We needs to convert the waypoint because the rosbee wants a relative way point.
 */

void VSLAM::moveRosbeeTo(int x, int y){
	// Converting the values when the direction is north.
	if (direction == 'N'){
		if (x == 0, y == 1){
			virtualrosbee->moveTo(0, -1);
		}
		else if(x == 0, y == -1){
			virtualrosbee->moveTo(0, 1);
		}
		else if (x == 1, y == 0){
			virtualrosbee->moveTo(1, 0);
		}
		else if (x == -1, y == 0){
			virtualrosbee->moveTo(-1, 0);
		}
	} // Converting the values when the direction is south.
	else if (direction == 'S'){
		if (x == 0, y == 1){
			virtualrosbee->moveTo(0, -1);
		}
		else if (x == 0, y == -1){
			virtualrosbee->moveTo(0, 1);
		}
		else if (x == 1, y == 0){
			virtualrosbee->moveTo(-1, 0);
		}
		else if (x == -1, y == 0){
			virtualrosbee->moveTo(1, 0);
		}
	} // Converting the values when the direction is west.
	else if (direction == 'W'){
		if (x == 0, y == 1){
			virtualrosbee->moveTo(-1, 0);
		}
		else if (x == 0, y == -1){
			virtualrosbee->moveTo(1, 0);
		}
		else if (x == 1, y == 0){
			virtualrosbee->moveTo(0, -1);
		}
		else if (x == -1, y == 0){
			virtualrosbee->moveTo(0, 1);
		}
	} // Converting the values when the direction is east.
	else if (direction == 'E'){
		if (x == 0, y == 1){
			virtualrosbee->moveTo(1, 0);
		}
		else if (x == 0, y == -1){
			virtualrosbee->moveTo(-1, 0);
		}
		else if (x == 1, y == 0){
			virtualrosbee->moveTo(0, 1);
		}
		else if (x == -1, y == 0){
			virtualrosbee->moveTo(0, -1);
		}
	}
}

