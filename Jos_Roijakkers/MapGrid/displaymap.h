#ifndef DISPLAYMAP_H
#define DISPLAYMAP_H
#include "QTableWidget"

class Map;
class Cell;

const int rows(20);
const int columns(20);

class DisplayMap : public QTableWidget
{
    Q_OBJECT
public:
    DisplayMap(QWidget* parent = nullptr);
    ~DisplayMap();
    void setCurrentMap(Map* map);

private:
    Map* currentmap;
    Cell* currentcell;


private slots:
    void currentCellChanged(int currentRow, int currentColumn);
    void isGrass(bool);
    void isConcrete(bool);
    void isDirt(bool);
    void isWater(bool);
    void isQuadcopter(bool);
    void isATV(bool);
    void isRosbee(bool);
};

#endif // DISPLAYMAP_H
