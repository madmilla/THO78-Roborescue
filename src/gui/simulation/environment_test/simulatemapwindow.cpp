/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file SimulateMapWindow.cpp
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

#include "simulatemapwindow.h"
#include "ui_simulatemapwindow.h"
#include <QMouseEvent>
#include <QFileDialog>
#include <QTextEdit>

SimulateMapWindow::SimulateMapWindow(Map *map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulateMapWindow),
    map(map)
{
    objectx = (drawWidth / map->width);
    objecty = (drawHeight / map->height);
    simMap = new SimulateMap(map);
    ui->setupUi(this);
}

SimulateMapWindow::~SimulateMapWindow()
{
    delete ui;
    delete simMap;
    simMap = NULL;
    delete map;
    map = NULL;
}

void SimulateMapWindow::on_simulateButton_clicked()
{
    std::string s = simMap->simulate();
    QString qs = QString::fromStdString(s);
    QTextEdit *txt = new QTextEdit();
    txt->setText(qs);

    txt->show();
}

void SimulateMapWindow::mousePressEvent(QMouseEvent * event){
    if(event->pos().x() < Values::DRAWWIDTH){
       if(selected < 0){
           return;
        }
        int positionx = (event->pos().x() - event->pos().x() % objectx) / objectx;
        int positiony = (event->pos().y() - event->pos().y() % objecty) / objecty;
        if(positionx < map->width  &&  positiony < map->height){
            if(selected == Values::CHECKPOINT){
                simMap->addCheckPoint(positionx,positiony);
            }
            else if(selected == Values::EMPTY){
                simMap->deleteCheckPoint(positionx, positiony);
            }
            map->setMapObject(selected, positiony, positionx);
            update();
            mousePressed = true;
        }
    }
}


void SimulateMapWindow::paintEvent(QPaintEvent * /* Unused */){
    if(!mousePressed) return;
    QPainter painter(this);
    int y = 0;
    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(getColorById(forx)));
            ++x;
        }
        ++y;
    }
}

Qt::GlobalColor SimulateMapWindow::getColorById(int id){
    Qt::GlobalColor bColor;
    switch (id) {
    case 0:
        bColor = Qt::white;
    break;
    case 1:
        bColor = Qt::red;
    break;
    case 2:
        bColor = Qt::green;
    break;
    case 3:
        bColor = Qt::blue;
    break;
    default:
        bColor = Qt::black;
    break;
    }
    return bColor;
}

void SimulateMapWindow::on_noneButton_clicked()
{
    selected = Values::EMPTY;
}

void SimulateMapWindow::on_checkpointButton_clicked()
{
    selected = Values::CHECKPOINT;
    std::cout << "clicked: " << selected << std::endl;
}

void SimulateMapWindow::on_savePcButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString());

    if (!fileName.isEmpty()) {
        std::string file = fileName.toStdString();
        Pointcloud pC = simMap->getPointCloud();
        pC.savePointsToFile(file);
    }
}

void SimulateMapWindow::on_savePcWNButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString());

    if (!fileName.isEmpty()) {
        std::string file = fileName.toStdString();
        Pointcloud pC = simMap->getPointCloud();
        Pointcloud pCN = simMap->addNoise(pC);
        pCN.savePointsToFile(file);
    }
}
