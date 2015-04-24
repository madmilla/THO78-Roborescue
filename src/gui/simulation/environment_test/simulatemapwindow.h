/*!
 *  \brief     Class containing all GUI handlings of the SimulateMap class.
 *  \details   The SimulateMapWindow class is used for event handling and drawing in the simulateMap window.
 *  \author    Danny Horvath - 1634676
 *  \author    Thomas Fink - 1634907
 *  \version   1.0
 *  \date      15-04-2015
 */

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
    /*!
    *   The constructor for the SimulateMapWindow given a Map.
    *   \brief The constructor of SimulateMapWindow containing a map with all the map information in it.
    *   @param Map a map pointer containing the information of the given map to be drawn on screen.
    */
    explicit SimulateMapWindow(Map *map, QWidget *parent = 0);
    /*!
    *   The default constructor for the SimulateMapWindow.
    *   \brief Destructs all made objects and clears the memory.
    */
    ~SimulateMapWindow();

private slots:
    //! Used when the simulate button is clicked.
    void on_simulateButton_clicked();
    //! Used when the none button is clicked.
    void on_noneButton_clicked();
    //! Used when the checkpointButton is clicked.
    void on_checkpointButton_clicked();

private:
    //! UI pointer for use with QT.
    Ui::SimulateMapWindow *ui;
    //! Map pointer containing a map object with all map information.
    Map *map;
    //! SimulateMap a simMap pointer so u can use the simulateMap functions.
    SimulateMap *simMap;
    //! paintEvent for painting the map in the GUI.
    void paintEvent(QPaintEvent *e);
    //! mousePressEvent for handling all mouse events.
    void mousePressEvent(QMouseEvent * event);
    //! Converts an int to a QT::GlobalColor.
    Qt::GlobalColor getColorById(int id);
    //! X coordinates of an object.
    int objectx = 0;
    //! Y coordinates of an object.
    int objecty = 0;
    //! Width of the drawing space.
    int drawWidth = Values::DRAWWIDTH;
    //! Height of the drawing space.
    int drawHeight = Values::DRAWHEIGHT;
    //! Value of selected object.
    int selected = Values::CHECKPOINT;
    //! Check if mouse is pressed.
    bool mousePressed = true;
};

#endif // SIMULATEMAPWINDOW_H
