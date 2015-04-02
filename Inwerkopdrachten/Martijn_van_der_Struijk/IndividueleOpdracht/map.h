#ifndef MAP_H
#define MAP_H

#include "item.h"
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <QFile>
class map
{
public:
    void loadFile(QString fileName);
    void saveFile(QString fileName);
    item *getcel(int x,int y);

    map();
    ~map();

private:
    item items[20][20];
};

#endif // MAP_H
