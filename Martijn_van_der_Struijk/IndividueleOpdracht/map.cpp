#include "map.h"


map::map()
{

}

map::~map()
{

}


item *map::getcel(int x,int y){
    return &items[x][y];
}


