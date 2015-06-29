/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file SimulateMapWindow.h
* @date Created: 22-04-2015
* @version 1.0
*
* @author Danny Horvath, Thomas Fink
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef SIMULATEMAPWINDOW_H
#define SIMULATEMAPWINDOW_H

#include <QtWidgets/QWidget>
#include <vector>
#include <iostream>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include "map.h"
#include "simulatemap.h"
#include "values.h"
#include <QtCore/QSize>
#include <QAbstractButton>
#include <QDesktopWidget>
#include <QtGui/QMouseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QTextEdit>

namespace Ui {
class SimulateMapWindow;
}

class SimulateMapWindow : public QDialog
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

    void on_savePcButton_clicked();

    void on_savePcWNButton_clicked();

private:
    //! UI pointer for use with QT.
    Ui::SimulateMapWindow *ui;
    //! Map pointer containing a map object with all map information.
    Map *map;
    //! SimulateMap a simMap pointer so u can use the simulateMap functions.
    SimulateMap *simMap;
    //! paintEvent for painting the map in the GUI.
   // void paintEvent(QPaintEvent *e);
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
    //! eventFilter is used for painting the window with it's contents.
    bool eventFilter(QObject* watched, QEvent* event);
    QSize screenSize;
    QSize canvasScreenSize;
    void setButtonPosition(QAbstractButton & button, int x, int y);
};

#endif // SIMULATEMAPWINDOW_H
