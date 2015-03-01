#include "mapcanvas.h"

#include <iostream>
#include <QPainter>

QColor MapCanvas::COLOR_BLOCK(0, 0, 0, 255);
QColor MapCanvas::COLOR_FREE(255, 255, 255, 255);
QColor MapCanvas::COLOR_QUAD(255, 0, 0, 255);

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
            if(map->get(x,y) == Map::BLOCK){
                color = COLOR_BLOCK;
            }
            else if(map->get(x,y) == Map::FREE){
                color = COLOR_FREE;
            }
            else if(map->get(x,y) == Map::QUAD){
                color = COLOR_QUAD;
            }
            painter.fillRect(rect, color);
        }
    }
}

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

void MapCanvas::setMap(Map * map) {
    this->map = map;
}
