#ifndef QUADROUTE_H
#define QUADROUTE_H

#include "map.h"


class Quadroute
{
public:
    static const int MAP_WIDTH = 20;
    static const int MAP_HEIGHT = 20;
    Quadroute();
    ~Quadroute();
    typedef int (*pointer_to_arrays)[MAP_HEIGHT];
    void createRoute(pointer_to_arrays objectMatrix, Map *map);

private:
};

#endif // QUADROUTE_H
