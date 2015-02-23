#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QColor>

#include <iostream>
#include <map>
#include <vector>

#include "map.h"

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = 0);
    ~MapWidget();

    void setMap(Map &map);
protected:
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent* event);

private:
    Map* map = NULL;

    std::map<int, QColor> colorMap;
};

#endif // MAPWIDGET_H
