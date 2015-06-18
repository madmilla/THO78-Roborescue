#include "mainwindow.h"
#include "testperformance.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //TestPerformance::test();
    return a.exec();
}
