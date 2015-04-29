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
    if(newMapLayout.size() < height || newMapLayout.size() > height){
        return;
    }
    for(int i = 0; i < height; ++i){
        if(newMapLayout[i].size() < width || newMapLayout[i].size() > width){
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

