#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "rosbee.h"
#include "lidar.h"

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
    void handleButton();

private:
    Ui::MainWindow *ui;

    std::vector<QMainWindow *> subWindows;

    Rosbee * rosbee;
    lidar * lidar;

    void checkZombies();
};

#endif // MAINWINDOW_H
