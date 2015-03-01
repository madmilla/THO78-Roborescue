#ifndef MAP_H
#define MAP_H
#include "cell.h"
#include <vector>


class Map : public QObject
{
    Q_OBJECT
public:
    Map();
    ~Map();
    Cell* getCell(int row, int column);
    void setActiveCell(int, int);
    friend std::istream& operator>>(std::istream& stream, Map& map);
private:
    std::vector<Cell> cells;
    Cell* activeCell;
};

#endif // MAP_H
