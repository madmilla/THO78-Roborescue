#include "cell.h"

cell::cell():
    surrounding(terrainType::none),
    quadPresent(false),
    ATVPresent(false),
    rosbeePresent(false)
{}

cell::~cell()
{

}

QTableWidgetItem *cell::formatCell()
{
    QTableWidgetItem * item = new QTableWidgetItem;
    switch(surrounding)
    {
        case(terrainType::concrete):
            item->setBackground(Qt::gray);
            break;
        case(terrainType::water):
            item->setBackground(Qt::blue);
            break;
        case(terrainType::grass):
            item->setBackground(Qt::green);
            break;
        case(terrainType::wall):
            item->setBackground(Qt::black);
            break;
        case(terrainType::none):
            item->setBackground(Qt::white);
            break;
    }
    if(rosbeePresent)
    {
       item->setBackground(Qt::yellow);
    }
    if(ATVPresent)
    {
        item->setBackground(Qt::magenta);
    }
    if(quadPresent)
    {
        item->setBackground(Qt::red);
    }
    return item;
}

void cell::placeVehicle(vehicleType vehicle)
{
    switch(vehicle)
    {
        case(vehicleType::quadCopter):
            quadPresent = true;
            break;
        case(vehicleType::ATV):
            ATVPresent = true;
            break;
        case(vehicleType::rosbee):
            rosbeePresent = true;
            break;
    }
}

void cell::removeVehicle(vehicleType vehicle)
{
    switch(vehicle)
    {
        case(vehicleType::quadCopter):
            quadPresent = false;
            break;
        case(vehicleType::ATV):
            ATVPresent = false;
            break;
        case(vehicleType::rosbee):
            rosbeePresent = false;
            break;
    }
}

void cell::changeTerrain(terrainType terrain)
{
    surrounding = terrain;
}

QString cell::getTerrainAsText()
{
    QString s = "";
    switch(surrounding)
    {
        case(terrainType::water):
            s = "terrain: Water";
            break;
        case(terrainType::concrete):
            s = "terrain: Concrete";
            break;
        case(terrainType::grass):
            s = "terrain: Grass";
            break;
        case(terrainType::wall):
            s = "terrain: Wall";
            break;
        case(terrainType::none):
            s = "terrain: Empty";
            break;
    }
    return s;
}

std::string cell::writeOut()
{
    switch(surrounding)
    {
        case(terrainType::water):
            qDebug() << "terrain: " << "water";
            break;
        case(terrainType::concrete):
            qDebug() << "terrain: " << "concrete";
            break;
        case(terrainType::grass):
            qDebug() << "terrain: " << "grass";
            break;
        case(terrainType::wall):
            qDebug() << "terrain: " << "wall";
            break;
        case(terrainType::none):
            qDebug() << "terrain: " << "none";
            break;
    }
    qDebug() << "rosbee: " << rosbeePresent << "\nATV: " << ATVPresent << "\nquadcopter: " << quadPresent << "\n;";
    return "";
}
