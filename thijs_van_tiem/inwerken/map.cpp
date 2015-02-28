#include "map.h"

map::map()
{

}

map::~map()
{

}

cells *map::getcel(int x, int y)   // returnt de huidige celpositie
{
    return &cellen[x][y]; // return de geheugen plek van de x en y (zonder reference (zweepslag) kan dit niet)
}

