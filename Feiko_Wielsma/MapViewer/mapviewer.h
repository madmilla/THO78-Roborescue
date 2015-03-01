#ifndef MAPVIEWER_H
#define MAPVIEWER_H

#include <QWidget>
//Own map class that stores objects
#include "map.h"
//std lib map for key value pair
#include <map>

enum class ObjectType {
    Empty,
    Wall,
    Tree,
    Quad,
    ATV
};

class MapViewer : public QWidget
{
    Q_OBJECT

public:
    MapViewer(QWidget* parent = 0);
    ~MapViewer();
    void setMap(Map* newMap);
    Map* getMap();
    void setSelectedObject(ObjectType);
private:
    std::map<ObjectType, QColor> objectColorMap;

    void drawCell(QPainter& painter, int x, int y);
    Map* map = nullptr;
    ObjectType selectedObject;

    const int GRID_SIZE = 20;
    const int CELL_HEIGHT = 18;
    const int CELL_WIDTH = 18;
    const int CELL_BORDER_SIZE = 1;
    const int CELL_PADDING = 1;
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif

