/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			aStar.h
* @date Created:	2015-06-17
*
*  @author	Yorrick Lans
*  @author	Kjeld Perquin
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms,
*	with or without modification, are permitted provided that
*	the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice,
*	  this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice,
*	  this list of conditions and the following disclaimer in the documentation
*	  and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht
*	  nor the names of its contributors may be used to endorse or
*	  promote products derived from this software without
*	  specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
*	BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
*	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*	IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
*   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
*	OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
*	OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef _A_STAR_H
#define _A_STAR_H

#include <vector>
#include <array>
#include "Route.h"
#include "mapImplementation.hpp"

//	pair of ints representing a coordinate
typedef std::pair<int, int> Coordinate;

class aStar
{
public:
	
	explicit aStar();
	~aStar();
	/** /brief Find the fastest path from the start coordinates to the end coordinates on the given map
	*
	*	/param startX x coordinate of the starting point
	*	/param startY y coordinate of the starting point
	*	/param endX x coordinate of the ending point
	*	/param endY y coordinate of the ending point
	*	/param theMap the map where the path has to be found on
	*	/return A vector of the coordinates of the path from start to end. will return an empty vector when
	*		no path is found.
	**/
	std::vector<std::pair<int, int>> findPath(int startX, int startY, int endX, int endY, const mapImplementation& theMap);

	/**	/brief Get the distances to the endpoint around the given coordinate on the given map
	*
	*	/param coordinate the coordinate on the map you want to test
	*	/param theMap the map on which the coordinate will be checked
	*	/return An array of 4 coordinates with their distances to the endpoint. will return a negative
	*		distance when the coordinate is out of the map bounds, is an obstacle or is a coordinate
	*		in closedcells.
	**/
	std::array<std::pair<Coordinate, int>, 4> getDistances(Coordinate coordinate, const mapImplementation& theMap);

	/**	/brief Get the shortest distance from 4 coordinates with their distances to the endpoint
	*
	*	/param distances an array of 4 elements which contain coordinates with their distances
	*	/return the coordinate with the closest distance to the endpoint
	**/
	Coordinate getShortestDistance(std::array<std::pair<Coordinate, int>, 4> distances);


	Route getRoute(std::vector<std::pair<int, int>>);
private:
	std::vector<Coordinate> closedCells;
	std::vector<Coordinate> openCells;
	Coordinate endPoint;
	Coordinate startPoint;
	//const int width = 60;
	//const int height = 60;
	//Map map;
};
#endif
