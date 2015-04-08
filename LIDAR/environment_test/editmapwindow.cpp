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

void EditMapWindow::on_saveMapButton_clicked(){
    map->saveMap();
}
void EditMapWindow::mousePressEvent(QMouseEvent * event){
    mousePressed = true;
}

void EditMapWindow::paintEvent(QPaintEvent *e){
    if(changed) return;
    std::cout << "Paint!" << std::endl;
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
