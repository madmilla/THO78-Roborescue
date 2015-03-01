#ifndef TILE_H
#define TILE_H
#include <QTableWidgetItem>
#include <iostream>
#include <QMetaEnum>

class Tile :  public QObject, public QTableWidgetItem
{
    Q_OBJECT
    Q_ENUMS(TERRAIN_TYPE)
public:
    enum class VEHICLE_TYPE
    {
        QUADCOPTER,
        ROSBEE,
        ATV
    };

    enum TERRAIN_TYPE
    {
        NONE,
        WATER,
        DIRT,
        CONCRETE,
        GRASS
    };
    Tile(TERRAIN_TYPE type = TERRAIN_TYPE::NONE,
         bool quadcopter = false,
         bool rosbee = false,
         bool ATV = false);

    void setTerrainType(TERRAIN_TYPE type);
    TERRAIN_TYPE getTerrainType();

    void addVehicle(VEHICLE_TYPE type);
    bool isQuadcopterPresent();
    bool isRosbeePresent();
    bool isATVPresent();
    void removeVehicle(VEHICLE_TYPE type);

    void clearTile();
    friend std::ostream& operator<<(std::ostream& stream, Tile& tile);
    friend std::istream& operator>>(std::istream& stream, Tile& tile);
private:
    TERRAIN_TYPE terrainType;
    bool quadcopterPresent;
    bool ATVPresent;
    bool rosbeePresent;
    QMetaEnum metaEnum;
};

#endif // TILE_H
