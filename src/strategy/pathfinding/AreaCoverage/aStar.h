#ifndef _A_STAR_H
#define _A_STAR_H

#include <vector>
#include "map.hpp"
#include <array>
#include "route.h"
typedef std::pair<int, int> Coordinate;

class aStar
{
public:
	
	explicit aStar();
	~aStar();
	std::vector<std::pair<int, int>> findPath(int startX, int startY, int endX, int endY, map& theMap);
	std::array<std::pair<Coordinate, int>, 4> getDistances(Coordinate coordinate, map& theMap);
	Coordinate getShortestDistance(std::array<std::pair<Coordinate, int>, 4> distances);
	Route getRoute(std::vector<std::pair<int, int>>);
private:
	std::vector<Coordinate> closedCells;
	std::vector<Coordinate> openCells;
	Coordinate endPoint;
	Coordinate startPoint;
	const int width = 60;
	const int height = 60;
	//Map map;
};
#endif