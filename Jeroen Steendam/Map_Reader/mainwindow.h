#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mapwidget.h"

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
    void actionNew();
    void actionLoad();
    void actionSave();
    void actionSaveAs();
    void actionExit();
private:
    void newMap();
    void loadFile();
    void loadFile(const QString &fileName);
    void save();
    void saveFile();
    void saveFile(const QString &fileName);
    void exitProgram();
private:
    Ui::MainWindow *ui;
    MapWidget* mapWidget;

    Map* map = NULL;
    QString currentFileName;
};

#endif // MAINWINDOW_H
