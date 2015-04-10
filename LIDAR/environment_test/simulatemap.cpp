#include "simulatemap.h"
#include <iostream>

SimulateMap::SimulateMap(Map *map):
    map(map)
{

}

void SimulateMap::simulate(){
    int y = 0;
    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            if(fory[x] == 1){
                int objectX = (x-lidarX);
                int objectY = (y-lidarY) * -1;
                std::cout << "Object found at location: (x:" << objectX << ",y:" << objectY << ")" << std::endl;
            }
            x++;
        }
        y++;
    }
}

SimulateMap::~SimulateMap()
{

}

void SimulateMap::setScanPoint(int y, int x){
    lidarY = y;
    lidarX = x;
}

