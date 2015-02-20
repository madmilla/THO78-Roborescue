#include "map.h"
#include <QDebug>
Map::Map(){}
Map::Map(int height, int width, QJsonObject json ):
    jsonMap(json),
    height(height),
    width(width)
{
    Types["wall"] =  QBrush(Qt::red);
    Types["water"] =  QBrush(Qt::blue);
    Types["free"] =  QBrush(Qt::white,Qt::DiagCrossPattern);
    Types["grass"] = QBrush(Qt::green);
    Types["stone"] = QBrush(Qt::lightGray);
    Types["wood"] = QBrush(QColor(139,69,19));
    Types["quad"] = QBrush(Qt::black,Qt::CrossPattern);
    Types["avu"] = QBrush(Qt::darkYellow,Qt::CrossPattern);
    if(!json.isEmpty()){
        QJsonArray rows = json["rows"].toArray();
        for(int i = 0; i < height; i ++){
            QJsonArray cellArray = rows[i].toObject()["row"].toArray();
            for(int j = 0; j < width; j++){
                QJsonObject cell = cellArray[j].toObject();
                QJsonArray cellTypes = cell["cell"].toArray();
                array[i][j] = cellTypes;
            }
        }
    } else{
        for(int i = 0; i<height; i++){
            for(int j = 0; j<width;j++){
                array[i][j] = QJsonArray() ;
            }
        }
    }

}
std::map<QString, QBrush> Map::getTypes(){
    return Types;
}

QBrush Map::getType(QString type){
    return Types[type];
}

QJsonArray Map::getPixel(int x,int y){
    return array[x][y];
}

void Map::setPixel(int x,int y, QJsonObject json){
    array[y/(480/height)][x/(480/width)].append(json);
}

void Map::deletePixel(int x, int y){
    array[y/(480/height)][x/(480/width)] = QJsonArray();
}
int Map::getHeight(){
    return height;
}

int Map::getWidth(){
    return width;
}

Map::~Map()
{

}

