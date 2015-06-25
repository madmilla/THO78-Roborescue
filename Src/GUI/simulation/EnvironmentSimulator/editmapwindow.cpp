/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file EditMapWindow.cpp
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

#include "editmapwindow.h"
#include "ui_editmapwindow.h"
#include "values.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <vector>
#include <iostream>

EditMapWindow::EditMapWindow(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMapWindow),
    map(map)
{
    ui->setupUi(this);

    std::cout << "map size: " << '(' << map->width << ' ' << map->height << ')' << std::endl;

    screenSize.setWidth(QApplication::desktop()->screenGeometry().width());
    screenSize.setHeight(QApplication::desktop()->screenGeometry().height());
    this->setFixedSize(screenSize.width(), screenSize.height());

    std::cout << "screen size: " << '(' << screenSize.width() << ' ' << screenSize.height() << ')' << std::endl;

    setButtonPosition(*ui->saveMapButton, screenSize.width()-(screenSize.width()/10), screenSize.height() - screenSize.height()/10);
    setButtonPosition(*ui->obstacleButton, screenSize.width()-(screenSize.width()/10), screenSize.height()/10);
    setButtonPosition(*ui->noneButton, screenSize.width()-(screenSize.width()/10), screenSize.height()/8);

    canvasScreenSize.setWidth(screenSize.width() - (screenSize.width()/8));
    canvasScreenSize.setHeight(screenSize.height());
    std::cout << "canvas size: " << '(' << canvasScreenSize.width() << ' ' << canvasScreenSize.height() << ')' << std::endl;

    ui->childWidget->installEventFilter(this);
    ui->childWidget->setFixedWidth(canvasScreenSize.width());
    ui->childWidget->setFixedHeight(canvasScreenSize.height());
    ui->childWidget->setStyleSheet("background-color: white");

    objectx = (canvasScreenSize.width() / map->width);
    objecty = (canvasScreenSize.height() / map->height);

    std::cout << "objectx y " << objectx << ' ' << objecty << std::endl;

    this->showFullScreen();
}

EditMapWindow::~EditMapWindow(){
    delete ui;
    delete map;
    map = NULL;
}

void EditMapWindow::setButtonPosition(QAbstractButton & button, int x, int y) {
    int ButtonWidth = button.geometry().width();
    int ButtonHeight = button.geometry().height();
    button.setGeometry(x, y, ButtonWidth, ButtonHeight);
}

void EditMapWindow::on_obstacleButton_clicked(){
    selected = Values::OBSTACLE;
}

void EditMapWindow::on_noneButton_clicked()
{
    selected = Values::EMPTY;
}

void EditMapWindow::on_saveMapButton_clicked(){
    map->saveMap();
}


