#include "tile.h"
#include "tileeditdialog.h"

Tile::Tile(TERRAIN_TYPE type, bool quadcopter, bool rosbee, bool ATV):
    QTableWidgetItem(),
    terrainType(type),
    quadcopterPresent(quadcopter),
    ATVPresent(ATV),
    rosbeePresent(rosbee),
    metaEnum(metaObject()->enumerator(metaObject()->indexOfEnumerator("TERRAIN_TYPE")))
{
}

void Tile::setTerrainType(TERRAIN_TYPE type)
{
    terrainType = type;
    switch(terrainType)
    {
    case(TERRAIN_TYPE::DIRT):
        setBackground(Qt::yellow);
        break;
    case(TERRAIN_TYPE::GRASS):
        setBackground(Qt::green);
        break;
    case(TERRAIN_TYPE::CONCRETE):
        setBackground(Qt::gray);
        break;
    case(TERRAIN_TYPE::WATER):
        setBackground(Qt::blue);
        break;
    case(TERRAIN_TYPE::NONE):
        setBackground(Qt::white);
        break;
    }
}

Tile::TERRAIN_TYPE Tile::getTerrainType()
{
    return terrainType;
}

void Tile::addVehicle(VEHICLE_TYPE type)
{
    switch(type)
    {
    case(VEHICLE_TYPE::QUADCOPTER):
        quadcopterPresent = true;
        break;
    case(VEHICLE_TYPE::ROSBEE):
        rosbeePresent = true;
        break;
    case(VEHICLE_TYPE::ATV):
        ATVPresent = true;
        break;
    }
}

bool Tile::isQuadcopterPresent()
{
    return quadcopterPresent;
}

bool Tile::isRosbeePresent()
{
    return rosbeePresent;
}

bool Tile::isATVPresent()
{
    return ATVPresent;
}

void Tile::removeVehicle(VEHICLE_TYPE type)
{
    switch(type)
    {
    case(VEHICLE_TYPE::QUADCOPTER):
        quadcopterPresent = false;
        break;
    case(VEHICLE_TYPE::ROSBEE):
        rosbeePresent = false;
        break;
    case(VEHICLE_TYPE::ATV):
        ATVPresent = false;
        break;
    }
}

void Tile::clearTile()
{
    setTerrainType(TERRAIN_TYPE::NONE);
    quadcopterPresent = false;
    rosbeePresent = false;
    ATVPresent = false;
}

std::istream &operator>>(std::istream &stream, Tile &tile)
{
    std::string type;
    stream >> type >> tile.quadcopterPresent >> tile.rosbeePresent >> tile.ATVPresent;
    tile.setTerrainType(static_cast<Tile::TERRAIN_TYPE>(tile.metaEnum.keyToValue(type.c_str())));
    return stream;
}

std::ostream& operator<<(std::ostream &stream, Tile &tile)
{
    std::string terrainType = tile.metaEnum.valueToKey(tile.terrainType);
    stream << terrainType << ' ' << tile.quadcopterPresent << ' ' << tile.rosbeePresent << ' ' << tile.ATVPresent;
    return stream;
}
