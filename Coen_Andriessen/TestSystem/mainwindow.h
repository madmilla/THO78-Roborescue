#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QGraphicsScene>
#include <QtGui>
#include <QTableWidgetItem>
#include <QWidget>
#include "Map.h"

namespace Ui {
class MainWindow;
}

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showMap();
private slots:
    void saveMap();
    void loadMap();
    void closeMap();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QAction *newAct;
    QAction *loadAct;
    QAction *saveAct;
    QAction *closeAct;
    Map *map;
};

#endif // MAINWINDOW_H
