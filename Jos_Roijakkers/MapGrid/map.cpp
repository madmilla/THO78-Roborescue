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




