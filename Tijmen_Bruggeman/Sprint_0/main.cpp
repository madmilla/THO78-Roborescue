#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "start";
    w.show();
    return a.exec();
}
