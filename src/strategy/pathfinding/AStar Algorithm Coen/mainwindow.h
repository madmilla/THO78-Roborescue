/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mainwindow.h
* @date Created: 6/15/2015
*
* @author Coen Andriessen
* 
* @version 1.3
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include <QTableWidgetItem>
#include <QWidget>
#include <QApplication>
#include <stdio.h>
#include <iostream>

#include "Map.h"
#include "Rosbee.h"
#include "mapcanvas.h"
#include "ui_mainwindow.h"
#include "scanArea.h"

namespace Ui {
class MainWindow;
}

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor of MainWindow.
    explicit MainWindow(Map * map, Rosbee * rosbee, scanArea * scanarea, QWidget *parent = 0);
    // Destructor of MainWindow.
    ~MainWindow();
private slots:
    // Slot for saving a map.
    void saveMap();
    // Slot for loading a map.
    void loadMap();
    // Slot for closing a map.
    void closeMap();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QAction *newAct;
    QAction *loadAct;
    QAction *saveAct;
    QAction *closeAct;
    Map *map;
    Rosbee *rosbee;
    mapCanvas *mapcanvas;
    scanArea * scanarea;
};

#endif // MAINWINDOW_H
