#ifndef MAP_H
#define MAP_H
#include "cell.h"
#include <vector>


class Map : public QObject
{
public:
    Map();
    ~Map();
    Cell* getCell(int row, int column);
    void setActiveCell(int, int);
private:
    std::vector<Cell> cells;
    Cell* activeCell;

private slots:
    void isGrass(bool);
    void isConcrete(bool);
    void isDirt(bool);
    void isWater(bool);
    void isQuadcopter(bool);
    void isATV(bool);
    void isRosbee(bool);
};

#endif // MAP_H
