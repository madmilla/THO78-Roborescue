/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file AreaCoverageAlgorithm.h
* @date Created: 4/28/2015
* @version 1.0
*
* @author Mathijs Arends
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
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

#ifndef AREACOVERINGALGORITHM_H
#define AREACOVERINGALGORITHM_H

#include "waypoint.h"
#include "Map.hpp"
#include "VirtualQuadCopter.h"
#include <vector>
#include "route.h"
#include "aStar.h"

class AreaCoveringAlgorithm
{
public:
	/**
	* @brief	point astarfrom
	*/
	point astarfrom = point(0,0);
	/**
	* @brief	point astarto
	*/
	point astarto = point(0,0);
	/**
	* @fn	void setCopterSquare(VirtualQuadCopter copt, Map* Map);
	*
	* @brief	Set VirtualQuadCopter location on the map.
	*
	* @param	copt
	* @param	map
	*/	
	void setCopterSquare(VirtualQuadCopter copt, Map* Map);
	/**
	* @fn	int followCovered(VirtualQuadCopter *copter, Map* map, int wallnumber, int coveredNumber);
	*
	* @brief	this function makes the area coverage function foollow his own covered
	* 			area effectifly covering all the area's of the Map.
	*
	* @param	copter
	* @param	map
	* @param	wallnumber
	* @param	coveredNumber
	*
	* @return	0
	*/	
	int followCovered(VirtualQuadCopter *copter, Map* map, int wallnumber, int coveredNumber);
	/**
	* @fn	void registerLocation(Map*, VirtualQuadCopter*);
	*
	* @brief	This method sets empty the area's around the test copter to covered.
	*
	* @param	Map*
	* @param	VirtualQuadCopter*
	*/
	void registerLocation(Map*, VirtualQuadCopter*);
	/**
	* @fn	AreaCoveringAlgorithm(VirtualQuadCopter *copter, Map* mapp);
	*
	* @brief	Constructor of the class AreaCoverageAlgorithm.
	*
	* @param	copter
	* @param	mapp
	*/
	AreaCoveringAlgorithm(VirtualQuadCopter *copter, Map* mapp);
	/**
	* @fn	~AreaCoveringAlgorithm();
	*
	* @brief	Destructor of the class AreaCoverageAlgorithm.
	*
	* @param	copter
	* @param	mapp
	*/
    ~AreaCoveringAlgorithm();
	/**
	* @fn	int followWall(VirtualQuadCopter *copter, Map* map, int wallnumber);
	*
	* @brief	This function makes the area coverage algorithm follow the wall
	*
	* @param	copter
	* @param	map
	* @param	wallnumber
	*
	* @return	0
	*/
	int followWall(VirtualQuadCopter *copter, Map* map, int wallnumber);
	/**
	* @brief	Route results. Store results.
	*/
    Route result;
	/**
	* @fn	void drawWayPoints(Map*);
	*
	* @brief	Write waypoint to the map.
	*
	* @param	Map*
	*/
    void drawWayPoints(Map);
	/**
	* @fn	bool testCoverage();
	*
	* @brief	Checks if the route coverage the whole area.
	*
	* @return	bool
	*/
    bool testCoverage();
	/**
	* @fn	Route getRoute();
	*
	* @brief	Get route generate by AreaCoverageAlgorithm.
	*
	* @return	route
	*/
	Route getRoute();
private:
	/**
	* @fn	bool isCoveredInDirection(Dimension d, VirtualQuadCopter* t);
	*
	* @brief	This function checks if the VirtualQuadCopter is covered in the given direction it
	*			not only checks directly in front of it but in front of the entire sight range of the copter.
	*
	* @param	d
	* @param	t
	*
	* @return	uncovered
	*/
	bool isCoveredInDirection(Dimension d, VirtualQuadCopter* t);
	/**
	* @fn	bool isBoxedIn(VirtualQuadCopter*, Map* map);
	*
	* @brief	this method checks if there are uncovered areas around the copter.
	*			if there are empty areas it will return false else true.
	*
	* @param	VirtualQuadCopter*
	* @param	map
	*
	* @return	isBoxedIn
	*/
	bool isBoxedIn(VirtualQuadCopter*, Map* map);
	/**
	* @fn	void moveBackOnRoute(VirtualQuadCopter* copter);
	*
	* @brief	this function moves the VirtualQuadCopter back on the
	*			route and keeps track of howfar it went back.
	*
	* @param	copter*
	*/
	void moveBackOnRoute(VirtualQuadCopter* copter);
	/**
	* @fn	int pointOn(int x, int y, VirtualQuadCopter *copter, Map* Map);
	*
	* @brief	this function returns the value on the point of the given Map.
	*
	* @param	x
	* @param	y
	* @param	copter
	* @param	map
	*
	* @return	value
	*/
    int pointOn(int x, int y, VirtualQuadCopter *copter, Map* Map);
    void goForward();
	/**
	* @brief	bool moveingBack. Is the VirtualQuadCopter moveingback?
	*/
    bool moveingBack;
	/**
	* @brief	int movesBack. Store movesBack.
	*/
    int movesBack = 0;
	/**
	* @brief	int stuckWaypointIndex. Variable to save waypoint when stuck.
	*/
    int stuckWaypointIndex;
	/**
	* @brief	Map* globalMap
	*/
	Map* globalMap;
};

#endif // AREACOVERINGALGORITHM_H
