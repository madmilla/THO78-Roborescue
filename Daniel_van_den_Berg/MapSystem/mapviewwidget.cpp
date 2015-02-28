#include "mapviewwidget.h"
#include "ui_mapviewwidget.h"
#include <QPainter>
#include "mapeditor.h"
#include "mainwindow.h"
#include <iostream>
#include <QMouseEvent>

#define WIDGET_WIDTH 300
#define WIDGET_HEIGHT 300

MapViewWidget::MapViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapViewWidget)
{
    //QTransform brushTransform(QMatrix().scale(0.7,0.7));
    objectBrushes[MapEditor::DRONE] = QBrush(Qt::green);
    objectBrushes[MapEditor::DRONE].setStyle(Qt::DiagCrossPattern);

    objectBrushes[MapEditor::WALL] = QBrush(Qt::red);
    objectBrushes[MapEditor::WALL].setStyle(Qt::Dense3Pattern);

    objectBrushes[MapEditor::TARGET] = QBrush(Qt::yellow);
    objectBrushes[MapEditor::TARGET].setStyle(Qt::CrossPattern);
    ui->setupUi(this);
}

MapViewWidget::~MapViewWidget()
{
    delete ui;
}

void MapViewWidget::mousePressEvent(QMouseEvent * mouseEvent){
    if (!MainWindow::shouldEdit){
        return;
    }

    int mapWidth = MapEditor::getInstance().getMapWidth();
    int mapHeight = MapEditor::getInstance().getMapHeight();
    int squareWidth = WIDGET_WIDTH/mapWidth;
    int squareHeight = WIDGET_HEIGHT/mapHeight;

    int squareX = mouseEvent->x() / squareWidth;
    int squareY = mouseEvent->y() / squareHeight;

    if (mouseEvent->button() == Qt::LeftButton){
        MapEditor::getInstance().placeObject(squareX,squareY,MainWindow::selectedObject);
    }else if(mouseEvent->button() == Qt::RightButton){
        for (auto object : MapEditor::getInstance().getObjectsAt(squareX,squareY)){
            MapEditor::getInstance().removeObject(squareX,squareY,MapEditor::toObject(object.toInt()));
        }
    }
    repaint();
}

void MapViewWidget::paintEvent(QPaintEvent * paintEvent){
    QPainter painter(this);
    if (MapEditor::getInstance().getLoadedMap() == ""){
        painter.drawText(32,32,QString("No map loaded."));
        return;
    }
    int mapWidth = MapEditor::getInstance().getMapWidth();
    int mapHeight = MapEditor::getInstance().getMapHeight();
    int squareWidth = WIDGET_WIDTH/mapWidth;
    int squareHeight = WIDGET_HEIGHT/mapHeight;
    painter.fillRect(0,0,WIDGET_WIDTH,WIDGET_HEIGHT,backgroundBrush);
    for (int x = 0; x <= mapWidth; x ++){
        for (int y = 0; y <= mapHeight; y ++){
            QJsonArray objects = MapEditor::getInstance().getObjectsAt(x,y);
            if (objects.count() == 0){
                continue;
            }
            for (auto object : objects){
                std::cout << "Drawing "<<object.toInt() << " at (" <<x*squareWidth<<","<<y*squareHeight<<") - (" <<x*squareWidth+squareWidth<<","<<y*squareHeight+squareHeight<<")\n";
                std::flush(std::cout);
                painter.fillRect(x*squareWidth,y*squareHeight,squareWidth,squareHeight,objectBrushes[MapEditor::Objects(object.toInt())]);
            }
        }
    }
}

void MapViewWidget::on_MapViewWidget_destroyed()
{

}
