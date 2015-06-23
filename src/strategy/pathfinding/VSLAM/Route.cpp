#include "Route.h"

Route::Route()
{
	newRoute.reserve(1);
}

Route::~Route()
{

}

void Route::setRouteTile(int x, int y){
    std::pair <int, int> temp;
    temp.first = x;
    temp.second = y;
    newRoute.push_back(temp);
}

int * Route::getNewTile(){
	static int tileLocation[1];
	for (auto &i : newRoute){
		tileLocation[0] = i.first;
		tileLocation[1] = i.second;
		newRoute.erase(newRoute.begin());
		break;
	}
	return tileLocation;
}

int Route::getSize(){
	return newRoute.size();
}

void Route::clearRoute(){
	newRoute.erase(newRoute.begin(), (newRoute.begin() + newRoute.size()));
}