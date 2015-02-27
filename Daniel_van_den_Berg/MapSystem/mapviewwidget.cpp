#include "mapviewwidget.h"
#include "ui_mapviewwidget.h"
#include <QPainter>
#include "mapeditor.h"
#include "mainwindow.h"

#define CELL_WIDTH 20
#define CELL_HEIGHT 20

MapViewWidget::MapViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapViewWidget)
{
    ui->setupUi(this);
}

MapViewWidget::~MapViewWidget()
{
    delete ui;
}

void MapViewWidget::paintEvent(QPaintEvent * paintEvent){
    QPainter painter(this);
    if (MapEditor::getInstance().getLoadedMap() == ""){
        painter.drawText(32,32,QString("No map loaded."));
        return;
    }
    painter.fillRect(0,0,CELL_WIDTH,CELL_HEIGHT,droneBrush);
}

void MapViewWidget::on_MapViewWidget_destroyed()
{

}