void EditMapWindow::mousePressEvent(QMouseEvent * event){
    if(event->pos().x() < Values::DRAWWIDTH){
       if(selected < 0){
           return;
        }

        if(selected == Values::LINE || selected == Values::RECTANGLE || selected == Values::CIRCLE){
            lineBeginning.setX((event->pos().x() - (event->pos().x() % objectx)) / objectx);
            lineBeginning.setY((event->pos().y() - (event->pos().y() % objecty)) / objecty);
            return;
        }
        const int positionx = (event->pos().x() - (event->pos().x() % objectx)) / objectx;
        const int positiony = (event->pos().y() - (event->pos().y() % objecty)) / objecty;

        std::cout << "coordinates: " << '(' << positionx << " " << positiony << ')' << std::endl;

        if(positionx < map->width  &&  positiony < map->height){
            map->setMapObject(selected, positiony, positionx);
            update();
            mousePressed = true;
        }
    }
}
void EditMapWindow::drawLine(QPoint begin, QPoint end){
    if(begin == end){
        map->setMapObject(selected, begin.y(), begin.x());
        return;
    }
    end.setX((end.x() - (end.x() % objectx)) / objectx);
    end.setY( (end.y() - (end.y() % objecty)) / objecty);
    if(begin.x() > end.x()){
        QPoint p = begin;
        begin = end;
        end = p;
    }
    if(begin.x() == end.x()){ // Vertical line
        if(begin.y() > end.y()){
            QPoint p = begin;
            begin = end;
            end = p;
        }
        std::cout << "same X"<< std::endl;
        int positionx = begin.x();
        std::cout << "x:" << positionx << std::endl;
        for(int i = begin.y(); i < end.y()+1; i++){
            std::cout << begin.y() << " - " << end.y() << " - " <<end.x() << " - " << begin.x() << std::endl;
            map->setMapObject(selected, i, positionx);
            update();
            mousePressed = true;
        }
    }
    else{
        //Y = Ax + B
        int deltaX =  (begin.x() - end.x());
        int deltaY =  (begin.y() - end.y());
        double a = (double)deltaY/deltaX;
        double b = (begin.y() - (a * begin.x()));
        std::cout << "Y = " << a <<"X + " << b<< std::endl;
        std::cout << begin.y() << " - " << end.y() << " - " << begin.x() << " - " << end.x()<< std::endl;
        std::cout << deltaX << " + " << deltaY << std::endl;
        for(int x = begin.x(); x < end.x()+1; x++){
            int y = (a * x) + b;
            map->setMapObject(selected, y, x);
            update();
            mousePressed = true;
        }
        if(begin.y() > end.y()){
            QPoint p = begin;
            begin = end;
            end = p;
        }
        for(int y = begin.y(); y < end.y()+1; y++){
            int x = (y-b)/a;
            map->setMapObject(selected, y, x);
            update();
            mousePressed = true;
        }
    }
}
void EditMapWindow::drawRectangle(QPoint begin, QPoint end){
    std::cout << "drawRect " << begin.x() << " - " << begin.y() << " - " << end.x() << " - " << end.y()<< std::endl;
    if(begin.x() == end.x() || begin.y() == end.y()){
        drawLine(begin,end);
    }
    else{
        int startX = begin.x();
        int endX =(end.x() - (end.x() % objectx)) / objectx;
        int startY = begin.y();
        int endY = (end.y() - (end.y() % objecty)) / objecty;
        std::cout << startX << " + " << startY << " + " <<endX << " + " << endY << std::endl;
        if(startX> endX){
            int i = startX;
            startX = endX;
            endX = i;
        }
        if(startY> endY){
            int i = startY;
            startY = endY;
            endY = i;
        }
        std::cout << startX << " + " << startY << " + " <<endX << " + " << endY << std::endl;

        for(int y = startY; y < endY; ++y){
            for(int x = startX; x < endX; ++x){
                 map->setMapObject(selected, y, x);
                 update();
                 mousePressed = true;
            }
        }
    }
}
void EditMapWindow::drawCircle(QPoint center, QPoint second){

    int endX =(second.x() - (second.x() % objectx)) / objectx;
    int endY = (second.y() - (second.y() % objecty)) / objecty;

    double radius = sqrt(pow(center.x() - endX, 2) + pow(center.y() - endY,2));
    std::cout << radius << std::endl;
    for (double angle=0; angle<=2*M_PI; angle+=0.001){
         map->setMapObject(selected, (center.y() + radius *sin( angle )), ( center.x() + radius*cos( angle ) ));
         update();
         mousePressed = true;
    }
}
bool EditMapWindow::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->childWidget && event->type() == QEvent::Paint) {
        QPainter painter;
        painter.begin(ui->childWidget);
        for(Map::Object & object : map->getMapContent()){

            painter.fillRect((object.X*objectx),(object.Y*objecty),objectx,objecty,QBrush(getColorById(object.id)));
        }
        std::cout << "paint event" << std::endl;
        painter.end();
        return true; // return true if you do not want to have the child widget paint on its own afterwards, otherwise, return false.
    }
   return false;
}

void EditMapWindow::mouseReleaseEvent(QMouseEvent * event){
    std::cout << "release\n"<< std::endl;
    if(selected == Values::LINE){
        std::cout << "drawLine" << std::endl;
        drawLine(lineBeginning, event->pos());
    }
    else if(selected ==Values::RECTANGLE){
        drawRectangle(lineBeginning, event->pos());
    }
    else if(selected == Values::CIRCLE){
        drawCircle(lineBeginning, event->pos());
    }
}
Qt::GlobalColor EditMapWindow::getColorById(int id){
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
    case 4:
        bColor = Qt::red;
    break;
    case 5:
        bColor = Qt::red;
    break;
    case 6:
        bColor = Qt::red;
    break;
    default:
        bColor = Qt::black;
    break;
    }
    return bColor;
}

void EditMapWindow::on_lineButton_clicked()
{
        selected = Values::LINE;
}

void EditMapWindow::on_rectangleButton_clicked()
{
        selected = Values::RECTANGLE;
}

void EditMapWindow::on_circleButton_clicked()
{
    selected  = Values::CIRCLE;
}

