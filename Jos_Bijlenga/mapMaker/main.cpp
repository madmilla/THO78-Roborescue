#include "mainwindow.h"
#include <QApplication>
#include "mapLogic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mapLogic *logic = new mapLogic();
    delete logic;

    MainWindow w;
    w.show();

    return a.exec();
}
