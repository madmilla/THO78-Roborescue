#include "grid.h"
#include <QGraphicsObject>

grid::grid(int xSize, int ySize, int distanceBetweenLines QGraphicsItem *parent = 0):
    QGraphicsObject(parent)
{

}

void grid::addGrid(int distanceBetweenLines){
    for(int i=0; i<xSize; i+=distanceBetweenLines){
        grid.append(scene->addLine(i,0,i,ySize));
    }
    for(int i=0; i<ySize; i+=distanceBetweenLines){
        grid.append(scene->addLine(0,i,xSize,i));
    }
}

void grid::removeGrid(){
    foreach( QGraphicsItem *item, grid ) {
       delete item;
    }
}

