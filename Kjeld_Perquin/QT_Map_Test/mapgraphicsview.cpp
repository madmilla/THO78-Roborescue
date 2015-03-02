#include "mapgraphicsview.h"
#include <QWheelEvent>

MapGraphicsView::MapGraphicsView(QWidget* parent):
    QGraphicsView(parent),
    scene( new QGraphicsScene(this) )
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setScene(scene);
    setDragMode(ScrollHandDrag);
}

void MapGraphicsView::addItem(QGraphicsItem *item)
{
    scene->addItem(item);
    update();
}

void MapGraphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    if(event->delta() > 0)
    {
        scale(scaleFactor,scaleFactor);
    }
    else
    {
        scale(1.0/scaleFactor, 1.0/scaleFactor);
    }
}
