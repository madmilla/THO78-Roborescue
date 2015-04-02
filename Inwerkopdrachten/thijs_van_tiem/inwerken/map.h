#ifndef MAP_H
#define MAP_H
#include "cells.h"



class map
{
public:

    map();
    ~map();

    cells *getcel(int x, int y); // pointer dus geen kopie


private:
    cells cellen[20][20]; // maakt via cells 400 cellen aan (x en y in een dimensie)
    // dit wordt standaard gevuld
};

#endif // MAP_H
