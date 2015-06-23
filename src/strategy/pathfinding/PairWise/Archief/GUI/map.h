#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "route.h"
#include "pairwisemove.h"

class Map
{
public:
    static const int MAP_WIDTH = 20;
    static const int MAP_HEIGHT = 20;

    enum class object{	//!max 255 objecten!
        empty = 0,
        object = 1,
        quadcopter = 2,
        atv = 3,
        quadcopterRoute = 4,
        atvRoute = 5,
        routeBegin = 6,
        routeEnd = 7
    };

    Map();
    ~Map();

    void set(int x, int y, int value);
    Map::object get(int x, int y);

    static Map * loadFromFile(const char * filename);
    void saveToFile(const char * filename);

    //void setFinish();
    typedef int (*pointer_to_arrays)[MAP_HEIGHT];

    pointer_to_arrays getObjectMatrix();
    //void setRoute(int waypoints[][MAP_HEIGHT], const int numberOfWaypoints);

private:
    int objectMatrix[MAP_WIDTH][MAP_HEIGHT];
};

#endif // MAP_H
