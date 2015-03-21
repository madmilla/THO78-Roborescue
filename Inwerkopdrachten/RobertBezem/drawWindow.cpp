#include "drawWindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QList>
#include <QGraphicsItem>
drawWindow::drawWindow(int xSize, int ySize,QWidget *parent) :
    QWidget(parent),
    xSize(xSize),
    ySize(ySize)
{
    // Set size of the window
    setFixedSize(xSize,ySize);
    scene = new QGraphicsScene(0,0,xSize,ySize);
    graphicsview = new QGraphicsView(scene,this);
    graphicsview->setRenderHint(QPainter::Antialiasing);
    graphicsview->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

}

void drawWindow::toggleGrid(int distanceBetweenLines){
    if(grid.size()==0){
        addGrid(distanceBetweenLines);
    }else{
        removeGrid();
    }
}

void drawWindow::addGrid(int distanceBetweenLines){
    for(int i=0; i<xSize; i+=distanceBetweenLines){
        grid.append(scene->addLine(i,0,i,ySize));
    }
    for(int i=0; i<ySize; i+=distanceBetweenLines){
        grid.append(scene->addLine(0,i,xSize,i));
    }
}

void drawWindow::removeGrid(){
    foreach( QGraphicsItem *item, grid ) {
       grid.removeOne(item);
       delete item;
    }
}
