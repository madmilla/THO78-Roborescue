#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
}

QPointF MainWindow::convertToQPointF(const Vector<float> p){
   return QPointF(p.x, p.y);
}

QPolygonF MainWindow::convertToQPolygonF(const MapItem mi){
   QVector<QPointF> vector;
   for(Vector<float> v : mi){
      vector.append(convertToQPointF(v));
   }
   return QPolygonF(vector);
}
