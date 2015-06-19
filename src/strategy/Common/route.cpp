#include "route.h"

Route::Route()
{

}
Route::Route(std::vector<WayPoint> waypoints){
	this->waypoints = waypoints;


}
Route::~Route()
{

}
void Route::addRoutePart(Route in) { waypoints.insert(waypoints.end(), in.waypoints.begin(), in.waypoints.end()); }
std::ostream & operator<<(std::ostream & os, Route & l){
	std::stringstream output;
	for (auto i : l.waypoints){
		output << i.x << " " << i.y << " ";
    }
	return os << output.str();
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


void Route::scaleWaypoints(){
	for (int index = 0; index < waypoints.size(); index++){
		WayPoint point = waypoints.at(index);
		point.x = point.x*scale; point.y = point.y *scale; 
		waypoints.at(index) = point;
	}

}
