/**
 * @file mainwindow.h
 * @author Coen Andriessen
 * @version 1.3
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include <QTableWidgetItem>
#include <QWidget>
#include <QApplication>
#include <stdio.h>
#include <iostream>

#include "Map.h"
#include "Rosbee.h"
#include "mapcanvas.h"
#include "ui_mainwindow.h"
#include "scanArea.h"

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
    // Constructor of MainWindow.
    explicit MainWindow(Map * map, Rosbee * rosbee, scanArea * scanarea, QWidget *parent = 0);
    // Destructor of MainWindow.
    ~MainWindow();
private slots:
    // Slot for saving a map.
    void saveMap();
    // Slot for loading a map.
    void loadMap();
    // Slot for closing a map.
    void closeMap();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QAction *newAct;
    QAction *loadAct;
    QAction *saveAct;
    QAction *closeAct;
    Map *map;
    Rosbee *rosbee;
    mapCanvas *mapcanvas;
    scanArea * scanarea;
};

#endif // MAINWINDOW_H
