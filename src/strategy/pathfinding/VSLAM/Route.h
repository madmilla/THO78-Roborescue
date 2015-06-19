#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <iostream>
//#include "Container.h"

class Route
{
public:
    Route();
    ~Route();
    void setRouteTile(int x , int y);
	int * getNewTile();
	int getSize();
	void clearRoute();
    std::vector <std::pair<int, int>> newRoute;
};

#endif // ROUTE_H
