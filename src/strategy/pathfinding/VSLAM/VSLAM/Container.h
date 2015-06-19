#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <iostream>
#include "Route.h"

class Container
{
public:
	static void setRouteTile(int x, int y){
		route.setRouteTile(x, y);
	}
	static Route route;
};

#endif  //CONTAINER_H
