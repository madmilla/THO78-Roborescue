#include "route.h"
#include <sstream>
Route::Route()
{

}

Route::~Route()
{

}
std::ostream & operator<<(std::ostream & os, const Route & l){
	std::stringstream output;
	for (auto i : l.waypoints){
		output << i.x << " " << i.y << "\n";
		

		}
	
	return os << output.str();
}

