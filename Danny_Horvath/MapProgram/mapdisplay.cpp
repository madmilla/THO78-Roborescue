#include "mapdisplay.h"
#include "ui_mapdisplay.h"
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QChar>
#include <QDebug>
#include <QRect>

MapDisplay::MapDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDisplay)
{
    ui->setupUi(this);
}

MapDisplay::~MapDisplay()
{
    delete ui;
}

void MapDisplay::setMap(QString content){
    map = content;
}

void MapDisplay::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int width = 640;
    int height = 480;
    x = 0;
    y = 0;
    objectx = (width / 20);
    objecty = (height / 20);
    map.remove(QRegExp("[\\n\\t\\r]"));                 //Remove enters tabs and whitespaces from the string y*20+x
    if(y < 20){
        for(int i = 0; i < map.length(); i++){
            std::cout << "TILE: " << map.toUtf8().at(i) << std::endl;
            char c = map.toUtf8().at(i);
            if(x >= 20){
                y++;
                x = 0;
            }
            switch(c){
            case MapDisplay::Wall:
                std::cout << objectx << std::endl;
                painter.fillRect((x*objectx),(y*objecty), objectx, objecty,QBrush(Qt::black));
                break;
            case MapDisplay::Rock:
                painter.fillRect((x*objectx),(y*objecty), objectx, objecty,QBrush(Qt::gray));
                break;
            case MapDisplay::Grass:
                painter.fillRect((x*objectx),(y*objecty), objectx, objecty,QBrush(Qt::green));
                break;
            case MapDisplay::Tree:
                painter.fillRect((x*objectx),(y*objecty), objectx,objecty,QBrush(Qt::red));
                break;
            case MapDisplay::Water:
                painter.fillRect((x*objectx),(y*objecty), objectx,objecty,QBrush(Qt::blue));
                break;
            case MapDisplay::Sand:
                painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(Qt::yellow));
                break;
            case MapDisplay::ATV:
                painter.fillRect((x*objectx),(y*objecty), objectx,objecty,QBrush(Qt::black));
                break;
            case MapDisplay::Quadcopter:
                painter.fillRect((x*objectx),(y*objecty), objectx,objecty,QBrush(Qt::black));
                break;
            case MapDisplay::ROSBEE:
                painter.fillRect((x*objectx),(y*objecty), objectx,objecty,QBrush(Qt::black));
                break;
            case MapDisplay::Objective:
                painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(Qt::black));
                break;
            case MapDisplay::Unknown:
                painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(Qt::white));
                break;
            }
            x++;
        }
    }
}

void MapDisplay::mousePressEvent(QMouseEvent *event){
    if(event->pos().x() < 640){
       if(!selected){
           return;
        }
        int positionx = (event->pos().x() - event->pos().x() % objectx) / objectx;
        int positiony = (event->pos().y() - event->pos().y() % objecty) / objecty;
        if(positionx > 20 && positiony > 20){
            return;
        }
        map.replace((positiony*20+positionx), 1, selected);
        update();
    }
}

void MapDisplay::on_wallButton_clicked()
{
    selected = MapDisplay::Wall;
    std::cout << "Wall pressed" << std::endl;
}

void MapDisplay::on_grassButton_clicked()
{
    selected = MapDisplay::Grass;
    std::cout << "Grass pressed" << std::endl;
}

void MapDisplay::on_sandButton_clicked()
{
    selected = MapDisplay::Sand;
    std::cout << "Sand pressed" << std::endl;
}

void MapDisplay::on_stoneButton_clicked()
{
    selected = MapDisplay::Rock;
    std::cout << "Stone pressed" << std::endl;
}

void MapDisplay::on_treeButton_clicked()
{
    selected = MapDisplay::Tree;
    std::cout << "Tree pressed" << std::endl;
}

void MapDisplay::on_waterButton_clicked()
{
    selected = MapDisplay::Water;
    std::cout << "Water pressed" << std::endl;
}

void MapDisplay::on_atvButton_clicked()
{
    selected = MapDisplay::ATV;
    std::cout << "Atv pressed" << std::endl;
}

void MapDisplay::on_rosbeeButton_clicked()
{
    selected = MapDisplay::ROSBEE;
    std::cout << "Rosbee pressed" << std::endl;
}

void MapDisplay::on_quadButton_clicked()
{
    selected = MapDisplay::Quadcopter;
    std::cout << "Quad pressed" << std::endl;
}

void MapDisplay::on_objectiveButton_clicked()
{
    selected = MapDisplay::Objective;
    std::cout << "Objective pressed" << std::endl;
}

void MapDisplay::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QString(),
                "Text Files (*.txt);;C++ Files (*.cpp *.h)");   //Open file dialog

    if (!fileName.isEmpty()) {                          //If a filename is set
        QFile file(fileName);                           //Put this in a variable
        if (!file.open(QIODevice::WriteOnly)) {         //If the file can't be opened to write return an error message
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        } else {
            QTextStream tStream(&file);                 //Setup a textstream to the file
            tStream << map;                           //Copy the content of the mapeditor to the file
            tStream.flush();                            //Flush the textstream
            file.close();                               //Close the filestream
        }
    }
}
