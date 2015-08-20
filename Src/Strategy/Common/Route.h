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
#include <stdlib.h> 
#include <vector>
#include "WayPoint.h"
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

	/**
	* @fn	Route(std::vector<WayPoint> waypoints);
	*
	* @brief	Constructor of the class Route. 
	* 			Initialise route with existing vector of waypoints.
	*
	* @param	Vector of waypoints.
	*/
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
	* @brief	Function to set a location x and location y in wayPoints.
	* 			Makes a new waypoint, should be renamed to pushWayPoint(int x, int y),
	* 			but that breaks SLAM?
	*
	* @param 	x
	* @param 	y
	*/
    void setRouteTile(int x , int y);

	/**
	* @fn	int * getNewTile();
	*
	* @brief	Function to get the x and y for the new destination of the VirtualRosbee.
	*
	* @return	tileLocation
	*/
	int * getNewTile();

	/**
	* @fn	int getSize();
	*
	* @brief	Function to get the size of the waypoints vector;
	*
	* @return	int waypoint-vector size;
	*/
	int getSize() const;

	/**
	* @fn	void addRoutePart(Route);
	*
	* @brief	Function to add a route to this route.
	*
	* @param	Route
	*/
	void addRoutePart(Route);
	
	/**
	* @fn	friend std::ostream & operator<<(std::ostream & os, Route & l);
	*
	* @brief	Operator to print out a route.
	*
	* @param	os
	* @param	l
	*/
    friend std::ostream & operator<<(std::ostream & os, Route & l);

	/**
	* @fn	void scaleWaypoints();
	*
	* @brief	Function to scale the waypoints.
	* 			Deprecated, use scaleWaypoints(int scale).
	*/
    void scaleWaypoints();

	/**
	* @fn	void scaleWaypoints(int scale);
	*
	* @brief	Function to scale the waypoints.
	* 			
	* @param	scale
	*/
	void scaleWaypoints(int scale);

	/**
	* @fn	void randomRoute(int MapWidth, int MapHeight);
	*
	* @brief	Function to create a random route.
	*
	* @param	MapWidth
	* @param	MapHeight
	*/	
    void randomRoute(int MapWidth, int MapHeight);

	/**
	* @fn	WayPoint* getWaypoint(int wayPoint);
	*
	* @brief	Function that returns a waypoint from the std::vector<WayPoint*> wayPoints.
	*
	* @param	a wayPoint
	*/	
    WayPoint* getWaypoint(int wayPoint) const;

	/**
	* @fn	void pushWayPoint(WayPoint* wayPoint);
	*
	* @brief	Function to add a waypoint at the back of the std::vector<WayPoint*> wayPoints.
	*
	* @param	a wayPoint
	*/
    void pushWayPoint(WayPoint* wayPoint);

	/**
	* @fn	void clearRoute();
	*
	* @brief	Function to clear the std::vector<WayPoint*> wayPoints;
	*/
	void clearRoute();

	/**
	* @brief	std::vector<WayPoint> waypoints;
	* 			Some weird application used this, ??Pathfinding?? 
	* 		 
	*/
	std::vector<WayPoint> waypoints;

private:
	/**
	* @brief std::vector<WayPoint*> wayPoints;
	*/
	std::vector<WayPoint*> wayPoints;


	/**
	* @brief int scale variable.
	*/
    int scale;
};
#endif // ROUTE_H
