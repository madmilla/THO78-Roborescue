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
    //void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    static QColor COLOR_OBJECT;
    static QColor COLOR_FREE;
    static QColor COLOR_QUADCOPTER;
    static QColor COLOR_ATV;
    static QColor COLOR_QUADCOPTERROUTE;
    static QColor COLOR_ATVROUTE;
    static QColor COLOR_ROUTEBEGIN;
    static QColor COLOR_ROUTEEND;

    //bool startBlock = false; /future use

    Map * map;
};

#endif // MAPCANVAS_H
