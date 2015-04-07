#include "mainwindow.h"
//#include "quadcopterwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QuadCopterWindow q;
    //q.show();

    return a.exec();
}
