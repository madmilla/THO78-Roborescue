/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file EditMapWindow.h
* @date Created: 08-04-2015
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

#ifndef EDITMAPWINDOW_H
#define EDITMAPWINDOW_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"
#include "values.h"
#include <QDesktopWidget>
#include <QAbstractButton>

namespace Ui {
class EditMapWindow;
}

class EditMapWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
    *   Constructor of editMapWindow
    *   \brief Constructor with a map object as parameter for drawing the map on the GUI
    *   @param map the map object containing the information for the GUI to draw
    */
    explicit EditMapWindow(Map* map, QWidget *parent = 0);
    /*!
    *   Default destructor of editMapWindow
    *   \brief Default destructor of editMapWindo.
    */
    ~EditMapWindow();

private slots:
    //! Used when the obstacle button gets clicked
    void on_obstacleButton_clicked();
    //! Used when the save button gets clicked
    void on_saveMapButton_clicked();
    //! Used when the none button gets clicked
    void on_noneButton_clicked();

private:
    //! A Uipointer used by QT.
    Ui::EditMapWindow *ui;
    //! Used for determining a color.
    Qt::GlobalColor getColorById(int id); 
    //! MousePressEvent is used for handling all mouspresses inside the window.
    void mousePressEvent(QMouseEvent * event);
    //! Bool used for checking if a mouse button is clicked.
    bool mousePressed = true;
    //! Pointer to a given map to store the map information in.
    Map *map;
    //! Sets the selected object to the value of an obstacle.
    int selected = Values::OBSTACLE;
    //! Contains the x coordinate of an object.
    int objectx = 0;
    //! Contains the y coordinate of an object.
    int objecty = 0;
    //! Containts the width of the drawing space.
    int drawWidth = Values::DRAWWIDTH;
    //! Containts the height of the drawing space.
    int drawHeight = Values::DRAWHEIGHT;
    void setButtonPosition(QAbstractButton & button, int x, int y);
    QSize screenSize;
    QSize canvasScreenSize;
    //! eventFilter is used for painting the window with it's contents.
    bool eventFilter(QObject* watched, QEvent* event);
};

#endif // EDITMAPWINDOW_H
