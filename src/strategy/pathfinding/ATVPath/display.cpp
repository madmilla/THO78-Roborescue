#include "display.h"

#include <QPainter>

Display::Display(QWidget *parent) : QWidget(parent)
{

}

Display::~Display()
{

}

void Display::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(QPointF(0,30), tr("hi"));
}
