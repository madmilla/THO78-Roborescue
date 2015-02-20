#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "file.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    std::string name ="myReadFile.txt";
    std::string namewrite = "output.txt";
    file::file(name,namewrite);




    QApplication a(argc, argv);
    MainWindow window;
    window.resize(640,480);
    window.show();
    window.setWindowTitle(QApplication::translate("het inwerk","Het inwerk project"));

    return a.exec();
}
