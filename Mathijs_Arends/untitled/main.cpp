#include "mainwindow.h"
#include <QApplication>
#include "widget.h"
#include "loader.h"
int main(int argc, char *argv[])
{
    Loader lod;
    QApplication a(argc, argv);

    //Map map= lod.getMap("map.txt");
    //map.print();

    Widget widget;
    MainWindow w(&widget);
    w.setFixedSize(480,480);
    w.show();
    widget.setFixedSize(480,480);
    w.setCentralWidget(&widget);
    return a.exec();
}
