#pragma once

#include "point.hpp"
#include "line.hpp"
#include <iostream>
#include <vector>

class map
{
public:
	map();
	map(line & l);
	map(std::vector<line> & l);
	~map();

	// Debug function to print map (implement?)
	friend std::ostream & operator<<(std::ostream & os, const map & m);

	//! Checks if the the map has the line parameter
	//! @param The line to be checked for presence in the map
	//! @return The result of the search. True if found, otherwise false.
	bool hasLine(line & l);

	//! Checks if the the map has all the lines from the parameter
	//! @param A vector of lines to be checked for presence in the map
	//! @return The result of the search. True if all are found, otherwise false.
	bool hasLine(std::vector<line> & l);

	//! Get all the lines that intersect the point parameter
	//! @param The point to be checked for intersecting lines
	//! @return A vector of lines that intersect the point parameter.
	std::vector<line> getPointLines(point & p);

	//! Append a line to the map
	//! @param A line to be appended to the map data
	void appendLine(line & l);

	//! Append a vector of lines to the map
	//! @param A vector of lines to be appended to the map data
	void appendLine(std::vector<line> & l);

	//! Remove a line from the map data
	//! @param A line to be removed from the the map data
	//! @return Return if a line equal to the parameter is still present after removal
	bool removeLine(line & l);

	//! Removes a vector of lines from the map data
	//! @param A vector of lines to be removed from the the map data
	//! @return Return if all the lines equal to the parameter are present after removal
	bool removeLine(std::vector<line> & l);

	//! Compares the current map to the map parameter
	//! @param The map to compare with
	//! @return The result of the comparison. True if equal, otherwise false.
	bool equals(const map & m);

	//! Get a part of the map that lies within the bounds of the parameter
	//! @param An X-coordinate of the top left corner of the rectangle
	//! @param A Y-coordinate of the top left corner of the rectangle
	//! @param The width of the rectangle
	//! @param The height of the rectangle
	//! @return A map within the region given as parameters
	map getRegion(int x, int y, unsigned int width, unsigned int height);

	//! Get a part of the map that lies within the bounds of the parameter
	//! @param The top left corner of the rectangle
	//! @param The width of the rectangle
	//! @param The height of the rectangle
	//! @return A map within the region given as parameters
	map getRegion(point & p, unsigned int width, unsigned int height);

	//2D vector to check if points are accessible and seen
	std::vector<std::vector<int>> access; //accessible = 0, notAccessible = 1, seen = 5

	//check if x,y is accessible
	//eventueel met boost isAccessible
	bool isAccessible(int x, int y);

	//add object to position x,y
	void addObject(std::vector<int> objects, int x, int y);

	//fill object (circle or polygon) so that middle is not accessible
	void fillObjects(std::vector<int> object);

	//when pathfinding is done, make all cells unseen again. seen = false;	
	void makeUnseen();

	//when pathfinding is done, make all cells unseen again. seen = false;	
	void setLocationValue(int x, int y,int value);

	//translate lines to points in 2d vector
	void translateToPoints();

	int getLocationValue(int x, int y);

	int contains(int value);
private:
	std::vector<line> mapData;
};
