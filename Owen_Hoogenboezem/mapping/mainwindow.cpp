#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtGui>
#include <stdio.h>
#include <iostream>
#include <QMessageBox>

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


void MainWindow::readFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    cX = 0, cY = 0;
    while(!file.atEnd())
    {
        QString line = in.readAll();
        for(int i = 0; i < line.length(); i++)
        {
            character = line.at(i);
            if(cX >= 20) { cX = 0; cY++; }
            if(character == "x" || character == "o" || character == "d" || character == "-") { objects[cX][cY] = character; cX++;  }
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
    for(int iY = 0; iY < 20; iY++){
        for(int iX = 0; iX < 20; iX++){
            QRect rect(24*iX,10+(24*iY), 24, 24);
            if(objects[iX][iY] == "x"){
                painter.fillRect(rect,Qt::red);
            }
            else if(objects[iX][iY] == "o")
            {
                painter.fillRect(rect,Qt::yellow);
            }
            else if(objects[iX][iY] == "d"){
                painter.fillRect(rect,Qt::black);
            }
            else if(objects[iX][iY] == "-"){
                painter.fillRect(rect,Qt::blue);
            }
        }
    }
    update();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox legend(this);
    legend.setDetailedText("Black: rock\nBlue: water\nYellow: dirt\nRed: gravel");
    legend.setText("mapping legend");
    legend.exec();
}
