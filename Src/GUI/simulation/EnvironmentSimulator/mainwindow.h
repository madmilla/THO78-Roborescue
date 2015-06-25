/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file MainWindow.cpp
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QInputDialog>
#include "map.h"
#include "editmapwindow.h"
#include "simulatemapwindow.h"
#include "values.h"
#include "PointCloud.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    *   Default constructor of mainWindow.
    *   \brief Default constructor of mainWindow.
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
    *   Default destructor of mainWindow.
    *   \brief Default destructor of mainWindow.
    */
    ~MainWindow();

private slots:
    //! Used when the NewMap button gets clicked
    void on_newMapButton_clicked();
    //! Used when the editMap button gets clicked
    void on_editMapButton_clicked();
    //! Used when the Simulate button gets clicked
    void on_simulateButton_clicked();

private:
    //! Load the correct window.
    void load(QString fileName, char type);
    //! Ui pointer for use with QT.
    Ui::MainWindow *ui;
    //! Map pointer containing map information.
    Map *map = 0;
    //! Editmapwindow for opening the editMapWindow.
    EditMapWindow* editMapWindow;
    //! Int containing the new map begin size.
    static const int newMapBeignSize = 100;
    //! Int containing minimal map size.
    static const int newMapMinSize = 10;
    //! Int containing maximal map size.
    static const int newMapMaxSize = 8000;
    //! Int containing the map step size.
    static const int newMapStepSize = 2;
    //! Pointcloud scale threshhold
    const int SCALETHRESHHOLD {500};
};

#endif // MAINWINDOW_H
