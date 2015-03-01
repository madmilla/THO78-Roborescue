#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include <vector>
#include <QChar>
#include "object.h"
class Map
{
public:
    Map();
    ~Map();
    std::vector<Tile*> tiles;
     std::vector<Object> objects;
private:

public:
    void addObject(Object o);
    void print();
    void addTile(Tile* t);
    void addNewTile(QChar c,int x, int y);
};

#endif // MAP_H
