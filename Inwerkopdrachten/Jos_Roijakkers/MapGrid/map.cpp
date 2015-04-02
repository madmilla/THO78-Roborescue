#include "map.h"
#include "displaymap.h"

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

std::istream& operator>>(std::istream& stream, Map& map)
{
    for(int column = 0; column < columns; column++)
    {
        for(int row = 0; row < rows; row++)
        {
            Cell cells;
            stream >> cells;
            map.cells[column * columns + row] = cells;
        }
    }
    return stream;
}




