#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;


    window.setWindowTitle(QApplication::translate("het inwerk","Het inwerk project"));

    //map(window);
    window.show();

    return a.exec();
}

