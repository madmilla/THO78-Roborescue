#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

enum Color{ red= '0', white = '1', blue = '2' };

class Map
{
public:
	Map();
	void EditMap(int wight, int hight, Color r);
	void LoadMap(std::string filePath);
	void StoreMAp(std::string filepath);
	~Map();
	char twoDmap[20][20];
private:
	
};

#endif // MAP_H
