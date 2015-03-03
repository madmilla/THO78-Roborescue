#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QString>
#include <QFileDialog>
#include <QTableWidget>
#include "mapBack.h"
//#include "mapio.h"


class QAction;
class QActionGroup;
class QMenu;
//class mapio;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void newFile();
    void open();
    void save();
    void exit();
    void insAtv();
    void insRosbee();
    void insDrone();

private:
    void createActions();
    void createMenus();
    void displayMap();
    QMenu* fileMenu;
    QMenu* addObjMenu;
    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* closeAction;
    QAction* addRosbee;
    QAction* addAtv;
    QAction* addDrone;

    QTableWidget* mapTableWidget;

    mapBack* mb;
    QString filename;
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
