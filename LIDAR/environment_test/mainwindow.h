#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "editmapwindow.h"

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
    void on_newMapButton_clicked();

    void on_editMapButton_clicked();

    void on_simulateButton_clicked();

private:
    Ui::MainWindow *ui;
    Map *map;
    EditMapWindow* editMapWindow;
};

#endif // MAINWINDOW_H
