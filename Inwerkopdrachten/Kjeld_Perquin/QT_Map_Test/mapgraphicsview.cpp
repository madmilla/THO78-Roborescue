#include "mapgraphicsview.h"
#include <QWheelEvent>

MapGraphicsView::MapGraphicsView(QWidget* parent):
    QGraphicsView(parent)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setDragMode(ScrollHandDrag);
}

void MapGraphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    //If the mousewheel is scrolled upwards scale the view up
    if(event->delta() > 0)
    {
        scale(SCALE_FACTOR,SCALE_FACTOR);
    }
    //Otherwise scale it down
    else
    {
        scale(1.0/SCALE_FACTOR, 1.0/SCALE_FACTOR);
    }
    //DO NOT call the handler of the superclass because it's default behaviour
    //is to show scroll bars.
}
