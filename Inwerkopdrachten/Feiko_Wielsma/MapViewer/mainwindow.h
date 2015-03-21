#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapviewer.h"
#include "mapsystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(MapSystem* mapSystem, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_emptyButton_clicked();

    void on_wallButton_clicked();

    void on_treeButton_clicked();

    void on_quadButton_clicked();

    void on_atvButton_clicked();

    void on_actionNew_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;
    MapSystem* mapSystem;
    void enableRadioButtons(bool);
};

#endif // MAINWINDOW_H
