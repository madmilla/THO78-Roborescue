#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "rosbee.h"

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
    void buttonClicked();

private:
    Ui::MainWindow *ui;

    std::vector<QMainWindow *> subwindows;

    Rosbee * rosbee;
};

#endif // MAINWINDOW_H
