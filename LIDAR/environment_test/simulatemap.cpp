#include "simulatemap.h"
#include <iostream>
#include <fstream>
#include "PointCloud.h"
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <sstream>

SimulateMap::SimulateMap(Map *map):
    map(map)
{

}

Pointcloud SimulateMap::simulate(){
    int y = 0;
    Pointcloud pC;
    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            if(fory[x] == 1){
                int objectX = (x-lidarX);
                int objectY = (y-lidarY) * -1;
                pC.setPoint(objectX,objectY);
                std::cout << "Object found at location: (x:" << objectX << ",y:" << objectY << ")" << std::endl;
            }
            x++;
        }
        y++;
    }
    return pC;
}

SimulateMap::~SimulateMap()
{

}

void SimulateMap::setScanPoint(int y, int x){
    lidarY = y;
    lidarX = x;
}

