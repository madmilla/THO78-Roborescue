#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "mapcanvas.h"

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

private:
    void createActions();
    void createMenus();

    Map *map;
    MapCanvas *mapCanvas;

    QMenu *fileMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
};

#endif
