#include "cell.h"

Cell::Cell():
    QTableWidgetItem(),
    Terrain(TERRAINTYPE::CONCRETE),
    Vehicle(VEHICLETYPE::QUADCOPTER),
    QuadcopterPresent(false),
    ATVPresent(false),
    RosbeePresent(false)
{
}

Cell::~Cell()
{
}

void Cell::setTerrainType(Cell::TERRAINTYPE TerrainType)
{
    Terrain = TerrainType;
    switch(TerrainType)
    {
    case(TERRAINTYPE::WATER):
        setBackground(QColor(Qt::blue));
        break;
    case(TERRAINTYPE::CONCRETE):
        setBackground(QColor(Qt::gray));
        break;
    case(TERRAINTYPE::DIRT):
        setBackground(QColor(Qt::yellow));
        break;
    case(TERRAINTYPE::GRASS):
        setBackground((QColor(Qt::green)));
        break;
    case(TERRAINTYPE::EMPTY):
        setBackground((QColor(Qt::white)));
        break;
    }
}

void Cell::addVehicle(VEHICLETYPE VehicleType)
{
    Vehicle = VehicleType;
    switch(VehicleType)
    {
    case(VEHICLETYPE::QUADCOPTER):
        setBackground((QColor(Qt::magenta)));
        QuadcopterPresent = true;
        break;
    case(VEHICLETYPE::ATV):
        setBackground((QColor(Qt::black)));
        ATVPresent = true;
        break;
    case(VEHICLETYPE::ROSBEE):
        setBackground((QColor(Qt::red)));
        RosbeePresent = true;
        break;
    }
}

void Cell::removeVehicle(VEHICLETYPE VehicleType)
{
    switch(VehicleType)
    {
    case(VEHICLETYPE::QUADCOPTER):
        QuadcopterPresent = false;
        break;
    case(VEHICLETYPE::ATV):
        ATVPresent = false;
        break;
    case(VEHICLETYPE::ROSBEE):
        RosbeePresent = false;
        break;
    }
}

void Cell::clearTile()
{
    Terrain = TERRAINTYPE::CONCRETE;
    QuadcopterPresent = false;
    ATVPresent = false;
    RosbeePresent = false;
}

std::ostream& operator<<(std::ostream &stream, Cell& cell)
{
    return stream;
}

