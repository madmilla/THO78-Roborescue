#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "editmapwindow.h"
#include "simulatemapwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //!The Contructor for the MainWindow
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //! Used when the NewMap button gets clicked
    void on_newMapButton_clicked();
    //! Used when the editMap button gets clicked
    void on_editMapButton_clicked();
    //! Used when the Simulate button gets clicked
    void on_simulateButton_clicked();

private:
    Ui::MainWindow *ui;
    Map *map;
    EditMapWindow* editMapWindow;

    int newMapBeignSize = 100;//Default begin size
    int newMapMinSize = 10;// Minimal size of a map
    int newMapMaxSize = 100;//Maximal size of a map
    int newMapStepSize = 10;//Step size if you use the arrows
};

#endif // MAINWINDOW_H
