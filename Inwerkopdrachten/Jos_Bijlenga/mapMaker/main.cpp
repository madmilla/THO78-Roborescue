#include "mainwindow.h"
#include <QApplication>
#include "maplogic.h"
#include <iostream>
#include <string>
#include "tester.h"

int main(int argc, char *argv[])
{
    if(argc > 1){
        if(std::string(argv[1]) == "test"){
            //Run test
            tester test;
            test.ini();
        }
    }
    else{
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
    }
    return 0;
}
