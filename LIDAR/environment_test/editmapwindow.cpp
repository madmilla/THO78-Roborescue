#include "editmapwindow.h"
#include "ui_editmapwindow.h"
#include <QGraphicsRectItem>

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
    QVector<QVector< int > > mapLayout = map->getMapContent();
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

void EditMapWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QVector<QVector< int > > mapLayout = map->getMapContent();
    for(int y = 0; y < mapLayout.size(); y++){
        for(int x = 0; x < mapLayout[y].size(); x++){
            painter.fillRect(x*10,y*10,10,10,QBrush(Qt::blue));
        }
    }
    if(true){
        update();
    }
}
