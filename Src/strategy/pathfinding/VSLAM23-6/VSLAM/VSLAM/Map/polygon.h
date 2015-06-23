#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include <point.hpp>

class polygon
{
public:
	std::vector<point> points;
	polygon(std::vector<point>);
	~polygon();
};

#endif
