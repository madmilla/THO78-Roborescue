#ifndef MAP_H
#define MAP_H
#include <vector>
#include "tile.h"

class Map
{
public:
    Map();
    Map(int rows, int columns);
    Tile *getTile(int row, int column);
    int getRows();
    int getColumns();
    friend std::istream& operator>>(std::istream&, Map&);
    friend std::ostream& operator<<(std::ostream&, Map&);
private:
    std::vector<Tile*> tiles;
    int nrOfRows;
    int nrOfColumns;
};

#endif // MAP_H
