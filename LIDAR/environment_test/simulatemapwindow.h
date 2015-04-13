#ifndef SIMULATEMAPWINDOW_H
#define SIMULATEMAPWINDOW_H

#include <QWidget>
#include <vector>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"
#include "simulatemap.h"
#include "values.h"

namespace Ui {
class SimulateMapWindow;
}

class SimulateMapWindow : public QWidget
{
    Q_OBJECT

public:
    //!The Contructor for the SimulateMapWindow
    /*!
    @param Map: the ui needs to know the map to use his functions
    */
    explicit SimulateMapWindow(Map *map, QWidget *parent = 0);
    ~SimulateMapWindow();

private slots:
    //! Used when the simulate button gets clicked
    void on_simulateButton_clicked();
    //! Used when the Lidar button gets clicked
    void on_lidarButton_clicked();
    //! Used when the none button gets clicked
    void on_noneButton_clicked();

private:
    Ui::SimulateMapWindow *ui;
    Map *map;
    SimulateMap *simMap;
    void paintEvent(QPaintEvent *e);//Paint the window
    void mousePressEvent(QMouseEvent * event);//Handle moude events
    Qt::GlobalColor getColorById(int id);//Get a color
    int objectx = 0;
    int objecty = 0;
    int drawWidth = Values::DRAWWIDTH;//size of the drawing space
    int drawHeight = Values::DRAWHEIGHT;//size of the drawing space
    int selected = Values::LIDAR;
    bool mousePressed = true;
};

#endif // SIMULATEMAPWINDOW_H
