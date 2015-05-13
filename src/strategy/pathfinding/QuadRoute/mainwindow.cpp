/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mainwindow.cpp
* @date Created: 4/4/2015
*
* @author Jasper Stas
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

#include <QtWidgets>
#include <iostream>
#include "mainwindow.h"
#include "map.h"
#include "mapcanvas.h"

/**
 * Basic constructor, creates a window.
 * */
MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    map = new Map;
    mapCanvas = new MapCanvas;
    setCentralWidget(mapCanvas);

    mapCanvas->setMap(map);

    createActions();
    createMenus();

    setWindowTitle(tr("MapEditor"));
    setMinimumSize(480, 520);
    resize(480, 480);
}

/**
 * Basic deconstructor
 * */
MainWindow::~MainWindow(){

}

/**
 * This method clears the map by calling a new clear one.
 * */
void MainWindow::newFile(){
    map = new Map;
    mapCanvas->setMap(map);
}

/**
 * This method opens an existing map, with the option to choose from where on your pc.
 * */
void MainWindow::open(){
    //QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    QString fileName = tr("C:\\Users\\Jasper\\Documents\\build-Map-Desktop_Qt_5_2_0_MinGW_32bit-Debug\\Standard.map");
    map = Map::loadFromFile(fileName.toStdString().c_str());
    mapCanvas->setMap(map);
    mapCanvas->update();
    std::cout<<"opened"<<std::endl;
}

/**
 * In this method you can save a map to anywhere on your pc.
 * */
void MainWindow::save(){
    //QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Files (*.*)"));
    QString fileName = tr("C:\\Users\\Jasper\\Documents\\build-Map-Desktop_Qt_5_2_0_MinGW_32bit-Debug\\Standard.map");
    map->saveToFile(fileName.toStdString().c_str());
    std::cout<<"saved"<<std::endl;
}

/**
 * This method creates a route from start to finish.
 * */
void MainWindow::createRoute(){
    quadroute->createRoute(map->getObjectMatrix(), map);
    mapCanvas->update();
}

/**
 * This method sets the actions in the menu bar of the window.
 * */
void MainWindow::createActions(){
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    createRouteAct = new QAction(tr("&Create Route"), this);
    createRouteAct->setShortcuts(QKeySequence::Copy);
    createRouteAct->setStatusTip(tr("Create route from quad to finish"));
    connect(createRouteAct, SIGNAL(triggered()), this, SLOT(createRoute()));
}

/**
 * This method creates the menu bar.
 * */
void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    runMenu = menuBar()->addMenu(tr("&Run"));
    runMenu->addAction(createRouteAct);
}
