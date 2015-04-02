#ifndef SIMULATEMAP_H
#define SIMULATEMAP_H
#include "map.h"


class SimulateMap
{
private:
    void setScanPoint(int y, int x);
    Map *map;
public:
    SimulateMap(Map *map);
    ~SimulateMap();
};

#endif // SIMULATEMAP_H
