#ifndef MAP_H
#define MAP_H
#include "map.h"
#include "QString"
#include "vector"
#include "tile.h"
class map
{
public:
    std::vector<Tile> mymap;
    map();
    ~map();
};

#endif // MAP_H
