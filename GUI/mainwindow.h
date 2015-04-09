#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "rosbee.h"
#include "lidar.h"
#include "atv.h"
#include "quadcopter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Quadcopter * quadcopter, Rosbee * rosbee, lidar * l, ATV * atv, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleButton();

private:
    Ui::MainWindow *ui;

    std::vector<QMainWindow *> subWindows;

    Rosbee * rosbee;
    lidar * l;
    ATV * atv;
    Quadcopter * quad;

    void checkZombies();
};

#endif // MAINWINDOW_H
