#include "map.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

const int Map::ALLOWED_VALUES[] = {FREE, BLOCK, QUAD};

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
    if(x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT ){
        throw std::invalid_argument("Index out of bounce");
    }
    return objectMatrix[x][y];
}

void Map::set(int x, int y, int value)
{
    if(x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT ){
        throw std::invalid_argument("Index out of bounce");
    }
    bool found = false;
    for(unsigned int i = 0; i < (sizeof(ALLOWED_VALUES) / sizeof(ALLOWED_VALUES[0])); i++){
        if(value == ALLOWED_VALUES[i]){
            found = true;
        }
    }
    if(!found){
        throw std::invalid_argument("Incorrect value given");
    }
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
