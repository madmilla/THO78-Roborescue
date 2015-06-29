/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Map.hpp
* @date Created: 06/24/2015
* @brief A class that contains the map and has the functions for adding objects to the map
*
* @author Jos Bijlenga, Marianne Delmaar, Mathijs Arends, Jasper Stas, Coen Andriessen
*
* @version 2.4
*
* @section LICENSE
* License: newBSD
*
* Copyright   2015, HU University of Applied Sciences Utrecht.
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


#ifndef Map_H
#define Map_H

#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>

#include "Point.hpp"
#include "Line.hpp"
#include "Polygon.h"
//#include "QuadCopter.h"
//#include "virtualRosbee.h"
//#include "virtualATV.h"
#include "aStar.h"
#include "MapImplementation.cpp"


class Map : public mapImplementation
{
public:
	//! Returns the scaled heuristic location value
	//! @param The x value
	//! @param The y value
	//! @return The the value of the scaled heuristic location
	int getScaledHeuristicLocationValue(int x, int y);

	//! Returns the scale value
	//! @return The scale value of the Map class
	int getScale();

	//! Constructor of the Map
	Map();

	//! Constructor of the Map with line object
	//! @param A line object
	Map(line & l);

	//! Constructor of Map with a vector of line objects
	//! @param A vector of line objects
	Map(std::vector<line> & l);

	//! Destructor of Map
	~Map();

	//! Debug function to print Map (implement?)
	//! @param Outputstream
	//! @param A map
	//! @return returns an outputstream
	friend std::ostream & operator<<(std::ostream & os, const Map & m);

	//! Checks if the the Map has the line parameter
	//! @param The line to be checked for presence in the Map
	//! @return The result of the search. True if found, otherwise false.
	bool hasLine(line & l);

	//! Checks if the the Map has all the lines from the parameter
	//! @param A vector of lines to be checked for presence in the Map
	//! @return The result of the search. True if all are found, otherwise false.
	bool hasLine(std::vector<line> & l);

	//! Get all the lines that intersect the point parameter
	//! @param The point to be checked for intersecting lines
	//! @return A vector of lines that intersect the point parameter.
	std::vector<line> getPointLines(point & p);

	//! Append a line to the Map
	//! @param A line to be appended to the Map data
	void appendLine(line l);

	//! Append a vector of lines to the Map
	//! @param A vector of lines to be appended to the Map data
	void appendLine(std::vector<line> & l);

	//! Remove a line from the Map data
	//! @param A line to be removed from the the Map data
	//! @return Return if a line equal to the parameter is still present after removal
	bool removeLine(line & l);

	//! Removes a vector of lines from the Map data
	//! @param A vector of lines to be removed from the the Map data
	//! @return Return if all the lines equal to the parameter are present after removal
	bool removeLine(std::vector<line> & l);

	//! Compares the current Map to the Map parameter
	//! @param The Map to compare with
	//! @return The result of the comparison. True if equal, otherwise false.
	bool equals(const Map & m);

	//! Get a part of the Map that lies within the bounds of the parameter
	//! @param An X-coordinate of the top left corner of the rectangle
	//! @param A Y-coordinate of the top left corner of the rectangle
	//! @param The width of the rectangle
	//! @param The height of the rectangle
	//! @return A Map within the region given as parameters
	Map getRegion(int x, int y, unsigned int width, unsigned int height);

	//! Get a part of the Map that lies within the bounds of the parameter
	//! @param The top left corner of the rectangle
	//! @param The width of the rectangle
	//! @param The height of the rectangle
	//! @return A Map within the region given as parameters
	Map getRegion(point & p, unsigned int width, unsigned int height);

	//2D vector to check if points are accessible and seen
	
	//! Check if the indices given are accessible
	//! @param The x index
	//! @param The y index
	//! @return The result of the accessible check
	bool isAccessible(int x, int y);
	
	//! Check if a destination is accessible from a location
	//! If the destination is not reachable it will be set unaccessible in the grid.
	//! @param The x coördinate of the starting point
	//! @param The y coördinate of the starting point
	//! @param The x coördinate of the destination
	//! @param The y coördinate of the destination
	bool isReachable(int x, int y, int x1, int y1);

	//! Check if a destination is accessible from a location
	//! If the destination is not reachable it will be set unaccessible in the grid.
	//! @param The x coördinate of the starting point
	//! @param The y coördinate of the starting point
	bool isReachable(point p, point p1);

