#include "display.h"

#include <QPainter>
#include <thread>

Display::Display(QWidget *parent) : QWidget(parent), timer(new QTimer()), executeRunning(false)
{
   timer->setSingleShot(false);
   timer->setInterval(100);

   connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
}

Display::~Display(){
   delete timer;
}

void Display::setStartPoint(QPointF startPoint) {
   this->startPoint = startPoint;
   this->repaint();
}
void Display::setStopPoint(QPointF stopPoint) {
   endPoint = stopPoint;
   this->repaint();
}

void Display::execute(){
   if(pf != nullptr && !executeRunning){
      executeRunning = true;
      timer->start();

      std::thread t(&Display::executeTask, this);
      t.detach();
   }
}
void Display::executeTask(){
   Vector<float> startP{startPoint.x(), startPoint.y()};
   Vector<float> endP{endPoint.x(), endPoint.y()};

   pf->find(startP, endP);
   executeRunning = false;
}

void Display::pushMapItem(){
   if(pf != nullptr && tempMapItem.pointCount() > 1){
      pf->getMap().addItem(tempMapItem);
      this->repaint();
   }
}

void Display::cancelMapItem() {
   tempMapItem = MapItem();
   this->repaint();
}
MapItem & Display::getTempMapItem() {
   return tempMapItem;
}


void Display::paintEvent(QPaintEvent *){
   if(executeRunning == false && timer->isActive()){
      timer->stop();
      emit executeDone();
   }
    QPainter painter(this);
    painter.setPen(Qt::blue);

    if(pf == nullptr) return;

    std::vector<MapItem> & mapitems = pf->getMap().getMapItems();
    for(MapItem & mi : mapitems){
      painter.drawPolygon(convertToQPolygonF(mi));
    }

    painter.drawPolygon(convertToQPolygonF(tempMapItem));

    painter.setPen(Qt::GlobalColor::magenta);
    painter.drawEllipse(QPointF(startPoint.x() + translation.x, startPoint.y() + translation.y), 4, 4);
    painter.drawEllipse(QPointF(endPoint.x() + translation.x, endPoint.y() + translation.y), 4, 4);

    if(pf->getPath() == nullptr) return;
    drawNode(painter, pf->getPath());
}

void Display::drawNode(QPainter & painter, Node * node){
   if(node == nullptr) return;
   node->setDrawing(true);

   if(node->isDeath()){
      painter.setPen(Qt::red);
   } else if(node->getChild(Node::Direction::Straigth) == nullptr){
      painter.setPen(Qt::yellow);
   }else{
      painter.setPen(Qt::green);
   }
   painter.drawEllipse(convertToQPointF(node->getPosition()), 2, 2);
   if(!node->isDeath() && node->getChild(Node::Direction::Straigth) != nullptr){
      painter.setPen(Qt::black);
      painter.drawLine(convertToQPointF(node->getPosition()), convertToQPointF(node->getChild(Node::Direction::Left)->getPosition()));
      painter.drawLine(convertToQPointF(node->getPosition()), convertToQPointF(node->getChild(Node::Direction::Right)->getPosition()));
      painter.drawLine(convertToQPointF(node->getPosition()), convertToQPointF(node->getChild(Node::Direction::Straigth)->getPosition()));

      drawNode(painter, node->getChild(Node::Direction::Left));
      drawNode(painter, node->getChild(Node::Direction::Right));
      drawNode(painter, node->getChild(Node::Direction::Straigth));
   }

   node->setDrawing(false);
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

void Display::mousePressEvent(QMouseEvent*){

}

void Display::mouseReleaseEvent(QMouseEvent* event){
   if(event->button() == Qt::LeftButton){
      QPointF pos{translation.x + event->pos().x(), translation.y + event->pos().y()};
      emit clicked(pos);
   }
}
