#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include "Mapping.h"

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
    void on_actionLoad_map_triggered();

    void on_actionExit_triggered();

    void on_actionSave_map_triggered();

    void on_freeButton_clicked();

    void on_quadcopterButton_clicked();

    void on_rosbeeButton_clicked();

    void on_atvButton_clicked();

    void on_wallButton_clicked();

private:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent * mouseEvent);
    Ui::MainWindow *ui;
    Mapping map;
    static const int recSize = 15;
};

#endif // MAINWINDOW_H
