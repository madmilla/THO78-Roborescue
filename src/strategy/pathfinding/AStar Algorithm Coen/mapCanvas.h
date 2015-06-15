/**
 * @file mapCanvas.h
 * @author Coen Andriessen
 * @version 1.2
 */

#ifndef MAPCANVAS_H
#define MAPCANVAS_H

#include <QWidget>
#include <QtGui>
#include <QMessageBox>
#include <QPainter>

#include "Map.h"
#include "Rosbee.h"

class mapCanvas : public QWidget
{

public:
    // Constructor of mapCanvas.
    mapCanvas(QWidget *parent = 0);
    // Destructor of mapCanvas.
    ~mapCanvas();
    // Function to set map.
    void setMap(Map *map);
    // Function to set rosbee.
    void setRosbee(Rosbee *rosbee);

protected:
    // Function to paint the map.
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    // Function to handle mouse events.
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    Map *map;
    Rosbee * rosbee;
};

#endif // MAPCANVAS_H
