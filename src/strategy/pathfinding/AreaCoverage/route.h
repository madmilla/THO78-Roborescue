#ifndef ROUTE_H
#define ROUTE_H
#include "vector"
#include "waypoint.h"
#include <sstream>
#include <iostream>

class Route
{
public:
    std::vector<WayPoint> waypoints;
    Route();
	int scale;
	Route(std::vector<WayPoint> waypoints);
    ~Route();
	friend std::ostream & operator<<(std::ostream & os, Route & l);
	void scaleWaypoints();
};

#endif // ROUTE_H
