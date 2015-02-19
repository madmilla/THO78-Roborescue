#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{

    std::cout << "Hello world, this is a testapplication!";

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
