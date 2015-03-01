#include "map.h"
#include <iostream>
#include <fstream>

Map::Map()
{
    for(int x = 0; x < MAP_WIDTH; x++){
        for (int y = 0; y < MAP_HEIGHT; y++){
            objectMatrix[x][y] = 0;
        }
    }
}

Map::~Map()
{

}

int Map::get(int x, int y)
{
    return objectMatrix[x][y];
}

void Map::set(int x, int y, int value)
{
    objectMatrix[x][y] = value;
}

Map * Map::loadFromFile(const char * filename)
{

    Map * map = new Map();
    std::ifstream is(filename);
    char c;
    int x = 0, y = 0;
    while(is.get(c)){
        if(c == CHAR_FREE){
            map->set(x, y, 0);
        }
        else if(c == CHAR_BLOCK){
            map->set(x, y, 1);
        }
        else if(c == CHAR_QUAD){
            map->set(x, y, 2);
        }
        else{
            x -= 1;
        }
        x+=1;
        if(x >= MAP_WIDTH){
            y += 1;
            x = 0;
        }
        if(y >= MAP_HEIGHT){
            break;
        }
    }
    is.close();
    return map;
}

void Map::saveToFile(const char * filename)
{
    std::ofstream os(filename, std::ofstream::out);
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
           if(get(x, y) == FREE){
               os << CHAR_FREE;
           }
           else if(get(x, y) == BLOCK){
               os << CHAR_BLOCK;
           }
           else if(get(x, y) == QUAD){
               os << CHAR_QUAD;
           }
        }
        os << '\n';
    }
    os.close();
}
