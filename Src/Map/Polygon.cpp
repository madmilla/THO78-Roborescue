#include "Polygon.h"


polygon::polygon(std::vector<point> points):
points{points}
{
}


polygon::~polygon()
{
}

std::vector<point> polygon::getPoints(){
	return points;
}