#ifndef CELL_H
#define CELL_H
#include "tile.h"
#include "vector"
class Cell
{
public:
    Cell();
    ~Cell();
    std::vector<Tile*> tiles;
    bool contains(Tile*t);
};

#endif // CELL_H
