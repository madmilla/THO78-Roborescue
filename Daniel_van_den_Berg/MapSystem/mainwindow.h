#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapeditor.h"

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
    void on_Load_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    MapEditor mapEditor = MapEditor();
    Ui::MainWindow *ui;
    void MainWindow::loadMaps();
};

#endif // MAINWINDOW_H