	//! Sets the scale value of the map class 
	//! @param The x value is the new scale value
	void setScale(int x);
	
	//! Check if a scaled destination is accessible from a location
	//! @param The x index
	//! @param The y index
	//! @return The result of the accessible check
	bool isScaledAccessible(int x, int y);

	//! Adds object to position x,y
	//! @param A polygon p
	void addObject(polygon p);

	//! Fills object (circle or polygon) so that middle is not accessible
	//! @param vector with the object (circle or polygon)
	void fillObjects(std::vector<int> object);

	//! When pathfinding is done, make all cells unseen again. seen = false;	
	void makeUnseen();

	//! Sets the value of a location in the map
	//! @param The x index
	//! @param The y index
	//! @param The new value of the position x, y
	void setLocationValue(unsigned int x, int y, int value);

	//! Translate lines to points in 2d vector
	//! Translates a line vector to a grid Map
	//! Line data from the parameter will be translated to
	//! point data to the return.
	void translateToPoints();

	//! Returns the value of the location x, y
	//! @param The x index
	//! @param The y index
	//! @return the value of location x, y
	int getLocationValue(unsigned int x, unsigned int y);

	//! Returns the value of the scaled location x, y
	//! @param The x index
	//! @param The y index
	//! @return the value of scaled location x, y
	int getScaledLocationValue(int x, int y);

	//! Returns the value of the scaled width
	//! @return the value of scaled width
	int getScaledWidth();

	//! Returns the value of the scaled height
	//! @return the value of scaled height
	int getScaledHeight();

	//! Returns if the map contains a certain value
	//! @param The value what will be checked
	//! @return true if the value is present in the map, false if not
	int contains(int value);

	//! Sets the value of a scaled location in the map
	//! @param The x index
	//! @param The y index
	//! @param The new value of the scaled position x, y
	void setScaledLocationValue(int x, int y, int value);

	//! Prints the map in the console output
	void print();


	//! Adds a circle to the map
	//! @param The x index
	//! @param The y index
	//! @param The radius of the circle
	void addCircle(int x, int y, int radius);

	//! Adds the objects from the lidar to the map
	//! @param The array gotten from the lidar
	void addvirtuallidarInput(int virtuallidarInputArray[]);
	
	//! Adds a line to the grid directly
	//! @param The line to add to the grid
	void addLineToGrid(line l);

	//! Adds a polygon to the collection of lines
	//! @param The polygon to add
	void addPolygonToMapData(polygon p);

	//! Adds a polygon to the grid
	//! @param THe polygon to add
	void addPolygonToGrid(polygon p);

	//! Adds a circle to the grid with a value
	//! @param The x value of the centre of the circle
	//! @param The y value of the centre of the circle
	//! @param The radius value of the circle
	//! @param The value given to the circle
	void addValuedCircle(int xCentre, int yCentre, int radius, int value);

	//! Adds a circle to the grid with a value
	//! @param The x value of the centre of the circle
	//! @param The y value of the centre of the circle
	//! @param The radius value of the circle
	//! @param The value given to the circle
	//! @param A vector filled with floats where no circle will be drawn
	//! @return The skipped degrees
	std::vector<float> addHalfValuedCircle(int xCentre, int yCentre, int radius, int value, std::vector<float> skipInts);
	
	//! Recursive flood function to fill the targets with the replacement starting at node
	//! @param The node to start the flooding from
	//! @param The target property of the node (point)
	//! @param The replacement property of the node (point)
	void floodFillLocation(point node, int target, int replacement);

	//! Flood fill function using a queue to fill the targets with the replacement starting at node
	//! @param The node to start the flooding from
	//! @param The target property of the node (point)
	//! @param The replacement property of the node (point)
	void floodFillLocationQueue(point node, int target, int replacement);

	//! Get the grid width
	//! @return The width of the grid
	int getGridWidth();

	//! Get the grid height
	//! @return The height of the grid
	int getGridHeight();

private:
	//! The scale of the grid
	int scale = 1;

	//! The MapData with of a vector of lines
	std::vector<line> MapData;

	//! A vector of polygon objects
	std::vector<polygon> objects;

	//! An int vector with the accessablility of the grid tiles
	std::vector<std::vector<int>> access; //accessible = 0, notAccessible = 1, seen = 5

	//! Set the given point to not reachable in the access grid
	//! @param The point on the grid
	void setNotReachable(point p);
};

#endif
