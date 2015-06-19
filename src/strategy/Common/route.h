#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include "waypoint.h"
#include <sstream>
#include <iostream>

class Route
{
public:

    Route();
    Route(std::vector<WayPoint> waypoints);
    ~Route();

    void addRoutePart(Route);
    std::vector<WayPoint> waypoints;
    int scale;
    friend std::ostream & operator<<(std::ostream & os, Route & l);
    void scaleWaypoints();

    void randomRoute(int mapWidth, int mapHeight);
    WayPoint* getWaypoint(int wayPoint);
    void pushWayPoint(WayPoint* wayPoint);
    int getRouteSize();
    void clearRoute();
	std::vector<WayPoint*> wayPoints;
private:
    // //mathijs code not prepared for this
};
#endif // ROUTE_H
