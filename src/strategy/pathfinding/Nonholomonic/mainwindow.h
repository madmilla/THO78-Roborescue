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
   enum class Status{firstUse, setStart, setStop, setObstacel, None};
   Status status;

   void statusUpdate();
private slots:
   void buttonClicked();
   void fieldClicked(QPointF position);
   void executeDone();
};

#endif // MAINWINDOW_H
