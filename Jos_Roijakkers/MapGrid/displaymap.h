#ifndef DISPLAYMAP_H
#define DISPLAYMAP_H
#include "QTableWidget"
#include "cell.h"

class Map;

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
    Cell::TERRAINTYPE currentType;


private slots:
    void currentCellChanged(int currentRow, int currentColumn);
    void on_isGrass_toggled(bool checked);
    void on_isConcrete_toggled(bool checked);
    void on_isDirt_toggled(bool checked);
    void on_isWater_toggled(bool checked);
    void on_isATV_toggled(bool checked);
    void on_isRosbee_toggled(bool checked);
    void on_isEmpty_toggled(bool checked);
    void on_isQuadcopter_toggled(bool checked);
};

#endif // DISPLAYMAP_H
