#include <iostream>
#include <fstream>
#include "Map.h"
#include "aStar.h"

int main(int argc, char * argv[])
{
	Map map;
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
	}
	system("pause");
	return 0;
}