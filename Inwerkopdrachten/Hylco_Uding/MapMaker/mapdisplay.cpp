#include "mapdisplay.h"
#include "ui_mapdisplay.h"

MapDisplay::MapDisplay(QString filename,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDisplay)
{
    ui->setupUi(this);
    map = new Map(filename);
}

MapDisplay::~MapDisplay()
{
    delete ui;
}

void MapDisplay::mousePressEvent(QMouseEvent * event){
   if(event->pos().x()<480){
       ui->listWidget->clear();
       QJsonArray cellTypes = map->getPixel(event->pos().y()/(MAP_HEIGHT/map->getHeight()* (MAP_HEIGHT/map->getWidth() / ((float)MAP_HEIGHT/map->getWidth()-ui->verticalSlider->value()))+ui->verticalScrollBar->value()-1)
                              ,event->pos().x()/(MAP_HEIGHT/map->getHeight()* (MAP_HEIGHT/map->getWidth() / ((float)MAP_HEIGHT/map->getWidth()-ui->verticalSlider->value())))+ui->horizontalScrollBar->value());
       for(int i = 0; i < cellTypes.size(); ++i){
           ui->listWidget->addItem(cellTypes[i].toObject()["type"].toString());
       }
   }
}

void MapDisplay::paintEvent(QPaintEvent *e){
    QPainter painter(this);
     qDebug()<< MAP_WIDTH/map->getWidth() / ((float)MAP_WIDTH/map->getWidth()-ui->verticalSlider->value());
    for(int i = 0; i <= map->getHeight()-ui->verticalScrollBar->value(); i ++){
        for(int j = 0; j <= map->getWidth()-ui->horizontalScrollBar->value(); j++){
            int cellWidth = MAP_WIDTH/map->getWidth() * (MAP_WIDTH/map->getWidth() / ((float)MAP_WIDTH/map->getWidth()-ui->verticalSlider->value()));
            int cellHeight = MAP_HEIGHT/map->getHeight()* (MAP_HEIGHT/map->getWidth() / ((float)MAP_HEIGHT/map->getWidth()-ui->verticalSlider->value()));
            if(j*cellHeight < 480 && i*cellWidth < 480){
            QJsonArray cellTypes = map->getPixel(i+ui->verticalScrollBar->value(),j+ui->horizontalScrollBar->value());
            bool isFree =false;
            bool isQuad =false;
            bool isAvu =false;
            for(int cellTypeIndex = 0; cellTypeIndex < cellTypes.size(); ++cellTypeIndex){
                QString item = cellTypes[cellTypeIndex].toObject()["type"].toString();
                item == "free"||isFree?isFree=true:isFree=false;
                item == "quad"||isQuad?isQuad=true:isQuad=false;
                item == "avu"||isAvu?isAvu=true:isAvu=false;
                painter.fillRect(j*cellHeight,i*cellWidth,cellHeight,cellWidth,map->getType(item));
            }
            if(isFree)
                painter.fillRect(j*cellHeight,i*cellWidth,cellHeight,cellWidth,map->getType("free"));
            if(isQuad)
                painter.fillRect(j*cellHeight,i*cellWidth,cellHeight,cellWidth,map->getType("quad"));
            if(isAvu)
                painter.fillRect(j*cellHeight,i*cellWidth,cellHeight,cellWidth,map->getType("avu"));
            }
        }
    }
}

void MapDisplay::on_verticalSlider_sliderMoved(int position)
{
    ui->horizontalScrollBar->setMaximum(position);
    ui->verticalScrollBar->setMaximum(position);
    ui->label->setText(QString::number(position));
    ui->label->setGeometry(ui->label->pos().x(),ui->label->pos().y()+1,ui->label->height(),ui->label->width());
    this->repaint();
}

void MapDisplay::on_horizontalScrollBar_sliderMoved(int position)
{
    this->repaint();
}

void MapDisplay::on_verticalScrollBar_sliderMoved(int position)
{
    this->repaint();
}
