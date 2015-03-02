#ifndef MAPDISPLAYWIDGET_H
#define MAPDISPLAYWIDGET_H
#include <QTableWidget>
#include "tile.h"

class Map;

class MapDisplayWidget : public QTableWidget
{
    Q_OBJECT
public:
    MapDisplayWidget(QWidget* parent = nullptr);
    void setCurrentMap(Map* map);
private:
    Map* currentMap;
    Tile* currentTile;
    Tile::TERRAIN_TYPE currentType;
    void fitToMap();

private slots:
    void currentTileChanged(int,int);
    void setGrassTile();
    void setDirtTile();
    void setConcreteTile();
    void setWaterTile();
    void setEmptyTile();
};
#endif // MAPDISPLAYWIDGET_H
