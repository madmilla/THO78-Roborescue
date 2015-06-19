#include "route.h"

Route::Route()
{

}

Route::~Route()
{

}

void Route::randomRoute(int mapWidth, int mapHeight){
   int waypoints = rand() % 22 + 3;

   for(int i = 0; i < waypoints; i++){
       int randomX = rand() % mapWidth;
       int randomY = rand() % mapHeight;

       WayPoint* wayPoint = new WayPoint(randomX, randomY);

       wayPoints.push_back(wayPoint);
   }
}

int Route::getRouteSize(){
    return wayPoints.size();
}

WayPoint* Route::getWaypoint(int wayPoint){
    return wayPoints[wayPoint];
}

void Route::pushWayPoint(WayPoint* wayPoint){
    wayPoints.push_back(wayPoint);
}

void Route::clearRoute(){
    wayPoints.clear();
}
