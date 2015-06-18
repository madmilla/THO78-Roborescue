#include "mapcanvas.h"

#include <iostream>
#include <QPainter>

QColor MapCanvas::COLOR_OBJECT(255, 0, 0, 255);
QColor MapCanvas::COLOR_FREE(0, 255, 0, 255);
QColor MapCanvas::COLOR_QUADCOPTER(0, 0, 255, 255);
QColor MapCanvas::COLOR_ATV(255, 255, 0, 255);
QColor MapCanvas::COLOR_QUADCOPTERROUTE(255, 153, 0, 255);
QColor MapCanvas::COLOR_ATVROUTE(255, 0, 153, 255);
QColor MapCanvas::COLOR_ROUTEBEGIN(153, 0, 255, 255);
QColor MapCanvas::COLOR_ROUTEEND(255, 255, 153, 255);


MapCanvas::MapCanvas(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);
}

void MapCanvas::paintEvent(QPaintEvent * /* event */)
{
    int blockWidth = this->width()/Map::MAP_WIDTH;
    int blockHeight = this->height()/Map::MAP_HEIGHT;

    QPainter painter(this);
    QColor color;
    for(int x = 0; x < Map::MAP_WIDTH; x++){
        for(int y = 0; y < Map::MAP_HEIGHT; y++){
            QRect rect(x*blockWidth, y*blockHeight, blockWidth, blockHeight);
            if(map->get(x,y) == map->object::object){
                color = COLOR_OBJECT;
            }
            else if(map->get(x,y) == map->object::empty){
                color = COLOR_FREE;
            }
            else if(map->get(x,y) == map->object::quadcopter){
                color = COLOR_QUADCOPTER;
            }
            else if(map->get(x, y) == map->object::atv){
                color = COLOR_ATV;
            }
            else if(map->get(x,y) == map->object::quadcopterRoute){
                color = COLOR_QUADCOPTERROUTE;
            }
            else if(map->get(x,y) == map->object::atvRoute){
                color = COLOR_ATVROUTE;
            }
            else if(map->get(x,y) == map->object::routeBegin){
                color = COLOR_ROUTEBEGIN;
               // startBlock = true; /future use
            }
            else if(map->get(x, y) == map->object::routeEnd){
                color = COLOR_ROUTEEND;
            }

            painter.fillRect(rect, color);
        }
    }
}

// future use
//void MapCanvas::mousePressEvent(QMouseEvent * event ){
//    int blockWidth = this->width()/Map::MAP_WIDTH;
//    int blockHeight = this->height()/Map::MAP_HEIGHT;
//    int value;

//    int x = event->x()/blockWidth;
//    int y = event->y()/blockHeight;
//    if(x >= Map::MAP_WIDTH || y >= Map::MAP_HEIGHT){
//        return;
//    }
//    if(event->button() == Qt::LeftButton){
//        if(!startBlock){
//            startBlock = true;
//        }
//        value = Map::BLOCK;
//    }
//    if(event->button() == Qt::MiddleButton){
//        value = Map::QUAD;
//    }
//    if(event->button() == Qt::RightButton){
//        value = Map::FREE;
//    }
//    map->set(x, y, value);
//    this->update();
//}

void MapCanvas::setMap(Map * map) {
    this->map = map;
}
