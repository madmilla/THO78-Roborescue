#ifndef ROUTE_H
#define ROUTE_H
#include <vector>
#include "waypoint.h"
#include <sstream>
#include <iostream>

class Route
{
public:
	void addRoutePart(Route);
    std::vector<WayPoint> waypoints;
    Route();
	int scale;
	Route(std::vector<WayPoint> waypoints);
    ~Route();
	friend std::ostream & operator<<(std::ostream & os, Route & l);
	void scaleWaypoints();

    void randomRoute(int mapWidth, int mapHeight);
    WayPoint* getWaypoint(int wayPoint);
    void pushWayPoint(WayPoint* wayPoint);
    int getRouteSize();
    void clearRoute();

private:
    //std::vector<WayPoint*> wayPoints; //mathijs code not prepared for this
};

#endif // ROUTE_H
