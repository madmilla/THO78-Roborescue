#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.hpp"
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
    void on_actionLoad_triggered();
    void tableItemClicked(int row, int column);

    void on_actionEdit_triggered();

    void on_actionExit_triggered();

    void on_actionSave_2_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;
    Map * map;
};

#endif // MAINWINDOW_H
