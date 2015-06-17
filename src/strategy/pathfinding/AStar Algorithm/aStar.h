#ifndef _A_STAR_H
#define _A_STAR_H

#include <vector>
#include "Map.h"
#include <array>

typedef std::pair<int, int> Coordinate;

class aStar
{
public:
	
	explicit aStar(Map newMap);
	~aStar();
	std::vector<std::pair<int, int>> findPath(int startX, int startY, int endX, int endY);
	std::array<std::pair<Coordinate, int>, 4> getDistances(Coordinate coordinate, Map& map);

private:
	std::vector<Coordinate> closedCells;
	std::vector<Coordinate> openCells;
	Coordinate endPoint;
	Coordinate startPoint;
	Map map;
};
#endif