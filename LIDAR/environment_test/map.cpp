#include "map.h"
#include <QtCore>
#include <QVector>
#include <iostream>

Map::Map(QString fileName)
{
    if(!fileName.isEmpty()){
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
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
        width = mapLayout[1].length();
        file.close();
    }
}

void Map::setMapObject(int object,int x, int y){
    if(x <= width && y <= height){
        mapLayout[y][x] = object;
    }
}

QVector<QVector< int > > Map::getMap()
{
    return mapLayout;
}

Map::~Map()
{

}

