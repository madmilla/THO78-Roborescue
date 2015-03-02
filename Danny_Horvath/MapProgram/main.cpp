#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    if(argc >=1 && argv[1]== "-test"){
        std::cout << "this is a test";
    }
    else{
        QApplication a(argc, argv);
        MainWindow w;
        std::cout << "start";
        w.show();
        return a.exec();
    }
}
