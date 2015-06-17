#include "aStar.h"
#include <iostream>
#include <array>

aStar::aStar(Map newMap):
map{newMap}
{
}


aStar::~aStar()
{
}

std::vector<std::pair<int, int>> aStar::findPath(int startX, int startY, int endX, int endY)
{
	/*
	//maybe use sets instead of vectors
	std::vector<std::pair<int, int>> openCells;
	std::vector<std::pair<int, int>> closedCells;
	std::vector<std::pair<int, int>> tempPath;
	bool firstTime = true, somebool = false, foundReplacement = false;
	std::pair<int, int> closestCell;
	int x = startX;
	int y = startY;
	tempPath.push_back(std::pair < int, int > {x,y});
	//try to find the x and y coordinates of the endpoint and do a while iteration when it's not found
	std::cout << "2" << std::endl;

	std::vector<std::pair<int, int>>::iterator it = std::find(closedCells.begin(), closedCells.end(), std::pair<int, int>{endX, endY});
	while (it == closedCells.end())
	{
		//if it's the first iteration then don't change x and y
		if (!firstTime)
		{
			x = closestCell.first;
			y = closestCell.second;
		}
		//variable to track the shortest distance to the endpoint. reset on every iteration
		int shortestCellLength = -1;
		//check the cell above and under the current cell and do stuff with it
		int i = -1;
		for (i; i <= 1; i += 2)
		{
			if ((y + i) >= 0 && (y + i) <= map.getHeight())
			{
				it = std::find(closedCells.begin(), closedCells.end(), std::pair < int, int > {x, y + i});
				if (it == closedCells.end())
				{
					if (!map.getCell(x, y + i).isObstacle())
					{
						it = std::find(openCells.begin(), openCells.end(), std::pair<int, int>{x, y + i});
						if (it == openCells.end())
						{
							openCells.push_back(std::pair < int, int > {x, y + i});
						}
						int cellLength = (abs((x)-(endX)) - 1) + (abs((y + i) - (endY)) - 1);
						if (cellLength < shortestCellLength || shortestCellLength == -1)
						{
							shortestCellLength = cellLength;
							closestCell.first = x;
							closestCell.second = y + i;
						}
					}
					else
					{
						closedCells.push_back(std::pair < int, int > {x, y + i});
					}
				}
			}
		}
		int j = -1;
		for (j; j <= 1; j += 2)
		{
			if ((x + j) >= 0 && (x + j) <= map.getWidth())
			{
				//check if coordinate is in closedCells and if the coordinate is found skip it
				it = std::find(closedCells.begin(), closedCells.end(), std::pair < int, int > {x + j, y});
				if (it == closedCells.end())
				{
					//check to see if the cell is an obstacle. if so then put it in closedCells
					if (!map.isObstacle(x + j, y))
					{
						it = std::find(openCells.begin(), openCells.end(), std::pair<int, int>{x + j, y});
						if (it == openCells.end())
						{
							openCells.push_back(std::pair < int, int > {x + j, y});
						}
						//check length between current cell and endpoint. make current cell closestCell if length is shorter than shortestCellLength
						int cellLength = (abs((x + j) - (endX)) - 1) + (abs((y)-(endY)) - 1);
						if (cellLength < shortestCellLength || shortestCellLength == -1)
						{
							shortestCellLength = cellLength;
							closestCell.first = x + j;
							closestCell.second = y;
						}
					}
					else
					{
						closedCells.push_back(std::pair < int, int > {x + j, y});
					}
				}
			}
		}
		//push current cell to the closed list
		closedCells.push_back(std::pair < int, int > {x, y});
		//push closestcell to temppath
		tempPath.push_back(std::pair < int, int > {closestCell.first, closestCell.second});
		//find closestcell in opencells and erase it from there
		it = std::find(openCells.begin(), openCells.end(), std::pair<int, int>{closestCell.first, closestCell.second});
		
		if (it != openCells.end())
		{
			openCells.erase(it);
			//std::cout << '(' << closestCell.first << ',' << closestCell.second << ')' << std::endl;
			//std::cout << openCells.size() << std::endl;
		}
		if (shortestCellLength == -1)
		{
			if (openCells.size() > 0)
			{
				for (int place = tempPath.size() - 1; place >= 0; --place)
				{
					for (int i1 = -1; i1 <= 1; i1 += 2)
					{
						it = std::find(openCells.begin(), openCells.end(), std::pair<int, int>{tempPath[place].first, tempPath[place].second + i1});
						if (it != openCells.end())
						{
							closestCell.first = tempPath[place].first;
							closestCell.second = tempPath[place].second;
							somebool = true;
						}
					}
					if (!somebool)
					{
						for (int i2 = -1; i2 <= 1; i2 += 2)
						{
							it = std::find(openCells.begin(), openCells.end(), std::pair < int, int > {tempPath[place].first + i2, tempPath[place].second});
							if (it != openCells.end())
							{
								closestCell.first = tempPath[place].first;
								closestCell.second = tempPath[place].second;
								somebool = true;
							}
						}
					}
					//still no replacement found
					if (!somebool)
					{
						it = std::find(tempPath.begin(), tempPath.end(), std::pair < int, int > {tempPath[place].first, tempPath[place].second});
						if (it != tempPath.end())
						{
							tempPath.erase(it);
							place = tempPath.size() - 1;
						}
					}
					else
					{
						//somebool = false;
						break;
					}
				}
			}
		}
		if (shortestCellLength == -1 && !foundReplacement)
		{

		}
		//std::cout << shortestCellLength << std::endl;
		firstTime = false;
		//endpoint found
		if (closestCell.first == endX && closestCell.second == endY)
		{
			closedCells.push_back(std::pair < int, int > {closestCell.first, closestCell.second});
		}
		//update iterator for next iteration
		it = std::find(closedCells.begin(), closedCells.end(), std::pair<int, int>{endX, endY});
	}
	return tempPath;*/
	//typedef std::pair<int, int> Coordinate;
	std::vector<Coordinate> path;
	startPoint.first = startX;
	startPoint.second = startY;
	endPoint.first = endX;
	endPoint.second = endY;
	bool wentBack = false;
	path.push_back(startPoint);
	int i = 0;
	while (path.back() != endPoint)
	{
		i++;
		Coordinate currentPoint = path.back();
		std::array<Coordinate, 4> connectedPoints
		{ {
				{ currentPoint.first - 1, currentPoint.second }, //left
				{ currentPoint.first + 1, currentPoint.second }, //right
				{ currentPoint.first, currentPoint.second - 1 }, //up
				{ currentPoint.first, currentPoint.second + 1 }  //down
			} };
		std::array<int, 4> distances;
		for (auto pointIterator = 0; pointIterator < 4; ++pointIterator)
		{
			auto point = connectedPoints[pointIterator];
			if ((point.first < 0 || point.second < 0 || point.first > map.getWidth() || point.second > map.getHeight())
				|| std::find(closedCells.begin(), closedCells.end(), point) != closedCells.end()
				|| map.isObstacle(point.first, point.second))
			{
				distances[pointIterator] = -1;
			}
			else if (std::find(openCells.begin(), openCells.end(), point) != openCells.end())
			{
				closedCells.push_back(currentPoint);
				path.pop_back();
				/*std::array<Coordinate, 4> surroundingPoints
				{ {
						{ point.first - 1, point.second }, //left
						{ point.first + 1, point.second }, //right
						{ point.first, point.second - 1 }, //up
						{ point.first, point.second + 1 }  //down
				} };
				for (auto surroundingPointIterator = 0; surroundingPointIterator < 4; ++surroundingPointIterator)
				{
					auto surroundingPoint = surroundingPoints[surroundingPointIterator];
					if ( std::find(path.begin(), path.end(), surroundingPoint) != path.end())
					{
						while (path.back() != surroundingPoint)
						{
							path.pop_back();
						}
						closedCells.push_back(point);
						path.push_back(point);
						wentBack = true;
						break;
					}
				}*/
				wentBack = true;
				break;
			}
			else
			{
				distances[pointIterator] = (abs((point.first) - (endX))) + (abs((point.second) - (endY)));
				openCells.push_back(point);
			}
		}
		if (wentBack)
		{
			wentBack = false;
			continue;
		}
		int shortestDistance = -1;
		Coordinate newPoint;
		for (auto distanceIterator = 0; distanceIterator < 4; ++distanceIterator)
		{
			auto distance = distances[distanceIterator];
			if ((distance < shortestDistance && distance > -1) || shortestDistance == -1)
			{
				shortestDistance = distance;
				newPoint = connectedPoints[distanceIterator];
			}
		}
		if (shortestDistance != -1)
		{
			openCells.erase(std::find(openCells.begin(), openCells.end(), newPoint));
			closedCells.push_back(currentPoint);
			path.push_back(newPoint);
		}
		else
		{
			
			closedCells.push_back(currentPoint);
			path.pop_back();
			if (path.size() == 0)
			{
				break;
			}
		}
		
	}
	return path;
}

