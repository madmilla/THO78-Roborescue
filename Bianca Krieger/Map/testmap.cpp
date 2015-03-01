#include "map.h"
#include <iostream>

int main(int argc, char *argv[]){
    Map *map = new Map();
    map->set(8, 8, 2);
    if(map->get(8, 8) != 2){
        std::cout << "FAILURE :(";
        return -1;
    }
    map->saveToFile("/tmp/testMapGridFileDingen");
    delete map;

    Map *mappie = Map::loadFromFile("/tmp/testMapGridFileDingen");
    if(map->get(8, 8) != 2){
        std::cout << "FAILURE :(";
        return -1;
    }

    std::cout << "SUCCESSSSS!!";
    return 0;
}
