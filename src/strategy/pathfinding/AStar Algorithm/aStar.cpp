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
	startPoint = Coordinate{ startX, startY };
	endPoint = Coordinate{ endX, endY };
	std::vector<Coordinate> path;
	path.push_back(startPoint);
	
	while (path.back() != endPoint)
	{
		bool wentBack = false;
		auto currentPoint = path.back();
		closedCells.push_back(currentPoint);
		std::array<std::pair<Coordinate, int>, 4> distances = getDistances(currentPoint, map);
		for (auto& distance : distances)
		{
			if (std::find(openCells.begin(), openCells.end(), distance.first) != openCells.end())
			{
				closedCells.erase(std::find(closedCells.begin(), closedCells.end(), currentPoint));
				std::array<std::pair<Coordinate, int>, 4> openCellDistances = getDistances(distance.first, map);
				int pathDistanceToEnd = (abs((currentPoint.first) - (endPoint.first))) + (abs((currentPoint.second) - (endPoint.second)));
				int openCellDistanceToEnd = (abs((distance.first.first) - (endPoint.first))) + (abs((distance.first.second) - (endPoint.second)));
				if (openCellDistanceToEnd < pathDistanceToEnd)
				{
					path.pop_back();
					for (auto& openCellDistance : openCellDistances)
					{
						if (std::find(path.begin(), path.end(), openCellDistance.first) != path.end())
						{
							while (path.back() != openCellDistance.first)
							{
								path.pop_back();
							}
							path.push_back(distance.first);
							openCells.erase(std::find(openCells.begin(), openCells.end(), distance.first));
							wentBack = true;
							break;
						}
					}
				}
				else
				{
					openCells.erase(std::find(openCells.begin(), openCells.end(), distance.first));
					closedCells.push_back(distance.first);
				}
				break;
			}
		}
		if (!wentBack)
		{
			Coordinate shortestCell = getShortestDistance(distances);
			if (shortestCell == Coordinate{-1,-1})
			{
				for (auto& distance : distances)
				{
					if (std::find(closedCells.begin(),closedCells.end(), distance.first) == closedCells.end())
					{
						closedCells.push_back(distance.first);
					}
				}
				path.pop_back();
				std::array<std::pair<Coordinate, int>, 4> previousCellDistances = getDistances(path.back(), map);
				for (auto& previousCellDistance : previousCellDistances)
				{
					auto iterator = std::find(openCells.begin(), openCells.end(), previousCellDistance.first);
					if (iterator != openCells.end())
					{
						openCells.erase(iterator);
					}
				}
			}
			else
			{
				path.push_back(shortestCell);
				for (auto& distance : distances)
				{
					if (distance.first != shortestCell)
					{
						if (distance.second == -1)
						{
							if (std::find(closedCells.begin(), closedCells.end(), distance.first) == closedCells.end())
							{
								closedCells.push_back(distance.first);
							}
						}
						else
						{
							if (std::find(openCells.begin(), openCells.end(), distance.first) == openCells.end())
							{
								openCells.push_back(distance.first);
							}
						}
					}
				}
			}
		}
	}
	return path;














	/*std::vector<Coordinate> path;
	startPoint.first = startX;
	startPoint.second = startY;
	endPoint.first = endX;
	endPoint.second = endY;
	bool wentBack = false;
	path.push_back(startPoint);
	closedCells.push_back(startPoint);
	int i = 0;
	while (path.back() != endPoint)
	{
		i++;
		bool wentBack = false;
		Coordinate currentPoint = path.back();
		std::array<std::pair<Coordinate, int>, 4> distances = getDistances(currentPoint, map);
		Coordinate closest = getShortestDistance(distances);
		//std::cout << currentPoint.first << ',' << currentPoint.second << std::endl;
		if (closest == Coordinate{-1,-1})
		{
			path.pop_back();
			closedCells.push_back(closest);
			continue;
		}
		for (auto& distance : distances)
		{
			if (std::find(openCells.begin(), openCells.end(), distance.first) != openCells.end())
			{
				closedCells.erase(std::find(closedCells.begin(), closedCells.end(), currentPoint));
				path.erase(std::find(path.begin(), path.end(), currentPoint));
				std::array<std::pair<Coordinate, int>, 4> errorDistances = getDistances(distance.first, map);
				for (auto& distance2 : distances)
				{
					auto iterator = std::find(openCells.begin(), openCells.end(), distance2.first);
					if (iterator != openCells.end())
					{
						openCells.erase(iterator);
					}
				}
				for (auto& distance2 : errorDistances)
				{
					if(std::find(path.begin(), path.end(), distance2.first) != path.end())
					{
						std::array<std::pair<Coordinate, int>, 4> newPointDistances = getDistances(distance2.first, map);
						for (auto& distance3 : newPointDistances)
						{
							auto iterator = std::find(openCells.begin(), openCells.end(), distance3.first);
							if (iterator != openCells.end())
							{
								openCells.erase(iterator);
							}
						}
						while (path.back() != distance2.first)
						{
							path.pop_back();
							wentBack = true;
						}
					}
					if (wentBack)
					{
						break;
					}
				}
				break;
			}
			else if (distance.second > -1)
			{
				openCells.push_back(distance.first);
			}
			else
			{
				if (std::find(closedCells.begin(), closedCells.end(), distance.first) == closedCells.end())
				{
					closedCells.push_back(distance.first);
				}
			}
		}
		if (wentBack)
		{
			//wentBack = false;
			continue;
		}
		openCells.erase(std::find(openCells.begin(), openCells.end(), closest));
		path.push_back(closest);
		closedCells.push_back(closest);
	}
	return path;*/
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
	for (auto& point : connectedPoints)
	{
		if ((point.first.first < 0 || point.first.second < 0 || point.first.first > map.getWidth() || point.first.second > map.getHeight())
			|| std::find(closedCells.begin(), closedCells.end(), point.first) != closedCells.end()
			|| map.isObstacle(point.first.first, point.first.second))
		{
			point.second = -1;
		}
		else
		{
			point.second = (abs((point.first.first) - (endPoint.first))) + (abs((point.first.second) - (endPoint.second)));
		}
	}
	return connectedPoints;
}

Coordinate aStar::getShortestDistance(std::array<std::pair<Coordinate, int>, 4> distances)
{
	Coordinate closestCoordinate{ -1, -1 };
	int shortestDistance = 1000;
	for (auto& point : distances)
	{
		if(point.second < shortestDistance && point.second > -1)
		{
			closestCoordinate = point.first;
			shortestDistance = point.second;
		}
	}
	return closestCoordinate;
}
/*closedCells.push_back(distance.first);
path.pop_back();
for (auto& distance2 : distances)
{
	auto iterator = std::find(openCells.begin(), openCells.end(), distance2.first);
	if (iterator != openCells.end() && distance2 != distance)
	{
		openCells.erase(iterator);
	}
}
wentBack = true;
break;*/