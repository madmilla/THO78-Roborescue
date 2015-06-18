#include "aStar.h"
#include <iostream>
#include <array>
#include "waypoint.h"
aStar::aStar()
{
}


aStar::~aStar()
{
}

Route aStar::getRoute(std::vector<std::pair<int, int>> input){
	std::cout << input.size();
	Route output;
	for (Coordinate c : input){
		output.waypoints.push_back(WayPoint(c.first, c.second));

	}
	return output;



}


std::vector<std::pair<int, int>> aStar::findPath(int startX, int startY, int endX, int endY, map& theMap)
{
	theMap.print();
	getchar();
	std::vector<Coordinate> path;
	if (startX < 0 || startY < 0 || startX > width || startY > height || endX < 0 || endY < 0 || endX > width || endY > height)
	{
		return path;
	}
	startPoint = Coordinate{ startX, startY };
	endPoint = Coordinate{ endX, endY };
	
	path.push_back(startPoint);
	
	while (path.back() != endPoint)
	{
		bool wentBack = false;
		auto currentPoint = path.back();
		closedCells.push_back(currentPoint);
		std::array<std::pair<Coordinate, int>, 4> distances = getDistances(currentPoint, theMap);
		for (auto& distance : distances)
		{
			if (std::find(openCells.begin(), openCells.end(), distance.first) != openCells.end())
			{
				closedCells.erase(std::find(closedCells.begin(), closedCells.end(), currentPoint));
				std::array<std::pair<Coordinate, int>, 4> openCellDistances = getDistances(distance.first, theMap);
				int pathDistanceToEnd = 0;
				int openCellDistanceToEnd = 0;
				path.pop_back();
				for (auto& openCellDistance : openCellDistances)
				{
					auto iterator = std::find(path.begin(), path.end(), openCellDistance.first);
					if (iterator != path.end())
					{
						auto itCounter = path.size() - 1;
						while (path[itCounter] != openCellDistance.first)
						{
							pathDistanceToEnd++;
							itCounter--;
						}
						path.push_back(currentPoint);
						break;
					}
				}
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
				if (path.size() == 0)
				{
					break;
				}
				std::array<std::pair<Coordinate, int>, 4> previousCellDistances = getDistances(path.back(), theMap);
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
}

std::array<std::pair<Coordinate, int>, 4> aStar::getDistances(Coordinate coordinate, map& theMap)
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
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//change the check for width and height with function when those are made for the map
		if ((point.first.first < 0 || point.first.second < 0 || point.first.first > width/*theMap.getScaledWidth()*/ || point.first.second > height/*theMap.getScaledHeight()*/)
			|| std::find(closedCells.begin(), closedCells.end(), point.first) != closedCells.end()
			|| !theMap.isAccessible(point.first.first, point.first.second))
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