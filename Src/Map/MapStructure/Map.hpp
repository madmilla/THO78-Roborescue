#ifndef Map_H
#define Map_H
#include <math.h>
#include <cmath>
#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <vector>
#include "Polygon.h"
//#include "QuadCopter.h"
//#include "virtualRosbee.h"
//#include "virtualATV.h"
#include "aStar.h"
#include "MapImplementation.cpp"
#include <cstdlib>
#include <climits>
#include <algorithm>


class Map : public mapImplementation
{
public:
	int getScaledHeuristicLocationValue(int x, int y);
	int getScale();
	Map();
	Map(line & l);
	Map(std::vector<line> & l);
	~Map();

	// Debug function to print Map (implement?)
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

	//!
	void setScale(int x);
	
	//! 
	bool isScaledAccessible(int x, int y);

	//add object to position x,y
	void addObject(polygon p);

	//fill object (circle or polygon) so that middle is not accessible
	void fillObjects(std::vector<int> object);

	//when pathfinding is done, make all cells unseen again. seen = false;	
	void makeUnseen();

	//when pathfinding is done, make all cells unseen again. seen = false;	
	void setLocationValue(unsigned int x, int y, int value);

	//translate lines to points in 2d vector
	//! Translates a line vector to a grid Map
	//! Line data from the parameter will be translated to
	//! point data to the return.
	void translateToPoints();

	int getLocationValue(unsigned int x, unsigned int y);

	int getScaledLocationValue(int x, int y);
	int getScaledWidth();
	int getScaledHeight();
	int contains(int value);
	void setScaledLocationValue(int x, int y, int value);
	void print();

	void addCircle(int x, int y, int radius);

	// Vehicle Positions Getters and Setters
	//! \returns the virtualrosbee position
	//virtualRosbee* getRosbeePosition() { return rosbeePosition; }
	//! \returns the atv position
	//virtualATV* getATVPosition() { return ATVPosition; }
	//! \returns the quadcopter position
	//QuadCopter* getQuadCopterPositon() { return quadcopterPosition; }

	//! Sets the virtualrosbee position
	//void setRosbeePosition(virtualRosbee* newPosition) { this->rosbeePosition = newPosition; }
	//! Sets the atv position
	//void setATVPosition(ATV* newPosition) { this->ATVPosition = newPosition; }
	//! Sets the quadcopter position
	//void setQuadCopterPositon(QuadCopter* newPosition) { this->quadcopterPosition = newPosition; }
	void addvirtuallidarInput(int virtuallidarInputArray[]);
	
	//! add a line to the grid directly
	//! @param The line to add to the grid
	void addLineToGrid(line l);

	//! add a polygon to the collection of lines
	//! @param The polygon to add
	void addPolygonToMapData(polygon p);

	//! add a polygon to the grid
	//! @param THe polygon to add
	void addPolygonToGrid(polygon p);
	void addValuedCircle(int xCentre, int yCentre, int radius, int value);
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
	int scale=1;
	std::vector<line> MapData;
	std::vector<polygon> objects;
	std::vector<std::vector<int>> access; //accessible = 0, notAccessible = 1, seen = 5

	//! Set the given point to not reachable in the access grid
	//! @param The point on the grid
	void setNotReachable(point p);

	//virtualRosbee* rosbeePosition;
	//virtualATV* ATVPosition;
	//QuadCopter* quadcopterPosition;
};

#endif
