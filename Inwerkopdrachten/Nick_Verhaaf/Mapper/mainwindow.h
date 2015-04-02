#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "editor.h"

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
    void on_newMap_clicked();

    void on_loadMap_clicked();

private:
    Ui::MainWindow *ui;
    QString map;
    Editor *editMap = new Editor();
};

#endif // MAINWINDOW_H
