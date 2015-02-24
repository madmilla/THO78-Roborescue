#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    //QWidget *window2 = new QWidget;
    //window2->setWindowTitle("Het inwerk project");

    window.setWindowTitle(QApplication::translate("het inwerk","Het inwerk project"));

    //QGridLayout *layout = new QGridLayout;
    //QLabel *label = new QLabel("Name:");
    //QLineEdit * txtName = new QLineEdit;

    //layout->addWidget(label,0,0);
    //layout->addWidget(txtName,0,1);

    //window2->setLayout(layout);
    window.resize(640,480);
    window.show();


    //int i;
    //int p=0;
       //for(i =0; i <20; i++){
           //layout->addWidget(label,i,p);
           //p++;
           //std::cout <<i;
           //std::flush(std::cout);
          //layout->addWidget(label,i,p);
           //std::cout << p;

    return a.exec();
}

