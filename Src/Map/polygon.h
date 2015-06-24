#ifndef POLYGON_H
#define POLYGON_H
#include<vector>
#include "point.hpp"

class polygon
{
public:
	//! Constructor of polygon
	//! The polygons use their starting point as starting point and
	//! as ending point.
	polygon(std::vector<point>);

	//! Destructor
	~polygon();

	//! Get the polygon shape
	//! @param Get all the points of the shape
	std::vector<point> getPoints();

private:
	std::vector<point> points;
};

#endif
