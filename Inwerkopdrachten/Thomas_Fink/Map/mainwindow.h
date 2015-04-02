#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
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

private:
    Ui::MainWindow *ui;
    Map * map;

    void loadMapList();
private slots:
   void on_loadButton_clicked();
   void on_createEmptyMapButton_clicked();
   void on_deleteButton_clicked();

};
#endif // MAINWINDOW_H
