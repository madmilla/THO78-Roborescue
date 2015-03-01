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

std::istream& operator>>(std::istream& stream, Cell& cell)
{
    std::string type;
    int quadPresent = 0;
    stream >> type >> quadPresent;
    if(type.compare("GRASS"))
    {
        cell.setTerrainType(Cell::TERRAINTYPE::GRASS);
    }
    else if(type.compare("CONRETE"))
    {
        cell.setTerrainType(Cell::TERRAINTYPE::CONCRETE);
    }
    else if(type.compare("WATER"))
    {
        cell.setTerrainType(Cell::TERRAINTYPE::WATER);
    }
    else if(type.compare("DIRT"))
    {
        cell.setTerrainType(Cell::TERRAINTYPE::DIRT);
    }
    else if (type.compare("EMPTY"))
    {
        cell.setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
    return stream;
}

std::istream& operator<<(std::istream &stream, Cell& cell)
{
    return stream;
}

