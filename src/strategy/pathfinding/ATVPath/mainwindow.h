#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointF>
#include <QPolygonF>
#include "vector.h"
#include "mapitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

private:
   Ui::MainWindow *ui;

   QPointF convertToQPointF(const Vector<float> p);
   QPolygonF convertToQPolygonF(const MapItem mi);
protected:
   void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
