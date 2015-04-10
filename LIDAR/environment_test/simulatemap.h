#ifndef SIMULATEMAP_H
#define SIMULATEMAP_H
#include "map.h"


class SimulateMap
{
private:
    int lidarX = 0;
    int lidarY = 0;
    Map *map;
public:
    SimulateMap(Map *map);
    void simulate();
    void setScanPoint(int y, int x);
    ~SimulateMap();
};

#endif // SIMULATEMAP_H
