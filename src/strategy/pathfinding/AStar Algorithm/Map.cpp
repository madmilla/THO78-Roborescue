#include "Map.h"


Map::Map()
{
}

Map::Map(std::vector<Cell> map, int width, int height):
mapPoints{map},
width{width},
height{height}
{
}

Map::~Map()
{
	mapPoints.erase(mapPoints.begin(), mapPoints.end());
}

void Map::setMap(std::vector<Cell> map, int newWidth, int newHeight)
{
	mapPoints = map;
	width = newWidth;
	height = newHeight;
}

void Map::setDimensions(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
}

void Map::addCell(bool isObstacle)
{
	Cell newCell(isObstacle);
	mapPoints.push_back(newCell);
}

void Map::addCell(int x, int y, bool isObstacle)
{
	Cell newCell(isObstacle);
	mapPoints[y * width + x] = newCell;
}

bool Map::isObstacle(int x, int y)
{
	return mapPoints[y * width + x].isObstacle();
}

int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}

Cell Map::getCell(int x, int y)
{
	return mapPoints[y * width + x];
}

void Map::setObstacle(int x, int y, bool isObstacle)
{
	mapPoints[y * width + x].setObstacle(isObstacle);
}