#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{

    std::cout << "Hello world, this is a testapplication!\n";
    QApplication a(argc, argv);
    if (QApplication::desktop()->screenCount() >= 1){
        std::cout << "This program ran on a pc with screen. \n";
        MainWindow w;
        w.show();
        return a.exec();
    }else{
        std::cout << "This program ran on a pc without screen. \n";
    }
}