std::array<std::pair<Coordinate, int>, 4> aStar::getDistances(Coordinate coordinate, Map& map)
{
	std::array<std::pair<Coordinate, int>, 4> connectedPoints
	{ {
			{ { coordinate.first - 1, coordinate.second }, -1 }, //left
			{ { coordinate.first + 1, coordinate.second }, -1 }, //right
			{ { coordinate.first, coordinate.second - 1 }, -1 }, //up
			{ { coordinate.first, coordinate.second + 1 }, -1 }  //down
	} };
	for (auto pointIterator = 0; pointIterator < 4; ++pointIterator)
	{
		auto point = connectedPoints[pointIterator];
		if ((point.first.first < 0 || point.first.second < 0 || point.first.first > map.getWidth() || point.first.second > map.getHeight())
			|| std::find(closedCells.begin(), closedCells.end(), point.first) != closedCells.end()
			|| map.isObstacle(point.first.first, point.first.second))
		{
			connectedPoints[pointIterator].second = -1;
		}
		else
		{
			connectedPoints[pointIterator].second = (abs((point.first.first) - (endPoint.first))) + (abs((point.first.second) - (endPoint.second)));
			openCells.push_back(point.first);
		}
	}
	return connectedPoints;
}

Coordinate aStar::getShortestDistance(std::array<std::pair<Coordinate, int>, 4> distances)
{
	Coordinate closestCoordinate{ -1, -1 };
	int shortestDistance = -1;
	for (auto distanceIterator = 0; distanceIterator < 4; ++distanceIterator)
	{
		auto distance = distances[distanceIterator].second;
		if ((distance < shortestDistance && distance > -1) || shortestDistance == -1)
		{
			shortestDistance = distance;
			closestCoordinate = distances[distanceIterator].first;
		}
	}
	return closestCoordinate;
}