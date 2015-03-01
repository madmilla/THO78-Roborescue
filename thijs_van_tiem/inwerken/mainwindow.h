#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iostream"
#include "cells.h"
#include "map.h"


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
    void currentCellChanged(int xn, int yn, int xo, int yo);

    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_RadioEmpty_clicked(bool checked);

    void on_RadioQuad_clicked(bool checked);

    void on_RadioATV_clicked(bool checked);

    void on_RadioRosbee_clicked(bool checked);

    void on_RadioGreen_clicked(bool checked);

    void on_RadioConcrete_clicked(bool checked);

    void on_RadioWater_clicked(bool checked);

    void savefile(const QString &name);


private:
    Ui::MainWindow *ui;
    //cells * boolcel = new cells;
    cells * activecell; //pointer naar de actieve cel op dat moment
    map * activemap; // pointer na map zodat je getcell kan gebruiken

};

#endif // MAINWINDOW_H
