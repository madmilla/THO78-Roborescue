#ifndef MAPSYSTEM_H
#define MAPSYSTEM_H

#include "map.h"
#include <exception>

class MapSystem
{
public:
    MapSystem();
    ~MapSystem();
    Map* createNewMap();
    Map* openMap(QString fileName);
    void saveMap(QString fileName);
    bool canSave();
private:
    Map* map = nullptr;
};

#endif // MAPSYSTEM_H
