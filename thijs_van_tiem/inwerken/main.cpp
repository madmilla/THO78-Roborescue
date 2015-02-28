#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include <iostream>

int map(MainWindow &window){ // deze functie wordt niet meer gebruikt


  QGridLayout *layout = new QGridLayout;


    for(int i=0; i <20; i++){
        for(int x=0; x<20; x++){
            layout->addWidget(new QLabel("name"),i,x);
            std::cout << i;
            std::flush(std::cout);
            std::cout << x;
        }
    }
   //window.setLayout(layout);
    QWidget * w = new QWidget;
    w->setLayout(layout);
    window.setCentralWidget(w);

    return 0;
}



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;


    window.setWindowTitle(QApplication::translate("het inwerk","Het inwerk project"));

    //map(window);
    window.show();

    return a.exec();
}

