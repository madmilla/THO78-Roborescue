#include "map.h"
#include <QTextStream>
Map::Map()
{

}

Map::~Map()
{

}
void Map::addNewTile(QChar c,int x, int y){
    this->addTile(new Tile(c,x,y));

}
void Map::addTile(Tile* t){
    this->tiles.push_back(t);
}
void Map::print(){
    for (Tile* t: tiles){
    QTextStream(stdout) << " x " << t->x <<t->y << " x ";
    }


}
void Map::addObject(Object o){

    this->objects.push_back(o);


}
Tile* Map::getTileAt(int x, int y){
    for(Tile* t: tiles){
        if(t->x==x && t->y==y){return t;}

    }


}
