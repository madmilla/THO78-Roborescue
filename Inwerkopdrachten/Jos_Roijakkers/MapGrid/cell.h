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
    TERRAINTYPE getTerrainType();
    void addVehicle(VEHICLETYPE Vehicle);
    void removeVehicle(VEHICLETYPE Vehicle);
    void clearTile();
    bool isQuadcopterPresent();
    bool isRosbeePresent();
    bool isATVPresent();
    friend std::ostream& operator<<(std::ostream& stream,Cell& cell);
    friend std::istream& operator>>(std::istream& stream, Cell& cell);
private:
    bool QuadcopterPresent;
    bool ATVPresent;
    bool RosbeePresent;
    TERRAINTYPE Terrain;
    VEHICLETYPE Vehicle;
};

#endif // CELL_H
