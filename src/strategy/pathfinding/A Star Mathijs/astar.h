#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "map.hpp"
#include "Anode.h"
#include "route.h"
class aStar{
public:
	map Map;
	aStar(map Map);
	Route pathFind(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish);


};