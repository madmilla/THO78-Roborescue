#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>
#include <iostream>
#include <QtDebug>

enum class terrainType
{
    water,
    concrete,
    grass,
    wall,
    none
};

enum class vehicleType
{
    rosbee,
    ATV,
    quadCopter
};

class cell
{
public:
    terrainType surrounding;

    bool quadPresent, ATVPresent, rosbeePresent;

    cell();
    ~cell();

    QTableWidgetItem *formatCell();

    void placeVehicle(vehicleType vehicle);
    void removeVehicle(vehicleType vehicle);
    void changeTerrain(terrainType terrain);
    QString getTerrainAsText();
    std::string writeOut();
};

#endif // CELL_H
