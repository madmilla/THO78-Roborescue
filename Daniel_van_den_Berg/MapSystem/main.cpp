#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{

    std::cout << "Hello world, this is a testapplication!\n";
    try{
        QApplication a(argc, argv);
        std::cout << "This program ran on a pc with screen. \n";
        MainWindow w;
        w.show();
        return a.exec();
    }catch(...){
        std::cout << "This program ran on a pc without screen. (Or an exception occured for some other reason, I've got no idea.)\n";
        return 0;
    }
}
