/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Route.h
* @date Created: 6/21/2015
* @version 1.5
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

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include "waypoint.h"
#include <sstream>
#include <iostream>

class Route
{
public:
	/**
	* @fn	Route();
	*
	* @brief	Constructor of the class Route.
	*/
    Route();
    Route(std::vector<WayPoint> waypoints);
	/**
	* @fn	~Route();
	*
	* @brief	Destructor of the class Route.
	*/
    ~Route();

	/**
	* @fn	void setRouteTile(int x , int y);
	*
	* @brief	Function to set the route to the unscanned tile the vector std::vector <std::pair<int, int>> newRoute;
	*
	* @param int x	the x value of a step.
	* @param int y	the y value of a step.
	*/
    void setRouteTile(int x , int y);

	/**
	* @fn	int * getNewTile();
	*
	* @brief	Function to get the x and y for the new destination of the rosbee.
	*
	* @return int * tileLocation	value x and y of the tile.
	*/
	int * getNewTile();

	/**
	* @fn	int getSize();
	*
	* @brief	Function to get the size of the vector std::vector <std::pair<int, int>> newRoute;
	*
	* @return int newRoute.size();	size of the vector std::vector <std::pair<int, int>> newRoute;
	*/
	int getSize();
    
  void addRoutePart(Route);

    std::vector<WayPoint> waypoints;

    int scale;
    friend std::ostream & operator<<(std::ostream & os, Route & l);
    void scaleWaypoints();

    void randomRoute(int mapWidth, int mapHeight);

    WayPoint* getWaypoint(int wayPoint);

    void pushWayPoint(WayPoint* wayPoint);

  /**
	* @fn	void clearRoute();
	*
	* @brief	Function to clear the vector std::vector <std::pair<int, int>> newRoute;
	*/
  void clearRoute();

  /**
	* @brief std::vector <WayPoint> newRoute;	vector to store the route for rosbee to the unscanned tile.
	*/
	std::vector<WayPoint*> wayPoints;

private:
    //std::vector<WayPoint*> wayPoints; //mathijs code not prepared for this
};
#endif // ROUTE_H
