#include <string>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <iomanip>

enum object{	//!max 255 objecten!
	empty,
	wood,
	water
};

class objectMap{
public:
	objectMap(int width, int height, std::string mapName) : 
		width{ width }, height{ height }, name{ "Maps/" + mapName + ".txt" } {
		
		int nameAmount = 1;
		while(fileExists(name)){
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

private:
	bool fileExists(std::string fileName);
	int width, height;
	std::string name;
};

bool objectMap::fileExists(std::string fileName){
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0); //check if file exists
}

void objectMap::setObject(int x, int y, object thing){
	std::string	buffer;
	std::fstream mapFile;
	mapFile.open(name);
	for (int i = 1; i < y; i++){			//Get to the y position 
		std::getline(mapFile, buffer);		
	}
	for (int i = 1; i < x; i++){			//Get to the x position
		mapFile >> buffer;
		mapFile.seekp(mapFile.tellg() += 1);
	}
	mapFile << std::hex << std::setw(2) << std::setfill('0') << thing << " "; //Change the object
	mapFile.close();
}

object objectMap::getObject(int x, int y){
	std::string	buffer;
	std::ifstream mapFile;
	mapFile.open(name);
	for (int i = 1; i < y; i++){			//Get to the y position 
		std::getline(mapFile, buffer);
	}
	for (int i = 1; i <= x; i++){			//Get to the x position
		mapFile >> buffer;
	}

	return (object)std::stoi(buffer);
}

int main(){
	objectMap mapje(20, 20, std::string("mapje"));

	mapje.setObject(1, 1, wood);
	mapje.setObject(10, 10, wood);
	mapje.setObject(20, 20, water);

	std::cout << mapje.getObject(20, 20);

	int tmp;
	std::cin >> tmp;
	return 0;
}