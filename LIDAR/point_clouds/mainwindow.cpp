#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtGui>
#include <stdio.h>
#include <iostream>
#include <QMessageBox>
#include <QApplication>

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

void MainWindow::readFile(QString fileOne, QString fileTwo)
{
    QFile one(fileOne);
    QFile two(fileTwo);
    one.open(QIODevice::ReadOnly | QIODevice::Text);
    two.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream oneS(&one);
    QTextStream twoS(&two);
    QString posO = oneS.readLine();
    QString posT = twoS.readLine();


    QString line1 = oneS.readAll();
    QString line2 = twoS.readAll();
    line1.remove(posO);
    line2.remove(posT);

    line1 = line1.simplified();
    line2 = line2.simplified();
    line1 = line1.replace( " ", "" );
    line2 = line2.replace( " ", "" );

    int posInt1 = posO.toInt();
    int posInt2 = posT.toInt();
    posi1 = posInt1;
    posi2 = posInt2;
    combine(line1, line2, posInt1, posInt2);
}


void MainWindow::combine(QString cloud1, QString cloud2, int pos1, int pos2)
{
    QFile output("/home/owen/cloudSet/combined");
    output.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&output);
    QString combined[50][50];
    int y = 0;
    for(int i = 0; i < cloud1.length(); i++)
    {
        if(pos1 >= (posi1 + 20))
        {
           pos1 = posi1;
           y++;
        }
        combined[pos1][y] = cloud1[i];
        pos1++;
    }
    y = 0;
    for(int i = 0; i < cloud2.length(); i++)
    {
        qDebug() << pos2;
        if(pos2 >= (posi2 + 20))
        {
           pos2 = posi2;
           y++;
        }
        combined[pos2][y] = cloud2[i];
        pos2++;
    }
    int max = (y+1) * ((20 + 20) - posi2);
    y = 0;
    int tempPos = 0;
    for(int i = 0; i < max; i++)
    {
        if(tempPos >= (posi2 + 20))
        {
          out << "\n";
          tempPos = 0;
          y++;
        }
        if(tempPos >= max)
        {

        }
        out << combined[tempPos][y];
        //qDebug() << combined[tempPos][y];
        tempPos++;
    }
}

void MainWindow::on_pushButton_clicked()
{
   readFile("/home/owen/cloudSet/cloud1", "/home/owen/cloudSet/cloud2");
}

void MainWindow::on_writeButton_clicked()
{
}
