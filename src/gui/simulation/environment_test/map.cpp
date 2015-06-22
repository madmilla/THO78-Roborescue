/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Map.cpp
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

#include "map.h"

Map::Map(std::string fileName, int height, int width):
    fileName(fileName),
    height(height),
    width(width)
{
    if(!fileName.empty()){
        createNewMap(fileName);
        loadMap(fileName);
    }
}

Map::Map(std::string fileName):
    fileName(fileName)
{
    height = 0;
    width = 0;
    if(!fileName.empty()){
        std::ifstream mapFile;
        mapFile.open(fileName);
        if(!mapFile.is_open()){
            throw Values::FILEEXCEPTION;
        }
        if(height == 0 && width == 0){
            std::string line;
            int i;
            for (i = 0; getline(mapFile, line); ++i);
            line.erase(std::remove_if(line.begin(), line.end(), (int(*)(int))isspace), line.end());
            height = i;
            width = static_cast<int>(line.length());
            mapFile.close();
            loadMap(fileName);
        }
    }
}

Map::Map(std::string fileName, Pointcloud *pcl):
fileName(fileName)
{
    int y = 0;
    height = pcl->getCloudHeight()+1;
    width = pcl->getCloudWidth()+1;
    std::vector<Pointcloud::Point> *points = pcl->getPoints();
    if(points->size() == 0){
        std::cout << "Size = 0" << std::endl;
        throw Values::CONTENTEXCEPTION;
    }
    int minX = 0;
    int minY = 0;

    for(Pointcloud::Point point : *points){
        if(point.X < minX){
            minX = point.X;
        }

        if(point.Y < minY){
            minY = point.Y;
        }
    }
    if(minX < 0){
        minX = minX * -1;
    }
    if(minY < 0){
        minY = minY * -1;
    }

    std::cout << "height: " << height << std::endl;
    std::cout << "width: " << width << std::endl;
    std::cout << "minX: " << minX << std::endl;
    std::cout << "minY: " << minY << std::endl;

    mapLayout.resize(height);
    while(y < height){
      mapLayout[y].resize(width);
      std::cout << y << std::endl;
      y++;
    }
    for(Pointcloud::Point point : *points){
        setMapObject(1,point.Y + minY,point.X + minX);
        std::cout << "X: " << (point.X + minX) << std::endl << "Y: " << (point.Y + minY) << std::endl;
    }

}

Map::~Map(){
}

void Map::loadMap(std::string fileName){
    std::ifstream mapFile;
    mapFile.open(fileName);
    if(!mapFile.is_open()){
        throw Values::FILEEXCEPTION;
    }
    int x = 0,y = 0;
    int content = -1;

    mapLayout.resize(height);
    mapLayout[y].resize(width);
    while(y < height){
        mapFile >> content;

        if(content == -1){
            throw Values::CONTENTEXCEPTION;
        }

        mapLayout[y][x] = content;
        ++x;
        if(x > (width-1)){
            x = 0;
            ++y;
           if(y!=height){
               mapLayout[y].resize(width);
           }
        }
        content = -1;
    }    
    mapFile.close();
}

void Map::setMapObject(int object,int y, int x){
    if(x < 0 || y < 0){
        return;
    }
    if(x < width && y < height){
        if(object >= 0){
            mapLayout[y][x] = object;
        }
    }
}

int Map::getMapObject(int y, int x){
    if(x < 0 || y < 0){
        return -1;
    }
    if(x < width && y < height){
        return mapLayout[y][x];
    }
    return -1;
}

std::vector<std::vector< int > > Map::getMapContent(){
    return mapLayout;
}

void Map::setMapContent(std::vector<std::vector< int > > newMapLayout){
    if(static_cast<int>(newMapLayout.size()) < height || static_cast<int>(newMapLayout.size()) > height){
        return;
    }
    for(int i = 0; i < height; ++i){
        if(static_cast<int>(newMapLayout[i].size()) < width || static_cast<int>(newMapLayout[i].size()) > width){
            return;
        }
    }
    mapLayout = newMapLayout;
}

void Map::saveMap(){
    std::ofstream mapFile;
    mapFile.open(fileName);
    for(int y = 0; y < height; ++y){
        for(int x = 0; x < width; ++x){
            mapFile << mapLayout[y][x];
            if(x != (width-1)){
                mapFile << ' ';
            }
        }
        if(y != (height-1)){
            mapFile << '\n';
        }
    }
    mapFile.close();
}

void Map::createNewMap(std::string fileName){
    std::ofstream mapFile;
    mapFile.open(fileName);
    for(int y = 0; y < height; ++y){
        for(int x = 0; x < width; ++x){
            mapFile << '0';
            if(x != (width-1)){
                mapFile << ' ';
            }
        }
        if(y != (height-1)){
            mapFile << '\n';
        }
    }
    mapFile.close();
}

