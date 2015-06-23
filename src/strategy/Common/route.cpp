/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Route.cpp
* @date Created: 6/21/2015
* @version 1.0
*
* @author Jacob Visser
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

#include "route.h"

/**
* Constructor of Route.
*/
Route::Route(){
	wayPoints.reserve(1);
}
Route::Route(std::vector<WayPoint> waypoints){
	this->waypoints = waypoints;
}

/**
* Destructor of Route.
*/
Route::~Route(){
}

/**
* Function to set a location x and location y in the vector.
*/
void Route::setRouteTile(int x, int y){
	this->pushWayPoint(new WayPoint(x, y));
}

/**
* Function that returns the next destination for the rosbee to reach the unscanned tile.
* tileLocation[0] will contain the x of the tile, tileLocation[1] will contain the y of the tile.
* Also the quaried tile will be removed from the vector.
*/
int * Route::getNewTile(){
	static int tileLocation[1];
	for (auto &i : wayPoints){
		tileLocation[0] = i->x;
		tileLocation[1] = i->y;
		wayPoints.erase(wayPoints.begin());
		break;
	}
	return tileLocation;
}

void Route::addRoutePart(Route in) { waypoints.insert(waypoints.end(), in.waypoints.begin(), in.waypoints.end()); }
std::ostream & operator<<(std::ostream & os, Route & l){
	std::stringstream output;
	for (auto i : l.waypoints){
		output << i.x << " " << i.y << " ";
    }
	return os << output.str();
}

void Route::randomRoute(int mapWidth, int mapHeight){
   int waypoints = rand() % 22 + 3;

   for(int i = 0; i < waypoints; i++){
       int randomX = rand() % mapWidth;
       int randomY = rand() % mapHeight;

       WayPoint* wayPoint = new WayPoint(randomX, randomY);

       wayPoints.push_back(wayPoint);
   }
}

/**
* Function that returns the size of vector std::vector <std::pair<int, int>> newRoute;.
*/
int Route::getSize(){
	return wayPoints.size();
}

WayPoint* Route::getWaypoint(int wayPoint){
    return wayPoints[wayPoint];
}

void Route::pushWayPoint(WayPoint* wayPoint){
    wayPoints.push_back(wayPoint);
}

/**
* Function that clears the vector std::vector <std::pair<int, int>> newRoute;.
*/
void Route::clearRoute(){
    wayPoints.clear();
}


void Route::scaleWaypoints(){
	for (int index = 0; index < waypoints.size(); index++){
		WayPoint point = waypoints.at(index);
		point.x = point.x*scale; point.y = point.y *scale; 
		waypoints.at(index) = point;
	}

}
