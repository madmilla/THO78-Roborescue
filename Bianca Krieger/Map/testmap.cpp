#include "map.h"
#include <iostream>

int main(int argc, char *argv[]){
    Map *map = new Map();
    map->set(8, 8, 2);
    if(map->get(8, 8) != 2){
        std::cout << "FAILURE GET :(";
        return -1;
    }
    map->saveToFile("/tmp/testMapGridFileDingen");
    delete map;

    Map *mappie = Map::loadFromFile("/tmp/testMapGridFileDingen");
    if(map->get(8, 8) != 2){
        std::cout << "FAILURE LOAD :(";
        return -1;
    }

	try{
		map->get(20, 2);
        std::cout << "FAILURE EXCEPTION :(";
        return -1;
    }catch(int e){
		
	}

	try{
		map->set(2, 2, 3);
        std::cout << "FAILURE EXCEPTION 2 :(";
        return -1;
    }catch(int e){
		
	}

    std::cout << "SUCCESSSSS!!";
    return 0;
}
