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

std::ostream & operator<<(std::ostream & os, Route & l){
	std::stringstream output;
	for (auto i : l.waypoints){
		output << i.x << " " << i.y << "\n";


	}

	return os << output.str();
}
void Route::scaleWaypoints(){
	for (int index = 0; index < waypoints.size(); index++){
		WayPoint point = waypoints.at(index);
		point.x = point.x*scale; point.y = point.y *scale; 
		waypoints.at(index) = point;
	}

	}
