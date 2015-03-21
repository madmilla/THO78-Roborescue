#include "mapdisplaywidget.h"
#include <QHeaderView>
#include "map.h"
#include <iostream>

MapDisplayWidget::MapDisplayWidget(QWidget *parent):
    QTableWidget(parent),
    currentMap(nullptr),
    currentTile(nullptr),
    currentType(Tile::TERRAIN_TYPE::NONE)
{
    applyInitialSettings();
    connect(this,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(currentTileChanged(int,int)));
}

void MapDisplayWidget::applyInitialSettings()
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSelectionMode(SelectionMode::SingleSelection);
    horizontalHeader()->hide();
    verticalHeader()->hide();
    setEditTriggers(NoEditTriggers);
    setGeometry(200,50,480,480);
}

void MapDisplayWidget::setCurrentMap(Map* map)
{
    currentMap = map;
    fitToMap();
    for(int i = 0; i < currentMap->getRows(); i++)
    {
        for(int j = 0; j < currentMap->getColumns(); j++)
        {
            setItem(i,j,currentMap->getTile(i,j));
        }
    }
}

void MapDisplayWidget::fitToMap()
{
    int nrOfRows = currentMap->getRows();
    int nrOfCols = currentMap->getColumns();
    int tileWidth = 480/nrOfCols;
    int tileHeight = 480/nrOfRows;
    //
    int length = tileWidth < tileHeight ? tileWidth : tileHeight;
    horizontalHeader()->setDefaultSectionSize(length);
    verticalHeader()->setDefaultSectionSize(length);
    setColumnCount(nrOfCols);
    setRowCount(nrOfRows);
    setGeometry(200,50,nrOfCols * length, nrOfRows * length);
}

void MapDisplayWidget::currentTileChanged(int col, int row)
{
    currentTile = currentMap->getTile(col,row);
    currentTile->setTerrainType(currentType);
}

void MapDisplayWidget::setGrassTile()
{
    currentType = Tile::TERRAIN_TYPE::GRASS;
}

void MapDisplayWidget::setDirtTile()
{
    currentType = Tile::TERRAIN_TYPE::DIRT;
}

void MapDisplayWidget::setConcreteTile()
{
    currentType = Tile::TERRAIN_TYPE::CONCRETE;
}

void MapDisplayWidget::setWaterTile()
{
    currentType = Tile::TERRAIN_TYPE::WATER;
}

void MapDisplayWidget::setEmptyTile()
{
    currentType = Tile::TERRAIN_TYPE::NONE;
}
