
#include <QApplication>

#include "mainwindow.h"
#include "tester.h"

int main(int argc, char *argv[])
{
    //if(argc > 1 && strcmp(argv[1], "-runtest") == 0){
        Tester tester;
        return tester.run();
    //}else{
        //QApplication app(argc,argv);
        //MainWindow window;
        //window.show();
        //return app.exec();
    //}

}
