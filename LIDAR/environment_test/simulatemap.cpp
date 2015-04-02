#include "simulatemap.h"
#include "values.h"

SimulateMap::SimulateMap(Map *map):
    map(map)
{

}

SimulateMap::~SimulateMap()
{

}

void SimulateMap::setScanPoint(int y, int x){
    map->setMapObject(Values::SCANLOCATION,y,x);
}

