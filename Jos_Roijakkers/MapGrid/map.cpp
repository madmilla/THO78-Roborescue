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

void Map::isGrass(bool checked)
{
    if(checked){
        activeCell->setTerrainType(Cell::TERRAINTYPE::GRASS);
    }
    else{
        activeCell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

