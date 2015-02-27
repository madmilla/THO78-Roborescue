#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtGui>
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
