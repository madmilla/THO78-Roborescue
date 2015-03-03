#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <string>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <iomanip>

enum object{	//!max 255 objecten!
	empty,
	tree,
	water,
	quadcopter,
	atv,
	rosbee,
	stone
};

struct size { int x; int y; }; //for easy returning size of map
typedef struct size Size;

class objectMap{
public:
	objectMap(int width, int height, std::string mapName) :
		width{ width }, height{ height }, name{ "Maps/" + mapName + ".txt" } {

		int nameAmount = 1;
		while (fileExists(name)){
			name = mapName + " (" + std::to_string(nameAmount) + ").txt";
			std::cout << "file already exists, renaming to: " + name << std::endl;
			++nameAmount;
		}

		std::ofstream mapFile;
		mapFile.open(name);

		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				mapFile << "00 ";
			}
			mapFile << "\n";
		}

		mapFile.close();
	}


	void setObject(int x, int y, object thing);
	object getObject(int x, int y);
    Size getSize();
    static Size getSize(std::string fileName);


private:
	bool fileExists(std::string fileName);
	int width, height;
	std::string name;
};

#endif // MAPCREATOR_H
