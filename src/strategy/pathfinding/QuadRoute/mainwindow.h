#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "mapcanvas.h"
#include "quadroute.h"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void newFile();
    void open();
    void save();

    void createRoute();

private:
    void createActions();
    void createMenus();

    Map *map;
    MapCanvas *mapCanvas;
    Quadroute *quadroute;

    QMenu *fileMenu;
    QMenu *runMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *createRouteAct;
};

#endif
