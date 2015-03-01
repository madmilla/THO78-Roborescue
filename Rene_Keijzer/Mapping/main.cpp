#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    if(argc > 1 && strcmp("-t", argv[1]) == 0){
        Map map("map.dat");
        if(map.width() != 20 && map.height() != 20){
            std::cout << "Map 20x20 Didn't load correctly";
            return 1;
        }

        Map map1("map1.dat");
        if(map1.width() != 5 && map1.height() != 5){
            std::cout << "Map 5x5 Didn't load correctly";
            return 1;
        }

        Map map2("map2.dat");
        if(map2.width() != 0 && map2.height() != 0){
            std::cout << "Map 0x0 Didn't load correctly";
            return 1;
        }
    return 0;
    }else{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    }
}
