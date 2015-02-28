#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapwindow.h"

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

    void on_dial_sliderMoved(int position);

    void on_actionNew_Grid_triggered();

    void on_actionLoad_triggered();

    void on_actionOptions_triggered();

private:
    Ui::MainWindow *ui;
    int oldValue = 0;
    MapWindow *mpWindow;
    QString filename;
};

#endif // MAINWINDOW_H
