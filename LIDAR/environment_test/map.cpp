#include "map.h"
#include <QtCore>
#include <QVector>
#include <iostream>

Map::Map(QString fileName):
mapName(fileName)
{
    if(!fileName.isEmpty()){
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        int y = 0;
        int x = 0;
        while(!file.atEnd()){
            QString line = file.readLine();
            line.remove(QRegExp("[\\n\\t\\r]"));
            mapLayout.resize((y+1));
            for(int i = 0; i < line.length(); i++ ){
                x = (int)(line[i].toLatin1() - '0');
                mapLayout[y].resize((i+1));
                mapLayout[y][i] = x;
            }
            mapLayout[y];
            y++;
        }
        height = mapLayout.size();
        width = mapLayout[0].length();
        file.close();
    }
}

Map::~Map(){

}

void Map::setMapObject(int object,int x, int y){
    if(x <= width && y <= height){
        mapLayout[y][x] = object;
    }
}

QVector<QVector< int > > Map::getMapContent(){
    return mapLayout;
}

void Map::setMapContent(QVector<QVector< int > > newMapLayout){
     mapLayout = newMapLayout;
}

void Map::saveMap(){
    QFile mapFile(mapName);
    if(!mapFile.open((QIODevice::WriteOnly | QIODevice::Text))) return;
    QTextStream mfOut(&mapFile);
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            mfOut << mapLayout[y][x];
        }
        if(y != height - 1)mfOut << '\n';
    }
    mapFile.close();
}

Qt::GlobalColor Map::getColorById(int id){
    Qt::GlobalColor bColor;
    switch (id) {
    case 0:
        bColor = Qt::white;
    break;
    case 1:
        bColor = Qt::red;
    break;
    case 2:
        bColor = Qt::green;
    break;
    case 3:
        bColor = Qt::blue;
    break;
    default:
        bColor = Qt::black;
    break;
    }
    return bColor;
}

