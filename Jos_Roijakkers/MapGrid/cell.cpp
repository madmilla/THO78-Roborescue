#include "cell.h"

Cell::Cell():
    QTableWidgetItem(),
    Terrain(TERRAINTYPE::EMPTY),
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

Cell::TERRAINTYPE Cell::getTerrainType()
{
    return Terrain;
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

bool Cell::isQuadcopterPresent()
{
    return QuadcopterPresent;
}

bool Cell::isRosbeePresent()
{
    return RosbeePresent;
}

bool Cell::isATVPresent()
{
    return ATVPresent;
}

std::istream& operator>>(std::istream& stream, Cell& cell)
{
    std::string type;
    stream >> type;
    if(type == "GRASS")
    {
        std::cout << type << std::endl;
        std::cout.flush();
        cell.setTerrainType(Cell::TERRAINTYPE::GRASS);
    }
    else if(type == "CONRETE")
    {
        cell.setTerrainType(Cell::TERRAINTYPE::CONCRETE);
    }
    else if(type == "WATER")
    {
        cell.setTerrainType(Cell::TERRAINTYPE::WATER);
    }
    else if(type == "DIRT")
    {
        cell.setTerrainType(Cell::TERRAINTYPE::DIRT);
    }
    else
    {
        cell.setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }

    return stream;
}

std::istream& operator<<(std::istream &stream, Cell& cell)
{
    return stream;
}

