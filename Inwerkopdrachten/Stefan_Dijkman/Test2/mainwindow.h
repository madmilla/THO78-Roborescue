#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void on_actionExit_triggered();

    void on_actionOpen_File_triggered();

private:
    Ui::MainWindow *ui;
    map* gridWidget;
};

#endif // MAINWINDOW_H
