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
#include <QtCore>
#include <QVector>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Map::Map(string fileName, int height, int width):
    fileName(fileName),
    height(height),
    width(width)
{
    if(!fileName.empty()){
        createNewMap(fileName);
        loadMap(fileName);
    }
}

Map::Map(string fileName):
    fileName(fileName)
{
    height = 0;
    width = 0;
    if(!fileName.empty()){
        ifstream mapFile;
        mapFile.open(fileName);
        if(!mapFile.is_open()){
            return;
        }
        if(height == 0 && width == 0){
            string line;
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

Map::~Map(){
}

void Map::loadMap(string fileName){
    ifstream mapFile;
    mapFile.open(fileName);
    if(!mapFile.is_open()){
        return;
    }
    int x = 0,y = 0;
    int content = 0;

    mapLayout.resize(height);
    mapLayout[y].resize(width);
    while(y < height){
        try{
            mapFile >> content;
        }
        catch(std::ifstream::failure e){
            std::cout << e.what() << std::endl;
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

vector<vector< int > > Map::getMapContent(){
    return mapLayout;
}

void Map::setMapContent(vector<vector< int > > newMapLayout){
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
    ofstream mapFile;
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

void Map::createNewMap(string fileName){
    ofstream mapFile;
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

