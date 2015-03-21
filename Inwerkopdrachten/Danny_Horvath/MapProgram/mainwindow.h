#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "mapdisplay.h"

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
    void on_LoadFile_triggered();

    void on_NewFile_triggered();

    void on_LoadMap_clicked();

private:
    Ui::MainWindow *ui;
    QString map;
    MapDisplay *m = new MapDisplay();
};

#endif // MAINWINDOW_H
