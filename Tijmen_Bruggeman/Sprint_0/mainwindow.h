#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "mapEditor.h"
#include <QTextStream>
#include "map.h"
#include <iostream>
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
    void on_Load_map_clicked();

    void on_Show_map_clicked();

    void on_NewButton_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::MainWindow *ui;
    MapEditor * mapEditor = new MapEditor();
};

#endif // MAINWINDOW_H
