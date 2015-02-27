#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtGui>
#include <stdio.h>
#include <iostream>

bool clicked = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString test;
QString objects[30][30];

void MainWindow::readFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int ix = 0, iy = 0;
    while(!file.atEnd())
    {
        QString line = in.readAll();
        for(int i = 0; i < line.length(); i++)
        {
            test = line.at(i);
            if(ix >= 20) { ix = 0; iy++; }
            if(test == "x" || test == "o" || test == "d" || test == "-") { qDebug() << ix << "," << iy << ": " << test << endl; objects[ix][iy] = test; ix++;  }
        }
    }
}



void MainWindow::on_pushButton_clicked()
{
     readFile("/home/owen/THO78-Roborescue/Owen_Hoogenboezem/mapping/test");
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            QRect rect(24*iix,20+(24*iiy), 24, 24);
            if(objects[iix][iiy] == "x"){
                painter.fillRect(rect,Qt::red);
            }
            else if(objects[iix][iiy] == "o")
            {
                painter.fillRect(rect,Qt::yellow);
            }
            else if(objects[iix][iiy] == "d"){
                painter.fillRect(rect,Qt::black);
            }
            else if(objects[iix][iiy] == "-"){
                painter.fillRect(rect,Qt::blue);
            }
        }
    }
    update();
}
