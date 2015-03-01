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
    ObjectType getType(int x, int y);
    void setType(int x, int y, ObjectType type);
    std::vector<Object>& getObjects();
private:
    std::vector<Object> objects;
};

#endif
