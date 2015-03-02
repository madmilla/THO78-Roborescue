#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "maplogic.h"
#include <iostream>
#include <QMainWindow>
#include <QtGui>
#include <QDialog>
#include <QtCore>
#include <QCursor>

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
