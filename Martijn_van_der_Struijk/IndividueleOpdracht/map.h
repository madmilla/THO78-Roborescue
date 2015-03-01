#ifndef MAP_H
#define MAP_H

#include "item.h"
#include <QTextStream>

class map
{
public:

    item *getcel(int x,int y);

    map();
    ~map();

private:
    item items[20][20];
};

#endif // MAP_H
