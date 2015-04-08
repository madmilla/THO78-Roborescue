#ifndef ROUTE_H
#define ROUTE_H
#include "vector"
#include "waypoint.h"

class Route
{
public:
    std::vector<WayPoint> waypoints;
    Route();
    ~Route();
};

#endif // ROUTE_H
