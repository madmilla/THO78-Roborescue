#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    if(argc > 1 && argv[1] == "-t"){
        Map map("map.dat");
        if(map.width() != 20 && map.height() != 20){
            std::cout << "Map 20x20 Didn't load correctly";
        }

        Map map("map1.dat");
        if(map.width() != 5 && map.height() != 5){
            std::cout << "Map 5x5 Didn't load correctly";
        }

        Map map("map2.dat");
        if(map.width() != 0 && map.height() != 0){
            std::cout << "Map 0x0 Didn't load correctly";
        }

    }else{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    }
}
