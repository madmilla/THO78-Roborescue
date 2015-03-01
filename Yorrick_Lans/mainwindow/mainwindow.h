#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "cell.h"
#include "map.h"

namespace Ui{
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void currentCellChanged(int xNew, int yNew, int xOld, int yOld);
    void waterButtonPressed();
    void concreteButtonPressed();
    void grassButtonPressed();
    void wallButtonPressed();
    void emptyButtonPressed();
    void quadButtonPressed();
    void ATVButtonPressed();
    void rosbeeButtonPressed();
   // void saveFile();
    //void loadFile();

private:
    void connectAllSlots();
    Ui::MainWindow *ui;
    cell *activeCell;
    map *activeMap;
};

#endif
