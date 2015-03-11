#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtGui>
#include "ui_mainwindow.h"


#define MAX 20
#define FREE 0
#define OBSTACLE 1
#define ATW 2

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
    void loadButton();
    void clearButton();
    void saveButton();


    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

    void cellSelected(int nRow, int nCol);

private:
    Ui::MainWindow *ui;
    int MapObjects[MAX][MAX];
    QString filename;
    void showOnBoard();
    void printOnScreen(int x, int y, QColor color);
    void printAndSave(int x, int y, int color);
    int mode = 0;
   // QString checkType(QString character);


\



};

#endif // MAINWINDOW_H
