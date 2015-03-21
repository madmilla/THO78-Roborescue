#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "maplogic.h"
#include <iostream>
#include <QMainWindow>
#include <QtGui>
#include <QDialog>
#include <QColor>
#include <QtCore>
#include <QCursor>

//const int EMPTY = 0;
//const int OBJECT = 1;
//const int COPTER = 2;
//const int WIDTH = 20;
//const int HEIGHT = 20;
//const int OFFSET = 20;

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
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;
    mapLogic * logic;

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
};

#endif // MAINWINDOW_H
