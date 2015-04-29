#include "simulatemap.h"
#include <iostream>
#include <fstream>
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

    if(checkpoints.size() > 0){
        for(int i = 0; (i < checkpoints.size()); ++i){
            y = 0;
            for(std::vector<int> fory : map->getMapContent()){
                setScanPoint(checkpoints[i].getY(), checkpoints[i].getX());
                int x = 0;
                for(int forx : fory){
                    if(forx == Values::OBSTACLE){
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
        pC.savePointsToFile("pointCloud");
        s += oss.str();
    }
    return s;
}

Pointcloud SimulateMap::getPointCloud(){
    return pC;
}

void SimulateMap::addCheckPoint(int x, int y){
    if(x < 0 || y < 0){
        return;
    }
    if(x < map->width && y < map->height){
        checkPoint cp = checkPoint(x, y);
        checkpoints.push_back(cp);
    }
}

void SimulateMap::deleteCheckPoint(int x, int y){
    if(x < 0 || y < 0){
        return;
    }
    if(x < map->width && y < map->height){
        for(int i = 0; (i < checkpoints.size()); ++i){
            if(checkpoints[i].getX() == x && checkpoints[i].getY() == y){
                checkpoints.erase(checkpoints.begin() + i);
            }
        }
    }
}

void SimulateMap::setScanPoint(int y, int x){
    lidarY = y;
    lidarX = x;
}

SimulateMap::~SimulateMap()
{
    delete map;
    map = NULL;
}
