#include "mainwindow.h"
#include <QApplication>
#inlcude "base.h"

int main(int argc, char *argv[])
{
    base *base = new base();
    delete base;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
