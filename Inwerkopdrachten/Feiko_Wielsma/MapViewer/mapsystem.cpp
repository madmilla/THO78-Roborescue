#include "mapsystem.h"
#include "fileloader.h"
#include "filewriter.h"

MapSystem::MapSystem()
{
}

MapSystem::~MapSystem()
{

}

Map* MapSystem::createNewMap()
{
    map = new Map();
    return map;
}

Map* MapSystem::openMap(QString fileName)
{
    map = createNewMap();
    FileLoader fileLoader;

    return fileLoader.openMap(fileName, map);
}

void MapSystem::saveMap(QString fileName)
{    
    FileWriter fileWriter(map);
    fileWriter.saveFile(fileName);
}

bool MapSystem::canSave()
{
    return map != nullptr;
}
