#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc >=1 && argv[1]== "-test"){
        std::cout << "this is a test";
    }
    else{
        QApplication a(argc, argv);
        MainWindow w;
        qDebug() << "start";
        w.show();
        return a.exec();
    }
}
