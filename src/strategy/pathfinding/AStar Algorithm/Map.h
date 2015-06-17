#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include "Cell.h"
class Map
{
public:
	Map();
	Map(std::vector<Cell> map, int width, int height);
	~Map();

	void 
		setMap(std::vector<Cell> map, int width, int height),
		setDimensions(int newWidth, int newHeight),
		addCell(bool isObstacle),
		addCell(int x, int y, bool isObstacle),
		setObstacle(int x, int y, bool isObstacle);
	bool 
		isObstacle(int x, int y);


	Cell getCell(int x, int y);
	int getWidth();
	int getHeight();

private:
	std::vector<Cell> mapPoints;
	int width, height;
};
#endif