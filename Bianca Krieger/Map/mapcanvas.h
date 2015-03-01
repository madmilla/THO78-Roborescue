#ifndef MAPCANVAS_H
#define MAPCANVAS_H

#include <QWidget>
#include <QtGui>

#include "map.h"

class MapCanvas : public QWidget
{
public:
    MapCanvas(QWidget *parent = 0);

    void setMap(Map * map);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    static QColor COLOR_BLOCK;
    static QColor COLOR_FREE;
    static QColor COLOR_QUAD;

    Map * map;
};

#endif // MAPCANVAS_H
