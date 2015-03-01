#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <QTableWidgetItem>


class Cell : public QTableWidgetItem
{
public:
    Cell();
    ~Cell();

    enum class TERRAINTYPE
    {
        WATER,
        DIRT,
        CONCRETE,
        GRASS,
        EMPTY
    };

    enum class VEHICLETYPE
    {
        QUADCOPTER,
        ATV,
        ROSBEE
    };

    void setTerrainType(TERRAINTYPE Terrain);
    void addVehicle(VEHICLETYPE Vehicle);
    void removeVehicle(VEHICLETYPE Vehicle);
    void clearTile();
    friend std::ostream& operator<<(std::ostream& stream,Cell& cell);
private:
    bool QuadcopterPresent;
    bool ATVPresent;
    bool RosbeePresent;
    TERRAINTYPE Terrain;
    VEHICLETYPE Vehicle;
};

#endif // CELL_H
