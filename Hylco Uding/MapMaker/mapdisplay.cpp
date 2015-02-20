#include "mapdisplay.h"
#include "ui_mapdisplay.h"

MapDisplay::MapDisplay(int height, int width,QJsonObject json,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDisplay)
{
    ui->setupUi(this);
    map = map = new Map(height,width,json);
}

MapDisplay::~MapDisplay()
{
    delete ui;
}

void MapDisplay::mousePressEvent(QMouseEvent * event){
   if(event->pos().x()<480)
   ui->listWidget->clear();
   QJsonArray cellTypes = map->getPixel(event->pos().x()/(480/map->getWidth()),event->pos().y()/(480/map->getHeight()));
   for(int i = 0; i < cellTypes.size(); ++i)
       ui->listWidget->addItem(cellTypes[i].toObject()["type"].toString());
}

void MapDisplay::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    for(int i = 0; i <= map->getHeight(); i ++){
        for(int j = 0; j <= map->getWidth(); j++){
            QJsonArray cellTypes = map->getPixel(i,j);
            bool isFree =false;
            bool isQuad =false;
            bool isAvu =false;
            for(int cellTypeIndex = 0; cellTypeIndex < cellTypes.size(); ++cellTypeIndex){
                QString item = cellTypes[cellTypeIndex].toObject()["type"].toString();
                item == "free"||isFree?isFree=true:isFree=false;
                item == "quad"||isQuad?isQuad=true:isQuad=false;
                item == "avu"||isAvu?isAvu=true:isAvu=false;
                painter.fillRect(j*(480/map->getWidth()),i*(480/map->getHeight()),480/map->getWidth(),480/map->getHeight(),map->getType(item));
            }
            if(isFree)
                painter.fillRect(j*(480/map->getWidth()),i*(480/map->getHeight()),480/map->getWidth(),480/map->getHeight(),map->getType("free"));
            if(isQuad)
                painter.fillRect(j*(480/map->getWidth()),i*(480/map->getHeight()),480/map->getWidth(),480/map->getHeight(),map->getType("quad"));
            if(isAvu)
                painter.fillRect(j*(480/map->getWidth()),i*(480/map->getHeight()),480/map->getWidth(),480/map->getHeight(),map->getType("avu"));
        }
    }
}
