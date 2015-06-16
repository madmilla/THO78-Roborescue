#ifndef ROUTE_H
#define ROUTE_H
#include "vector"
#include "waypoint.h"
#include <iostream>
class Route
{
public:
    std::vector<WayPoint> waypoints;
    Route();
    ~Route();
	friend std::ostream & operator<<(std::ostream & os, const Route & l);
};

#endif // ROUTE_H
