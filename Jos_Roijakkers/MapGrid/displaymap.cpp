#include "displaymap.h"
#include "map.h"
#include <QHeaderView>

DisplayMap::DisplayMap(QWidget* parent):
    QTableWidget(rows,columns,parent),
    currentmap( nullptr ),
    currentcell(nullptr),
    currentType(Cell::TERRAINTYPE::EMPTY)
{
    setRowCount(rows);
    setColumnCount(columns);
    setGeometry(30,30,480,480);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSelectionMode(SelectionMode::SingleSelection);
    setGridStyle(Qt::DashDotLine);
    setEditTriggers(NoEditTriggers);

    horizontalHeader()->hide();
    verticalHeader()->hide();
    horizontalHeader()->setDefaultSectionSize(24);
    verticalHeader()->setDefaultSectionSize(24);
    connect(this,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(currentCellChanged(int,int)));

}

DisplayMap::~DisplayMap()
{

}

void DisplayMap::setCurrentMap(Map* map)
{
    currentmap = map;
    for(int x = 0; x < 20; ++x)
    {
        for(int y = 0; y < 20; ++y)
        {
           setItem(x, y, currentmap->getCell(x,y));
        }
    }
}

void DisplayMap::currentCellChanged(int currentRow, int currentColumn)
{
    if(currentmap){
        currentcell = currentmap->getCell(currentRow,currentColumn);
        currentcell->setTerrainType(currentType);
    }
}

void DisplayMap::on_isATV_toggled(bool checked)
{
    if(checked){
        currentcell->addVehicle(Cell::VEHICLETYPE::ATV);
    }
    else{
        currentcell->removeVehicle(Cell::VEHICLETYPE::ATV);
    }
}

void DisplayMap::on_isQuadcopter_toggled(bool checked)
{
    if(checked){
        currentcell->addVehicle(Cell::VEHICLETYPE::QUADCOPTER);
    }
    else{
        currentcell->removeVehicle(Cell::VEHICLETYPE::QUADCOPTER);
    }
}

void DisplayMap::on_isRosbee_toggled(bool checked)
{
    if(checked){
        currentcell->addVehicle(Cell::VEHICLETYPE::ROSBEE);
    }
    else{
        currentcell->removeVehicle(Cell::VEHICLETYPE::ROSBEE);
    }
}

void DisplayMap::on_isGrass_toggled(bool checked)
{
    if(checked){
        currentType = Cell::TERRAINTYPE::GRASS;
    }
    else{
        currentType = Cell::TERRAINTYPE::EMPTY;
    }
}

void DisplayMap::on_isDirt_toggled(bool checked)
{
    if(checked){
        currentType = Cell::TERRAINTYPE::DIRT;
    }
    else{
        currentType = Cell::TERRAINTYPE::EMPTY;
    }
}

void DisplayMap::on_isConcrete_toggled(bool checked)
{
    if(checked){
        currentType = Cell::TERRAINTYPE::CONCRETE;
    }
    else{
        currentType = Cell::TERRAINTYPE::EMPTY;
    }
}

void DisplayMap::on_isWater_toggled(bool checked)
{
    if(checked){
        currentType = Cell::TERRAINTYPE::WATER;
    }
    else{
        currentType = Cell::TERRAINTYPE::EMPTY;
    }
}

void DisplayMap::on_isEmpty_toggled(bool checked)
{
    if(checked){
        currentType = Cell::TERRAINTYPE::EMPTY;
    }
    else{
        currentType = Cell::TERRAINTYPE::EMPTY;
    }
}


