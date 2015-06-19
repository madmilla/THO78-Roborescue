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
//    painter.setFont(QFont("Arial", 30));
//    painter.drawText(QPointF(0,30), tr("hi"));

    if(pf == nullptr) return;

    std::vector<MapItem> & mapitems = pf->getMap().getMapItems();
    for(MapItem & mi : mapitems){
      painter.drawPolygon(convertToQPolygonF(mi));
    }

    if(pf->getPath() == nullptr) return;
    drawNode(painter, pf->getPath());
}

void Display::drawNode(QPainter & painter, Node * node){
   if(node == nullptr) return;

   if(node->isDeath()){
      painter.setPen(Qt::red);
   }else{
      painter.setPen(Qt::green);
   }
   painter.drawEllipse(convertToQPointF(node->getPosition()), 2, 2);
   if(!node->isDeath()){
      painter.setPen(Qt::black);
      painter.drawLine(convertToQPointF(node->getPosition()), convertToQPointF(node->getChild(Node::Direction::Left)->getPosition()));
      painter.drawLine(convertToQPointF(node->getPosition()), convertToQPointF(node->getChild(Node::Direction::Right)->getPosition()));
      painter.drawLine(convertToQPointF(node->getPosition()), convertToQPointF(node->getChild(Node::Direction::Straigth)->getPosition()));

      drawNode(painter, node->getChild(Node::Direction::Left));
      drawNode(painter, node->getChild(Node::Direction::Right));
      drawNode(painter, node->getChild(Node::Direction::Straigth));
   }
}

QPointF Display::convertToQPointF(const Vector<float> p){
   return QPointF(p.x + translation.x, p.y + translation.y);
}

QPolygonF Display::convertToQPolygonF(const MapItem & mi){
   QVector<QPointF> vector;
   for(Vector<float> v : mi){
      vector.append(convertToQPointF(v));
   }
   return QPolygonF(vector);
}
