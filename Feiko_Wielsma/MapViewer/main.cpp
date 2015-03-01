#include "mainwindow.h"
#include <QApplication>
#include "mapsystem.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if(argc > 1 && std::string(argv[1]) == "--test")
    {
        std::cout << "Console\n";
        MapSystem * mapSystem = new MapSystem;

        delete mapSystem;
        return 0;
    }
    else
    {
        std::cout << "Window\n";
        MapSystem * mapSystem = new MapSystem;
        QApplication a(argc, argv);
        MainWindow w (mapSystem);
        w.show();
        delete mapSystem;

        return a.exec();
    }
}
