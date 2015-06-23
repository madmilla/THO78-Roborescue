#pragma once
#include<vector>
#include "point.hpp"

class polygon
{
public:
	std::vector<point> points;
	polygon(std::vector<point>);
	~polygon();
};

