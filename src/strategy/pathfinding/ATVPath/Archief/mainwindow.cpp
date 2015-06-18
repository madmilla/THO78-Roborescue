#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   Map * map = new Map();
   MapItem mi;
   mi.addPoint(Vector<float>());
   mi.addPoint(Vector<float>(5, 0));
   mi.addPoint(Vector<float>(5, 5));
   mi.addPoint(Vector<float>(0, 5));
   map->addItem(mi);
   PathFinding * pf = new PathFinding(30, Vector<float>(10, 20), *map);
   ui->display->setPathFinding(*pf);
   qDebug() << "Hi0?";
   pf->find(Vector<float>(20, 20), Vector<float>(500, 200));
   qDebug() << "Hi2?";

}

MainWindow::~MainWindow()
{
   delete &ui->display->getPathFinding()->getMap();
   delete ui->display->getPathFinding();
   delete ui;
}
