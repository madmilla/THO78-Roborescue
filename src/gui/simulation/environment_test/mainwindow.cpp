/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Mainwindow.cpp
* @date Created: 12-04-2015
* @version 2.0
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(map != 0){
        delete map;
        map = NULL;
    }
}

void MainWindow::on_newMapButton_clicked()
{
    bool ok;
    QString fileName = QInputDialog::getText(this, "Create map","Map name:",
                                         QLineEdit::Normal,"map name", &ok);
    if(!ok) return;
    int height = QInputDialog::getInt(this, "Create map","Map height:",
                                      newMapBeignSize,newMapMinSize,newMapMaxSize,newMapStepSize, &ok);
    if(!ok) return;
    int width = QInputDialog::getInt(this, "Create map","Map height:",
                                     newMapBeignSize,newMapMinSize,newMapMaxSize,newMapStepSize, &ok);

    if (ok && !fileName.isEmpty()){
        map = new Map(fileName.toStdString() + ".map",height,width);
    }
}

void MainWindow::on_editMapButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Map Files (*.map)");

    if (!fileName.isEmpty()){
        map = new Map(fileName.toStdString());
        editMapWindow = new EditMapWindow(map);
        editMapWindow->show();
    }
}

void MainWindow::on_simulateButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Map Files (*.map)");

    if (!fileName.isEmpty()){
        map = new Map(fileName.toStdString());
        SimulateMapWindow *simulateMapWindow = new SimulateMapWindow(map);
        simulateMapWindow->show();
    }
}
