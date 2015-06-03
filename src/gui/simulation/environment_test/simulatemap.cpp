/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file SimulateMap.cpp
* @date Created: 22-04-2015
* @version 1.0
*
* @author Danny Horvath, Thomas Fink
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

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
        for(unsigned int i = 0; (i < checkpoints.size()); ++i){
            y = 0;
            for(std::vector<int> fory : map->getMapContent()){
                setScanPoint(checkpoints[i].getY(), checkpoints[i].getX());
                int x = 0;
                for(int forx : fory){
                    if(forx == Values::OBSTACLE){
                        bool obstacleFound = false;
                        int objectX = (x-lidarX);
                        int objectY = (y-lidarY)* -1;
                        if(objectY > -Values::SCANRADIUS && objectY < Values::SCANRADIUS && objectX > -Values::SCANRADIUS && objectX < Values::SCANRADIUS){

                            // CHECK IF LIDAR Y IS SAME as object Y --> scan left or right
                            // ELSE scan top or bottom
                            if(lidarY == y) {
                                // scan left or right
                                if(lidarX-x < 0){
                                    //scan right
                                    // right x
                                    for(int j = 0; j < abs((lidarX-x))-1; ++j){
                                        if(map->getMapObject(lidarY, lidarX+(j+1)) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    //scan left
                                    // left x
                                    for(int j = 0; j < abs((lidarX-x))-1; ++j){
                                        if(map->getMapObject(lidarY, lidarX-(j+1)) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            else if(lidarX == x){
                                // scan top or bottom
                                if(lidarY-y < 0){
                                    //scan bottom
                                    for(int j = 0; j < abs((lidarY-y))-1; ++j){
                                        if(map->getMapObject(lidarY+(j+1), lidarX) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                                else {
                                    //scan top
                                    for(int j = 0; j < abs((lidarY-y))-1; ++j){
                                        if(map->getMapObject(lidarY-(j+1), lidarX) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            else {
                                // Diagonaal
                                // check naar linksboven, rechtsboven, rechtsonder of linksonder
                                bool left = (lidarX - x > 0);
                                bool top = (lidarY - y > 0);

                                // linksboven
                                if(left && top) {
                                    for(int j = 0; j < abs((lidarY-y))-1; ++j){
                                        if(map->getMapObject(lidarY-(j+1), lidarX-(j+1)) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                                // linksonder
                                else if(left && !top) {
                                    for(int j = 0; j < abs((lidarY-y))-1; ++j){
                                        if(map->getMapObject(lidarY+(j+1), lidarX-(j+1)) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                                // rechtsonder
                                else if(!left && !top) {
                                    for(int j = 0; j < abs((lidarY-y))-1; ++j){
                                        if(map->getMapObject(lidarY+(j+1), lidarX+(j+1)) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }
                                // rechtsboven
                                else if(!left && top) {
                                    for(int j = 0; j < abs((lidarY-y))-1; ++j){
                                        if(map->getMapObject(lidarY-(j+1), lidarX+(j+1)) == Values::OBSTACLE){
                                            obstacleFound = true;
                                            break;
                                        }
                                    }
                                }                               
                            }

                            if(!obstacleFound){
                                pC.setPoint(objectX,objectY);
                                oss << "Checkpoint " << (i+1) <<" found object at: (X:" << objectX << ",Y:" << objectY <<")\n";
                            }
                        }
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
        for(unsigned int i = 0; (i < checkpoints.size()); ++i){
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

Pointcloud SimulateMap::addNoise(Pointcloud pc){
   //  Pointcloud pNC;
   // for(Pointcloud::Point p : *pc.getPoints()){
   //     pNC.setPoint(p);
   // }
    Pointcloud pNC(pc);
    int cPx = checkpoints[0].getX();
    int cPy = checkpoints[0].getY();

    for(int i = 0; i < pNC.getPoints()->size(); ++i){
        int pCx = pNC.getPoints()->at(i).X;
        int pCy = pNC.getPoints()->at(i).Y;
        int distancex = (pCx - cPx)^2;
        int distancey = (pCy - cPy)^2;

        double distance = sqrt(distancex - distancey);
        if(distance > (Values::NOISETHRESHOLD/10)){
            std::cout << "Point distance: " << distance << "\n";
            int intDistance = static_cast<int>(distance * 10);
            int randomXValue = (rand()% (intDistance * 2)) - intDistance;
            int randomYValue = (rand()% (intDistance * 2)) - intDistance;
            randomXValue = randomXValue / 10;
            randomYValue = randomYValue / 10;
            std::cout << "Random distance: " << randomXValue <<" , " <<  randomYValue <<"\n";
            Pointcloud::Point newPosition =  pNC.getPoints()->at(i);
            newPosition.X += randomXValue;
            newPosition.Y += randomYValue;
            pNC.getPoints()->at(i) = newPosition;
        }
    }
    return pNC;
}
