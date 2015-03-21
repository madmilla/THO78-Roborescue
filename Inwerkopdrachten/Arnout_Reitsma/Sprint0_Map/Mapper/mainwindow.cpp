#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtGui>
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
        errorMsg.setText("File not found");
        errorMsg.exec();
    }
    else if(type == "readerror"){
        QMessageBox errorMsg(this);
        errorMsg.setText("File not correct");
        errorMsg.exec();
    }
}

void MainWindow::loadFile(QString filename)
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
            if(cX >= MAX){
                cX = 0; cY++;
            }
            if(character.toInt()){
                objects[cX][cY] = character; cX++;
            }
        }
    }
}

void MainWindow::on_loadButton_clicked()
{
    loadFile(":/new/prefix1/map1.map");
    loadButtonClicked = true;
    clearButtonClicked = false;
}

void MainWindow::on_clearButton_clicked()
{
    clearButtonClicked = true;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int iY = 0; iY < MAX; iY++){
        for(int iX = 0; iX < MAX; iX++){
            QRect rect(CUBE * iX ,10+ (CUBE*iY), CUBE, CUBE);
            QColor colour;
            if(!clearButtonClicked){
                switch(objects[iX][iY].toInt()){
                case Objects::Water:
                    colour = Qt::blue;
                    break;
                case Objects::Stone:
                    colour = Qt::darkGray;
                    break;
                case Objects::Wall:
                    colour = Qt::red;
                    break;
                case Objects::Grass:
                    colour = Qt::green;
                    break;
                case Objects::Tree:
                    colour = Qt::darkGreen;
                    break;
                default:
                    colour = Qt::white;
                    break;
                }
            }
            else{
               colour = Qt::white;
            }
            painter.fillRect(rect,colour);
        }
    }
    update();
    if(loadButtonClicked){
        return;
    }
    loadButtonClicked = false;
}



