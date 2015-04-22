#ifndef WIDGET_H
#define WIDGET_H
#include <qpainter.h>
#include <QImage>
#include "map.h"
#include "object.h"
#include "loader.h"
#include "QFileDialog"
#include "cell.h"
#include "areacoveringalgorithm.h"
#include "arraymap.h"
class Widget : public QWidget {

public:
    void setArrayMap(ArrayMap* mapp){
        map=mapp;



    }
  Widget() {

    if (logo.load("robologo.png")) {
      qWarning("loadgood");
    } else {
      qWarning("loadError");
    }
  }
 //void getMap(Map map) { this->map = map; }
 void loadMap(){
     mapSelected=1;
    //QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),"",tr("Files(*.*)"));
    Loader loader;
    //map = loader.getMap(fileName);



 }
 void addObject(Object o){

     //map.addObject(o);
     this->update();
 }
protected:
 bool mapSelected=0;
  void paintEvent(QPaintEvent *event) {
      if(true){
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
    for(int i=0; i<map->data.size();i++){
        std::vector<int>* tmp = map->data.at(i);
        for(int ii=0; ii< tmp->size();ii++){
            int t = tmp->at(ii);
           QRect rectangle(i*10,ii*10,10,10);
        if(t==1){painter.setBackgroundMode( Qt::OpaqueMode );
            painter.setBackground( QColor( Qt::gray ) );
            painter.setPen( QPen( Qt::black ) );
            painter.setBrush( QBrush( Qt::black, Qt::Dense5Pattern ) );}
        else if(t==3){
            painter.setPen(Qt::red);
            painter.setBrush(QBrush(Qt::red, Qt::Dense1Pattern));

        }
        else{painter.setPen(Qt::white);
             painter.setBrush(QBrush(Qt::white, Qt::NoBrush));
        }

        painter.drawRect(rectangle);



    }}
    /*al.getCells(map);
    int index=0;
    for(Cell cell: al.cells){
        QColor color;
        if(index==0){color = Qt::red;}
        else if(index==1){color = Qt::blue;}
        else if(index==2){color = Qt::green;index=-1;}
        for(Tile* t: cell.tiles){
            QRect rectangle(t->x*tilesize, t->y*tilesize, tilesize,tilesize);

            painter.setBackgroundMode( Qt::OpaqueMode );
                painter.setBackground( color );
                painter.setPen( QPen( color ) );
                painter.setBrush( QBrush( Qt::black, Qt::Dense5Pattern ) );

            painter.drawRect(rectangle);




        }
        index++;


    }*/


}}

private:
  int tilesize;
  ArrayMap* map;
  QImage logo;
};

#endif // WIDGET_H
