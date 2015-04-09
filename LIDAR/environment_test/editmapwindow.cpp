#include "editmapwindow.h"
#include "ui_editmapwindow.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <vector>
#include <iostream>

EditMapWindow::EditMapWindow(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMapWindow),
    map(map)
{
    objectx = (drawWidth / map->width);
    objecty = (drawHeight / map->height);
    ui->setupUi(this);

}

EditMapWindow::~EditMapWindow(){
    delete ui;
}

void EditMapWindow::on_obstacleButton_clicked(){
    selected = 1;
}

void EditMapWindow::on_noneButton_clicked()
{
    selected = 0;
}

void EditMapWindow::on_saveMapButton_clicked(){
    map->saveMap();
}

void EditMapWindow::mousePressEvent(QMouseEvent * event){
    if(event->pos().x() < 640){
       if(!selected < 0){
           return;
        }
        int positionx = (event->pos().x() - event->pos().x() % objectx) / objectx;
        int positiony = (event->pos().y() - event->pos().y() % objecty) / objecty;
        std::cout << "pos x: " << positionx << " pos y: " << positiony << " Selected: " << selected << std::endl;
        if(positionx < map->width  &&  positiony < map->height){
            map->setMapObject(selected, positiony, positionx);
            update();
            mousePressed = true;
        }
    }
}

void EditMapWindow::paintEvent(QPaintEvent *e){
    if(!mousePressed) return;
    QPainter painter(this);
    int y = 0;
    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(getColorById(forx)));
            x++;
        }
        y++;
    }
}

Qt::GlobalColor EditMapWindow::getColorById(int id){
    Qt::GlobalColor bColor;
    switch (id) {
    case 0:
        bColor = Qt::white;
    break;
    case 1:
        bColor = Qt::red;
    break;
    case 2:
        bColor = Qt::green;
    break;
    case 3:
        bColor = Qt::blue;
    break;
    default:
        bColor = Qt::black;
    break;
    }
    return bColor;
}
