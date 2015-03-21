#include "map.h"
#include "ui_map.h"
#include <QTextStream>

QTextStream out(stdout);

Map::Map(QString filename, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height());

    table = ui->tableWidget;

    for(int i = 0; i < table->columnCount(); i++){
        table->setColumnWidth(i,(table->width()/20)-2);
        table->setRowHeight(i,(table->height()/20)-2);
    }

    mapLogic = new MapLogic(filename);

    showMap();
}

Map::~Map()
{
    delete ui;
    delete mapLogic;
}

void Map::showMap(){
    for(int y = 0; y < mapLogic->mapLayout.size(); y++){
        for(int x = 0; x < mapLogic->mapLayout[y].size(); x++){
            QTableWidgetItem * item = new QTableWidgetItem(0);
            item->setBackgroundColor(getColorById(mapLogic->mapLayout[y][x]));
            item->setText("x: " + QString::number(x) + " y: " + QString::number(y));
            table->setItem(y,x,item);
        }
    }
}

void Map::on_emptyButton_clicked(){
    fillColor(0);
}

void Map::on_redButton_clicked(){
    fillColor(1);
}

void Map::on_greenButton_clicked(){
    fillColor(2);
}

void Map::on_blueButton_clicked(){
    fillColor(3);
}

void Map::on_saveButton_clicked(){
    mapLogic->saveMap();
}

void Map::fillColor(int id){
    foreach(QTableWidgetItem* item, table->selectedItems()){
        mapLogic->updateMap(item->row(), item->column(), id);
        item->setBackgroundColor(getColorById(id));
    }
}

Qt::GlobalColor Map::getColorById(int id){
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
