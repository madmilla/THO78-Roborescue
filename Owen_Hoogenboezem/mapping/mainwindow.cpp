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

void MainWindow::messages(QString type)
{
    if(type == "error")
    {
        QMessageBox errorMsg(this);
        errorMsg.setText("FILE NOT FOUND");
        errorMsg.exec();
    }
    else if(type == "legend")
    {
        QMessageBox legend(this);
        legend.setDetailedText("Black: rock\nBlue: water\nYellow: dirt\nRed: gravel");
        legend.setText("mapping legend");
        legend.exec();
    }
}

void MainWindow::readFile(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) { messages("error"); }
    QTextStream in(&file);
    cX = 0, cY = 0;
    while(!file.atEnd())
    {
        QString line = in.readAll();
        for(int i = 0; i < line.length(); i++)
        {
            character = line.at(i);
            character.remove("\n");
            if(cX >= MAX) { cX = 0; cY++; }
            if(character == GRAVEL || character == DIRT || character == ROCK || character == WATER) { objects[cX][cY] = character; cX++;  }
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
    for(int iY = 0; iY < MAX; iY++){
        for(int iX = 0; iX < MAX; iX++){
            QRect rect(CUBE * iX ,10+ (CUBE*iY), CUBE, CUBE);
            QColor colour = Qt::white;
            if(objects[iX][iY] == GRAVEL){
                colour = Qt::red;
            }
            else if(objects[iX][iY] == DIRT)
            {
                colour = Qt::yellow;
            }
            else if(objects[iX][iY] == ROCK){
                colour = Qt::black;
            }
            else if(objects[iX][iY] == WATER){
                colour = Qt::blue;
            }
            painter.fillRect(rect,colour);
        }
    }
    update();
}

void MainWindow::on_pushButton_2_clicked()
{
    messages("legend");
}
