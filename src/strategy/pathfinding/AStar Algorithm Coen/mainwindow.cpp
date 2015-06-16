/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mainwindow.cpp
* @date Created: 6/15/2015
*
* @author Coen Andriessen
*
* @version 1.4
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

#include "mainwindow.h"

/**
 * Constructor of MainWindow.
 *
 * @param map
 * @param rosbee
 * @param parent
 */

MainWindow::MainWindow(Map * map, Rosbee * rosbee, scanArea * scanarea, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->map = map;
    this->rosbee = rosbee;
    this->scanarea = scanarea;
    mapcanvas = new mapCanvas;

    setCentralWidget(mapcanvas);
    mapcanvas->setMap(map);
    mapcanvas->setRosbee(rosbee);

    // Create saveAct.
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveMap()));

    // Create loadAct.
    loadAct = new QAction(tr("&Load"), this);
    loadAct->setShortcuts(QKeySequence::Open);
    loadAct->setStatusTip(tr("Open the document from disk"));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadMap()));

    // Create closeAct.
    closeAct = new QAction(tr("&Close"), this);
    closeAct->setShortcuts(QKeySequence::Close);
    closeAct->setStatusTip(tr("Close"));
    connect(closeAct, SIGNAL(triggered()), this, SLOT(closeMap()));

    // Creat Menu.
    fileMenu = menuBar()->addMenu(tr("&Map"));
    fileMenu->addAction(saveAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(closeAct);
    setMinimumSize(480, 480);

}

/**
 * Destructor of myXXXDevice.
 */

MainWindow::~MainWindow(){
    delete ui;
}

/**
 * Function to save the loaded map.
 */

void MainWindow::saveMap(){
    // Is not ready
    std::cout << "Save" << std::endl;
}

/**
 * Function to close the loaded map/application.
 */

void MainWindow::closeMap(){
    QCoreApplication::quit();
}

/**
 * Function to load the map by given path and calls update from mapcanvas and start the
 * scanning algorithm from the class scanarea.
 */

void MainWindow::loadMap(){
    //map->loadMap("C:\\Users\\coen__000\\Documents\\TestSystem\\Map1.txt");
    mapcanvas->update();
    //scanarea->run();
}
