#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include "mappinglogic.h"
#include <QTableWidgetItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(MappingLogic * mapper,QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MappingLogic * mapper;
    void setItemColor(QTableWidgetItem * item,int status);
    void setCellstatus(int x, int y, int status);
    void LoadGrid();
private slots:
    void handleButton();
    void actionLoad();
    void actionSave();
    void actionExit();
};

#endif // MAINWINDOW_H
