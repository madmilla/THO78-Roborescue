#include "map.h"


Map::Map()
{
    for(int i = 0; i < 400; i++)
    {
        cells.push_back(Cell());
    }
}

Map::~Map()
{
}
Cell *Map::getCell(int row, int column)
{
    return &cells.at((row) * 20 + (column));
}

void Map::setActiveCell(int row, int column)
{
    activeCell = getCell(row,column);
}

void Map::isATV(bool checked)
{
    if(checked){
        activeCell->addVehicle(Cell::VEHICLETYPE::ATV);
    }
    else{
        activeCell->removeVehicle(Cell::VEHICLETYPE::ATV);
    }
}

void Map::isQuadcopter(bool checked)
{
    if(checked){
        activeCell->addVehicle(Cell::VEHICLETYPE::QUADCOPTER);
    }
    else{
        activeCell->removeVehicle(Cell::VEHICLETYPE::QUADCOPTER);
    }
}

void Map::isRosbee(bool checked)
{
    if(checked){
        activeCell->addVehicle(Cell::VEHICLETYPE::ROSBEE);
    }
    else{
        activeCell->removeVehicle(Cell::VEHICLETYPE::ROSBEE);
    }
}

void Map::isGrass(bool checked)
{
    if(checked){
        activeCell->setTerrainType(Cell::TERRAINTYPE::GRASS);
    }
    else{
        activeCell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

void Map::isDirt(bool checked)
{
    if(checked){
        activeCell->setTerrainType(Cell::TERRAINTYPE::DIRT);
    }
    else{
        activeCell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

void Map::isConcrete(bool checked)
{
    if(checked){
        activeCell->setTerrainType(Cell::TERRAINTYPE::CONCRETE);
    }
    else{
        activeCell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

void Map::isWater(bool checked)
{
    if(checked){
        activeCell->setTerrainType(Cell::TERRAINTYPE::WATER);
    }
    else{
        activeCell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}


