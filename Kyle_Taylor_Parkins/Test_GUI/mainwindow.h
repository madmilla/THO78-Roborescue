#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mapping.h"

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

    void on_actionAbout_triggered();

    void on_actionLoad_triggered();

private:
    Qt::GlobalColor convertColor(int value);
    Ui::MainWindow *ui;
    static const int columnSize = 20, rowSize = 20;
};

#endif // MAINWINDOW_H
