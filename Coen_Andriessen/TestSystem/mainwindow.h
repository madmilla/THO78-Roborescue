#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void getMap(QString filename);
    void showMap();

private:
    Ui::MainWindow *ui;
    QString myMap[20][20];
    QString quadCopterLocationX;
    QString quadCopterLocationY;
    int xLength, yLength;
};

#endif // MAINWINDOW_H
