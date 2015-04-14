#include "simulatemap.h"
#include <iostream>
#include <fstream>
#include "PointCloud.h"
#include <sstream>
#include "values.h"

SimulateMap::SimulateMap(Map *map):
    map(map)
{

}

std::string SimulateMap::simulate(){
    int y = 0;
    std::ostringstream oss;
    std::string s = "";

    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            if(fory[x] == Values::OBSTACLE){
                int objectX = (x-lidarX);
                int objectY = (y-lidarY) * -1;
                pC.setPoint(objectX,objectY);
                oss << "Lidar found object at: (X:" << objectX << ",Y:" << objectY <<")\n";
            }
            x++;
        }
        y++;
    }

    if(checkpoints.size() > 0){
        for(int i = 0; i < checkpoints.size(); i++){
            y = 0;
            for(std::vector<int> fory : map->getMapContent()){
                setScanPoint(checkpoints[i].getY(), checkpoints[i].getX());
                int x = 0;
                for(int forx : fory){
                    if(fory[x] == Values::OBSTACLE){
                        int objectX = (x-lidarX);
                        int objectY = (y-lidarY)* -1;
                        pC.setPoint(objectX,objectY);
                        oss << "Checkpoint " << (i+1) <<" found object at: (X:" << objectX << ",Y:" << objectY <<")\n";
                    }
                    x++;
                }
                y++;
            }
        }
    }
    s += oss.str();
    return s;
}

Pointcloud SimulateMap::getPointCloud(){
    return pC;
}

void SimulateMap::addCheckPoint(int x, int y){
    checkPoint cp = checkPoint(x, y);
    checkpoints.push_back(cp);
}

void SimulateMap::setScanPoint(int y, int x){
    lidarY = y;
    lidarX = x;
}

SimulateMap::~SimulateMap()
{}
