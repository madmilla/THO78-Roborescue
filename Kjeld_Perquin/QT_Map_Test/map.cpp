#include "map.h"
#include <iostream>

Map::Map():
    nrOfRows(0),
    nrOfColumns(0)
{
}

Map::Map(int rows, int columns):
    nrOfRows(rows),
    nrOfColumns(columns)
{
    for(int i = 0; i < nrOfRows * nrOfColumns; i++)
    {
        tiles.push_back(new Tile);
    }
}

Tile* Map::getTile(int row, int column)
{
    return tiles[row * nrOfColumns + column];
}

int Map::getRows()
{
    return nrOfRows;
}

int Map::getColumns()
{
    return nrOfColumns;
}

std::ostream& operator<<(std::ostream& stream, Map& map)
{
    stream << map.nrOfRows << ' ' << map.nrOfColumns << std::endl;
    for(int columns = 0; columns < map.nrOfColumns; columns++)
    {
        for(int rows = 0; rows < map.nrOfRows; rows++)
        {
            stream << *map.tiles[columns*map.nrOfColumns + rows] << std::endl;
        }
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, Map& map)
{
    for(int columns = 0; columns < map.nrOfColumns; columns++)
    {
        for(int rows = 0; rows < map.nrOfRows; rows++)
        {
            Tile *tile = new Tile;
            stream >> *tile;
            map.tiles[columns*map.nrOfColumns + rows] = tile;
        }
    }
    return stream;
}
