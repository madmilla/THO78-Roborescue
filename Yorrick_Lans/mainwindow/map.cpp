#include "map.h"

map::map()
{

}

map::~map()
{

}

cell *map::getCell(int x, int y)
{
    return &cells[x][y];
}

std::string map::writeOut()
{
    for(int row = 0; row < 20; ++row)
    {
        for(int column = 0; column < 20; ++column)
        {
            qDebug() << "row: " << row+1 << "\ncolumn" << column+1;
            getCell(row, column)->writeOut();
        }
    }
    return "";
}

