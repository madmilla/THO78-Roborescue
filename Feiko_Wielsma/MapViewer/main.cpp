#include "mainwindow.h"
#include <QApplication>
#include "mapsystem.h"

int main(int argc, char *argv[])
{
    MapSystem * mapSystem = new MapSystem;
    QApplication a(argc, argv);
    MainWindow w (mapSystem);
    w.show();
    delete mapSystem;

    return a.exec();
}
