/**
 * @file mapCanvas.cpp
 * @author Coen Andriessen
 * @version 1.3
 */

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
    int *tmp =new int;
    *tmp=2;
    map->setTile(x, y, tmp);
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
