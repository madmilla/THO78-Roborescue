#include "mapCreator.h"

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
    mapFile << std::hex << std::setw(2) << std::setfill('0') << (int)thing << " "; //Change the object
	mapFile.close();
}

int objectMap::getObject(int x, int y){
	std::string	buffer;
	std::ifstream mapFile;
	mapFile.open(name);
	for (int i = 1; i < y; i++){			//Get to the y position 
		std::getline(mapFile, buffer);
	}
	for (int i = 1; i <= x; i++){			//Get to the x position
		mapFile >> buffer;
	}
    if(buffer.empty()){
        std::cout << "EMPTY" << x << "  " << y << std::endl;
        return -1;
    }
    return std::stoi(buffer);
}

Size objectMap::getSize(){
    size map;
    map.x = width;
    map.y = height;
    return map;
}

 Size objectMap::getSize(std::string fileName){
    size mapSize;
    std::ifstream mapFile;
    mapFile.open(fileName);

    std::string tmp;
    std::getline(mapFile, tmp);
    mapSize.x = (int)tmp.length()/3; //object size in file == 2 + 1 space
    int ySize = 0;
    while(!mapFile.eof()){
        ++ySize;
        std::getline(mapFile, tmp);
    }
    mapSize.y = ySize;
    return mapSize;
}

//int main(){
//	objectMap mapje(20, 20, std::string("mapje"));
//
//	mapje.setObject(1, 1, tree);
//	mapje.setObject(10, 10, tree);
//	mapje.setObject(20, 20, water);
//
//	std::cout << mapje.getObject(20, 20);
//
//	int tmp;
//	std::cin >> tmp;
//	return 0;
//}
