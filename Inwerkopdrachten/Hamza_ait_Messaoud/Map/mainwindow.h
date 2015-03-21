#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <stdlib.h>
#include "map.h"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void tableItemClicked(int row, int column);
    void open();
    void save();
    void newFile();

private:
    Ui::MainWindow *ui;
    Map map;
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QAction *exitAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *newAct;
};

#endif // MAINWINDOW_H
