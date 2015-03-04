#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <string>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <iomanip>

enum class object{	//!max 255 objecten!
    empty = 0,
    tree = 1,
    water = 2,
    quadcopter = 3,
    atv = 4,
    rosbee = 5,
    stone = 6,
};

static struct {object obj; std::string path;} objectss[] = {
{object::empty, "Images/free.jpg"},
{object::tree, "Images/tree.jpg"},
{object::water, "Images/water.jpg"},
{object::quadcopter, "Images/quadcopter.jpg"},
{object::atv, "Images/atv.jpg"},
{object::rosbee, "Images/rosbee.jpg"},
{object::stone, "Images/stone.jpg"},


};

struct size { int x; int y; }; //for easy returning size of map
typedef struct size Size;

class objectMap{
public:
    objectMap(){}
    objectMap(std::string fileName): name{"Maps/" + fileName + ".txt"}{
        Size mapSize = getSize(name);
        width = mapSize.x;
        height = mapSize.y;
    }

	objectMap(int width, int height, std::string mapName) :
		width{ width }, height{ height }, name{ "Maps/" + mapName + ".txt" } {

//		int nameAmount = 1;
//		while (fileExists(name)){
//            name = "Maps/" + mapName + " (" + std::to_string(nameAmount) + ").txt";
//            std::cout << "file already exists, renaming to: " + name << std::endl;
//			++nameAmount;
//		}

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
    int getObject(int x, int y);
    Size getSize();
    Size getSize(std::string fileName);


private:
	bool fileExists(std::string fileName);
	int width, height;
	std::string name;
};

#endif // MAPCREATOR_H
