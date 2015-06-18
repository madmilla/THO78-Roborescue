#ifndef ROUTE_H
#define ROUTE_H
#include "vector"
#include "waypoint.h"

class Route
{
public:
    Route();
    ~Route();

    void randomRoute(int mapWidth, int mapHeight);
    WayPoint* getWaypoint(int wayPoint);
    void pushWayPoint(WayPoint* wayPoint);
    int getRouteSize();
    void clearRoute();

private:
    std::vector<WayPoint*> wayPoints;
};

#endif // ROUTE_H
