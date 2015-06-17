#include <iostream>
#include <fstream>
#include "map.hpp"
#include "aStar.h"

int main(int argc, char * argv[])
{

	map Map;


	// randomly select start and finish locations
	int xA = 1;
	int yA = 1;
	int xB = 10;
	int yB = 10;

	//std::cout << "Map Size (X,Y): " << n << "," << m << std::endl;
	std::cout << "Start: " << xA << "," << yA << std::endl;
	std::cout << "Finish: " << xB << "," << yB << std::endl;
	aStar star = aStar();
	std::vector<Coordinate> route = star.findPath(xA, yA, xB, yB, Map);

	for (auto& cell : route)
	{
		Map.setLocationValue(cell.first, cell.second, 3);
	}
	for (int y = 0; y < 70; y++){
		for (int x = 0; x < 70; x++){
			std::cout << Map.getLocationValue(x, y);
		}
		std::cout << "\n";
	}
	std::cout << "Route:" << std::endl;
	//std::cout << route << std::endl << std::endl;
	for (auto& e : route)
	{
		std::cout << '(' << e.first << ',' << e.second << ')' << std::endl;
	}




	/*Map map;
	std::fstream pFile("map.txt");
	char c;
	int tempWidth = 0;
	auto width = 0,height = 1;
	while (!pFile.eof())
	{
		pFile.get(c);
		switch (c){
		case 'X':
			map.addCell(true);
			++tempWidth;
			break;
		case'_':
			map.addCell(false);
			++tempWidth;
			break;
		case '\n':
			if (tempWidth > width)
			{
				width = tempWidth;
			}
			tempWidth = 0;
			++height;
			break;
		default:
			break;
		}
	}
	map.setDimensions(width, height);
	aStar algorithm{ map };
	std::vector<std::pair<int, int>> path = algorithm.findPath(2, 2, 10, 9);

	for (auto& e : path)
	{
		std::cout << '(' << e.first << ',' << e.second << ')' << std::endl;
	}*/
	system("pause");
	return 0;
}