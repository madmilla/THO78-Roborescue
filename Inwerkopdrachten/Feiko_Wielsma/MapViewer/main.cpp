#include "mainwindow.h"
#include <QApplication>
#include "mapsystem.h"
#include "maptester.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    bool debug = false;
    if(argc > 1 && std::string(argv[1]) == "--test" || debug)
    {
        std::cout << "Test\n";
        MapSystem * mapSystem = new MapSystem;
        MapTester mapTester(mapSystem);
        bool testsSucceeded = mapTester.runTests();
        delete mapSystem;
        return !testsSucceeded;
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
