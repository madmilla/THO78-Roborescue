#include "map.h"
#include "ui_map.h"
#include <QTextStream>

QTextStream out(stdout);

Map::Map(QString filename, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map),
    filename(filename)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height());

    table = ui->tableWidget;

    for(int i = 0; i < table->columnCount(); i++){
        table->setColumnWidth(i,(table->width()/20)-2);
        table->setRowHeight(i,(table->height()/20)-2);
    }
    loadMap(filename);
}

Map::~Map()
{
    delete ui;
}

void Map::loadMap(QString &filename){
    QFile mapFile(filename);
    if(!mapFile.open((QIODevice::ReadOnly | QIODevice::Text))) return;
    QTextStream in(&mapFile);

    int x = 0,y = 0;
    int content;

    mapLayout.resize(mapGridSize);

    while(y <= mapGridSize - 1){
        in >> content;
        mapLayout[y].resize(x+1);
        mapLayout[y][x] = content;

        x++;
        if(x >= mapGridSize){
            x = 0;
            y++;
        }
    }
    mapFile.close();
    showMap();
}

void Map::showMap(){
    for(int y = 0; y < mapLayout.size(); y++){
        for(int x = 0; x < mapLayout[y].size(); x++){
            QTableWidgetItem * item = new QTableWidgetItem(0);
            item->setBackgroundColor(getColorById(mapLayout[y][x]));
            item->setText("x: " + QString::number(x) + " y: " + QString::number(y));
            table->setItem(y,x,item);
        }
    }
}

void Map::updateMap(int y, int x, int newContent){
    mapLayout[y][x] = newContent;
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
    QFile mapFile(filename);
    if(!mapFile.open((QIODevice::WriteOnly | QIODevice::Text))) return;
    QTextStream mfOut(&mapFile);

    for(int y = 0; y < mapLayout.size(); y++){
        for(int x = 0; x < mapLayout[y].size(); x++){
            mfOut << mapLayout[y][x] << " ";
        }
        mfOut << "\n";
    }
    mapFile.close();
}

void Map::fillColor(int id){
    foreach(QTableWidgetItem* item, table->selectedItems()){
        updateMap(item->row(), item->column(), id);
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
        break;
    }
    return bColor;
}
