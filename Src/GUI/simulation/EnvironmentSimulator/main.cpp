#include "mainwindow.h"
#include <QApplication>
#include "test.h"
int main(int argc, char *argv[])
{
    if(argc > 1 && strcmp(argv[1], "-test") == 0){
    //if(true){
        Test test;
        return test.run();
    }else{
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}
