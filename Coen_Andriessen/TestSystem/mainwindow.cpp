#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QtGui>
#include <stdio.h>
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getMap("C:\\Users\\Coen\\Documents\\GitHub\\THO78-Roborescue\\Coen_Andriessen\\TestSystem\\Mapping.txt");
    showMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            QRect rect(24*iix,20+(24*iiy), 24, 24);
            if(myMap[iix][iiy] == "0"){
                painter.fillRect(rect,Qt::red);
            }
            if(myMap[iix][iiy] == "1"){
                painter.fillRect(rect,Qt::blue);
            }
            if(iiy == quadCopterLocationY.toInt() && iix == quadCopterLocationX.toInt()){
                painter.fillRect(rect,Qt::green);
            }
        }
    }
    update();
}

void MainWindow::getMap(QString filename)
{
    xLength = 0;
    yLength = 0;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString map = in.readAll();
        //qDebug() << "abc" << map << "def";
        for(int i = 0; i < map.length(); i++){
            QString character = map.at(i);
            if(xLength == 20){
                xLength = 0;
                yLength = yLength + 1;
            }
            if(character == "1" || character == "0"){
                myMap[xLength][yLength] = character;
                xLength = xLength + 1;
            }
            if(character == "Q"){
                QString temp;
                for(int henk = (i + 1); henk < (i + 5); henk++){
                    temp += map.at(henk);
                }
                QStringList myStringList = temp.split("-");
                quadCopterLocationX = myStringList[0];
                quadCopterLocationY = myStringList[1];
            }
        }
    }
    file.close();
}


void MainWindow::showMap()
{

}
