#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtGui>
#include <stdio.h>
#include <iostream>



void readFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int x = 0, y = 0;
    while(!file.atEnd())
    {
        QString line = in.readAll();
        for(int i = 0; i < line.length(); i++)
        {
            QString test = line.at(i);
            if(x >= 20) { x = 0; y++; }
            if(test == "x") { x++; qDebug() << x << "," << y << ": tree" << endl; }
            else if(test == "o") { x++; qDebug() << x << "," << y << ": rock" << endl; }
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    readFile("/home/owen/THO78-Roborescue/Owen_Hoogenboezem/mapping/test");
    w.show();
    return a.exec();
}
