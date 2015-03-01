#ifndef MAP_H
#define MAP_H

#include <vector>
#include "object.h"

class Map
{
public:
    Map();
    ~Map();

    void addObject(Object);
    QColor getColor(int x, int y);
    void setColor(int x, int y, QColor color);
    std::vector<Object>& getObjects();
private:
    std::vector<Object> objects;
};

#endif
