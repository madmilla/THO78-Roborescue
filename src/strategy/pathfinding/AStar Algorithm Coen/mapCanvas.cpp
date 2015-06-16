/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file mapCanvas.cpp
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

#include "mapCanvas.h"

/**
 * Constructor of Map.
 *
 * @param parent
 */

mapCanvas::mapCanvas(QWidget *parent):
    QWidget(parent)
{
    //Constructor
    setAutoFillBackground(true);
}

/**
 * Destructor of Map.
 *
 * @param parent
 */

mapCanvas::~mapCanvas(){
    //Destructor
}

/**
 * Function to detect mouseclicks. For earch mouseclick on the map the selected tile
 * will be set to value 2.
 *
 * @param event
 */

void mapCanvas::mousePressEvent(QMouseEvent *event){
    int x = event->x()/map->blockWidth;
    int y = event->y()/map->blockHeight;
    map->setTile(x, y, "2");
}

/**
 * Function to paint the map. Map will be painted tile for tile.
 * The color of the tiles depents of which value has the tile.
 */

void mapCanvas::paintEvent(QPaintEvent *){
    QPainter painter(this);
    map->blockWidth = this->width()/20;
    map->blockHeight = this->height()/20;
    // For loops to loop trough the whole map.
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            QRect rect(map->blockWidth * iix, map->blockHeight * iiy, map->blockWidth , map->blockHeight);
            // Switch case to check which tile is selected.
            switch(map->getTile(iix, iiy)){
                // Scanned.
                case 1:
                    painter.fillRect(rect,Qt::yellow);
                    break;
                // Object.
                case 2:
                    painter.fillRect(rect,Qt::blue);
                    break;
                // Object.
                case 3:
                    painter.fillRect(rect,Qt::magenta);
                    break;
                case 4:
                    painter.fillRect(rect,Qt::black);
                    break;
                // Free tile.
                default:
                    painter.fillRect(rect, Qt::red);
                    break;
            }
            // Paint the rosbee.
            if(iiy == rosbee->getRosbeeLocationY() && iix == rosbee->getRosbeeLocationX()){
                painter.fillRect(rect,Qt::green);
            }
        }
    }
    // Paint the map again.
    this->update();
}

/**
 * Function to set the map.
 *
 * @param map
 */

void mapCanvas::setMap(Map * map){
    this->map = map;
}

/**
 * Function to set the rosbee.
 *
 * @param map
 */

void mapCanvas::setRosbee(Rosbee * rosbee){
    this->rosbee = rosbee;
}
