#include "Map.h"
#include <iostream>

Map::Map(QWidget *parent) : QWidget(parent)
{
  std::cout << "henk" << std::endl;
  setAutoFillBackground(true);
}

Map::~Map()
{

}

void Map::mousePressEvent(QMouseEvent *event){
    int x = event->x()/blockWidth;
    int y = event->y()/blockHeight;
    QColor color;
    qDebug() << "Mouse x" << x;
    qDebug() << "Mouse y" << y;
    if(event->button() == Qt::LeftButton){
            color = Qt::black;
    }
    setTile(x, y);
    this->update();
}

void Map::setTile(int x, int y){
    for(int iiy = 0; iiy < (y+1); iiy++){
        for(int iix = 0; iix < (x+1); iix++){
            qDebug() << "iix" << iix << "iiy" << iiy;
            if(iiy == y && iix == x){
                QRect rect(blockWidth*iix,blockHeight*iiy, blockWidth, blockHeight);
                myMap[iix][iiy] = "1";
            }
        }
    }
}

void Map::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    blockWidth = this->width()/20;
    blockHeight = this->height()/20;
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            QRect rect(blockWidth*iix,blockHeight*iiy, blockWidth, blockHeight);
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

void Map::getMap(QString filename)
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
