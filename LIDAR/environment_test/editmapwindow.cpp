#include "editmapwindow.h"
#include "ui_editmapwindow.h"
#include <QGraphicsRectItem>
#include <vector>
#include <iostream>

EditMapWindow::EditMapWindow(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMapWindow),
    map(map)
{
    ui->setupUi(this);

    showMap(map);
}

EditMapWindow::~EditMapWindow(){
    delete ui;
}

void EditMapWindow::showMap(Map *map){
    vector<vector< int > > mapLayout = map->getMapContent();
    for(int y = 0; y < mapLayout.size(); y++){
        for(int x = 0; x < mapLayout[y].size(); x++){
        }
    }
}

void EditMapWindow::on_obstacleButton_clicked(){

}

void EditMapWindow::on_saveMapButton_clicked(){
    map->saveMap();
}
void EditMapWindow::mousePressEvent(QMouseEvent * event){
    mousePressed = true;
}

void EditMapWindow::paintEvent(QPaintEvent *e){
    if(mousePressed){
        QPainter painter(this);
    }
    mousePressed = false;
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
