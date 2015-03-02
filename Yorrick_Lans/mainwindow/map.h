#ifndef MAP_H
#define MAP_H

#include "cell.h"


class map
{
public:
    map();
    ~map();

    cell* getCell(int x, int y);
    QString writeOut();

private:
    cell cells[20][20]; // twodimensional
};

#endif // MAP_H
