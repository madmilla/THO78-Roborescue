#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "item.h"
#include "map.h"
#include <QFileDialog>
#include <QTextStream>

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
    void on_Water_on_clicked(bool checked);
    void on_actionExit_triggered();
    void on_Object_on_clicked(bool checked);
    void on_Grass_on_clicked(bool checked);
    void on_QuadCopter_on_clicked(bool checked);
    void on_Rosbee_on_clicked(bool checked);
    void on_Atv_on_clicked(bool checked);
    void on_None_on_clicked(bool checked);
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void savefile(const QString &name);

    void on_actionLoad_triggered();

private:
    bool quadCopter = false;
    bool atv = false;
    bool rosbee = false;
    void MainWindow::loadFile();
    //bool quadCopter = false;
    int quadX, quadY;
    //bool atv = false;
    int atvX, atvY;
    //bool rosbee = false;
    int rosbeeX, rosbeeY;
    QString saveFile;
    QString fileName;

    Ui::MainWindow *ui;
    item * activeGrid;
    map * activemap;
};

#endif // MAINWINDOW_H
