#include "maplogic.h"

MapLogic::MapLogic(QString filename):
    filename{filename}
{
    loadMap(filename);
}

MapLogic::~MapLogic()
{

}

void MapLogic::loadMap(QString &filename){
    QFile mapFile(filename);
    if(!mapFile.open((QIODevice::ReadOnly | QIODevice::Text))) return;
    QTextStream in(&mapFile);

    int x = 0,y = 0;
    int content;

    mapLayout.resize(mapGridSize);

    while(y <= mapGridSize - 1){
        in >> content;
        mapLayout[y].resize(x+1);
        mapLayout[y][x] = content;

        x++;
        if(x >= mapGridSize){
            x = 0;
            y++;
        }
    }
    mapFile.close();
}


void MapLogic::updateMap(int y, int x, int newContent){
    if(x >= mapLayout.size() || y >= mapLayout.size()) return;
    mapLayout[y][x] = newContent;
}
int MapLogic::getMapData(int y, int x){
    if(x >= mapLayout.size() || y >= mapLayout.size()) return 0;
    return mapLayout[y][x];
}

void MapLogic::saveMap(){
    QFile mapFile(filename);
    if(!mapFile.open((QIODevice::WriteOnly | QIODevice::Text))) return;
    QTextStream mfOut(&mapFile);

    for(int y = 0; y < mapLayout.size(); y++){
        for(int x = 0; x < mapLayout[y].size(); x++){
            if(x != (mapLayout[y].size() - 1)){
                mfOut << mapLayout[y][x] << " ";
            }else{
                mfOut << mapLayout[y][x];
            }
        }
       if(y != (mapLayout.size() - 1)) mfOut << "\n";
    }
    mapFile.close();
}
