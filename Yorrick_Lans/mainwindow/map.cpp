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

QString map::writeOut()
{
    QString s = "";
    for(int row = 0; row < 20; ++row)
    {
        for(int column = 0; column < 20; ++column)
        {
            s += QString("row: %1\n").arg(row+1);
            s += QString("column: %1\n").arg(column+1);
            s += getCell(row, column)->writeOut();
            s += ";\n";
        }
    }
    return s;
}

