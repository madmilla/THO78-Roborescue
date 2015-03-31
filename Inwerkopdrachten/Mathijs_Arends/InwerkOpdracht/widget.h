#ifndef WIDGET_H
#define WIDGET_H
#include <qpainter.h>
#include <QImage>
#include "map.h"
#include "object.h"
#include "loader.h"
#include "QFileDialog"
class Widget : public QWidget {

public:
  Widget() {

    if (logo.load("robologo.png")) {
      qWarning("loadgood");
    } else {
      qWarning("loadError");
    }
  }
 void getMap(Map map) { this->map = map; }
 void loadMap(){
     mapSelected=1;
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),"",tr("Files(*.*)"));
    Loader loader;
    map = loader.getMap(fileName);



 }
 void addObject(Object o){

     map.addObject(o);
     this->update();
 }
protected:
 bool mapSelected=0;
  void paintEvent(QPaintEvent *event) {
      if(mapSelected){
      if(event ==nullptr){}
      tilesize = height()/20;
    // QTransform myTransform;
    qWarning("warning");
    // myTransform.rotate(prev, Qt::ZAxis);
    // logo = logo.transformed(myTransform);
    QPainter painter(this);
    QRect rect(50, 50, 100, 100);
    painter.setBackgroundMode( Qt::OpaqueMode );
    painter.setBackground( QColor( Qt::gray ) );
    painter.setPen( QPen( Qt::black ) );
    painter.setBrush( QBrush( Qt::black, Qt::Dense5Pattern ) );
    // painter.drawLine(0, 0, 200, 200);
    for(Tile* t: map.tiles){
        QRect rectangle(t->x*tilesize, t->y*tilesize, tilesize,tilesize);

        if(t->type=='1'){painter.setBackgroundMode( Qt::OpaqueMode );
            painter.setBackground( QColor( Qt::gray ) );
            painter.setPen( QPen( Qt::black ) );
            painter.setBrush( QBrush( Qt::black, Qt::Dense5Pattern ) );}
        else{painter.setPen(Qt::white);
             painter.setBrush(QBrush(Qt::white, Qt::NoBrush));
        }

        painter.drawRect(rectangle);



    }
    for(Object o: map.objects){
        QRect rectangle(o.x, o.y, o.width,o.hight);
       painter.drawImage(rectangle, logo);

    }
	event = nullptr;



}}

private:
  int tilesize;
  Map map;
  QImage logo;
};

#endif // WIDGET_H
