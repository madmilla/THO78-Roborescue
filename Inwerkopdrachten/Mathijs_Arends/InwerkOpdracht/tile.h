#ifndef TILE_H
#define TILE_H
#include "QChar"

class Tile
{
public:
    Tile();
    Tile(QChar c,int x, int y);
    ~Tile();
    QChar type;
    int x;
    int y;
};

#endif // TILE_H
