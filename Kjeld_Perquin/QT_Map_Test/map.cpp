#include "map.h"
#include <iostream>

Map::Map(int rows, int columns):
    nrOfRows(rows),
    nrOfColumns(columns)
{
    resizeTileContainer();
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

void Map::resizeTileContainer()
{
    size_t newSize = nrOfRows * nrOfColumns - tiles.size();
    for(int i = 0; i < newSize ; ++i)
    {
        tiles.push_back(new Tile());
    }
}

std::ostream& operator<<(std::ostream& stream, Map& map)
{
    //First output the number of rows and number of columns.
    stream << map.nrOfRows << ' ' << map.nrOfColumns << std::endl;
    //Then output every tile in the map from left to right and top to bottom.
    for(int rows = 0; rows < map.nrOfRows; ++rows)
    {
        for(int columns = 0; columns < map.nrOfColumns; ++columns)
        {
            stream << *map.tiles[rows * map.nrOfColumns + columns] << std::endl;
        }
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, Map& map)
{
    //First read in the map size.
    stream >> map.nrOfRows >> map.nrOfColumns;
    //Then resize the container.
    map.resizeTileContainer();
    //Then read in every tile and saving them from
    //left to right and top to bottom.
    for(int rows = 0; rows < map.nrOfRows; ++rows)
    {
        for(int columns = 0; columns < map.nrOfColumns; ++columns)
        {
            Tile *tile = new Tile;
            stream >> *tile;
            map.tiles[rows*map.nrOfColumns + columns] = tile;
        }
    }
    return stream;
}
