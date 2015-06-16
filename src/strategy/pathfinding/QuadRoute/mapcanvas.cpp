/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mapcanvas.cpp
* @date Created: 4/7/2015
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

#include "mapcanvas.h"

#include <iostream>
#include <QPainter>

QColor MapCanvas::COLOR_BLOCK(255, 0, 0, 255);
QColor MapCanvas::COLOR_FREE(0, 255, 0, 255);
QColor MapCanvas::COLOR_QUAD(0, 0, 255, 255);
QColor MapCanvas::COLOR_FINISH(255, 255, 0, 255);
QColor MapCanvas::COLOR_ROUTE(255, 153, 0, 255);

/**
 * Basic constructor, creates the colors of the window.
 * */
MapCanvas::MapCanvas(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);
}

/**
 * This method gives the different objects their own color.
 * */
void MapCanvas::paintEvent(QPaintEvent * /* event */)
{
    int blockWidth = this->width()/Map::MAP_WIDTH;
    int blockHeight = this->height()/Map::MAP_HEIGHT;

    QPainter painter(this);
    QColor color;
    for(int x = 0; x < Map::MAP_WIDTH; x++){
        for(int y = 0; y < Map::MAP_HEIGHT; y++){
            QRect rect(x*blockWidth, y*blockHeight, blockWidth, blockHeight);
            if(map->get(x,y) == Map::BLOCK){
                color = COLOR_BLOCK;
            }
            else if(map->get(x,y) == Map::FREE){
                color = COLOR_FREE;
            }
            else if(map->get(x,y) == Map::QUAD){
                color = COLOR_QUAD;
            }
            else if(map->get(x,y) == Map::FINISH){
                color = COLOR_FINISH;
            }
            else if(map->get(x,y) == Map::ROUTE){
                color = COLOR_ROUTE;
            }
            painter.fillRect(rect, color);
        }
    }
}

/**
 * This method handles the mouse events when someone clicks a button on the mouse.
 * */
void MapCanvas::mousePressEvent(QMouseEvent * event ){
    int blockWidth = this->width()/Map::MAP_WIDTH;
    int blockHeight = this->height()/Map::MAP_HEIGHT;
    int value;

    int x = event->x()/blockWidth;
    int y = event->y()/blockHeight;
    if(x >= Map::MAP_WIDTH || y >= Map::MAP_HEIGHT){
        return;
    }
    if(event->button() == Qt::LeftButton){
        value = Map::BLOCK;
    }
    if(event->button() == Qt::MiddleButton){
        value = Map::QUAD;
    }
    if(event->button() == Qt::RightButton){
        value = Map::FREE;
    }
    map->set(x, y, value);
    this->update();
}

/**
 * This method sets the variable map from the file map.cpp to the locale variable map.
 * */
void MapCanvas::setMap(Map * map) {
    this->map = map;
}
