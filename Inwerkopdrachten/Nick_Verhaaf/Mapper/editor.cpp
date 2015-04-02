#include "editor.h"
#include "ui_editor.h"
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QChar>
#include <QDebug>
#include <QRect>
#include <QRadialGradient>

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::setMap(QString content){
    map = content;
}

void Editor::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int width = 640;
    int height = 480;
    x = 0;
    y = 0;
    objectX = (width / 20);
    objectY = (height / 20);
    //Remove enters tabs and whitespaces from the string
    map.remove(QRegExp("[\\n\\t\\r]"));
    if(y < 20){
        for(int i = 0; i < map.length(); i++){
            char object = map.toUtf8().at(i);
            if(x >= 20){
                y++;
                x = 0;
            }
            switch(object){
            case Editor::Wall:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::red));
                break;
            case Editor::Rock:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::gray));
                break;
            case Editor::Grass:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::green));
                break;
            case Editor::Tree:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::darkGreen));
                break;
            case Editor::Water:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::blue));
                break;
            case Editor::Sand:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::yellow));
                break;
            case Editor::ATV:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::white));
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::VerPattern));
                break;
            case Editor::Quadcopter:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::white));
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::CrossPattern));
                break;
            case Editor::ROSBEE:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::white));
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::HorPattern));
                break;
            case Editor::Objective:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::white));
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::DiagCrossPattern));
                break;
            case Editor::Unknown:
                painter.fillRect((x*objectX), (y*objectY), objectX, objectY, QBrush(Qt::white));
                break;
            }
            x++;
        }
    }
}

void Editor::mousePressEvent(QMouseEvent *event){
    if(event->pos().x() < 640){
       if(!selectedObject){
           return;
        }
        int positionX = (event->pos().x() - event->pos().x() % objectX) / objectX;
        int positionY = (event->pos().y() - event->pos().y() % objectY) / objectY;
        if(positionX > 20 && positionY > 20){
            return;
        }
        map.replace((positionY * 20 + positionX), 1, selectedObject);
        update();
    }
}

void Editor::on_Wall_clicked()
{
    selectedObject = Editor::Wall;
}

void Editor::on_Rock_clicked()
{
    selectedObject = Editor::Rock;
}

void Editor::on_Grass_clicked()
{
    selectedObject = Editor::Grass;
}

void Editor::on_Tree_clicked()
{
    selectedObject = Editor::Tree;
}

void Editor::on_Water_clicked()
{
    selectedObject = Editor::Water;
}

void Editor::on_Sand_clicked()
{
    selectedObject = Editor::Sand;
}

void Editor::on_ATV_clicked()
{
    selectedObject = Editor::ATV;
}

void Editor::on_Quadcopter_clicked()
{
    selectedObject = Editor::Quadcopter;
}

void Editor::on_ROSBEE_clicked()
{
    selectedObject = Editor::ROSBEE;
}

void Editor::on_Objective_clicked()
{
    selectedObject = Editor::Objective;
}

void Editor::on_SaveMap_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QString(),
                    "Text Files (*.txt);;C++ Files (*.cpp *.h)");   //Open file dialog

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::critical(this, "Error", "Could not open file");
                return;
            } else {
                QTextStream tStream(&file);
                tStream << map;
                tStream.flush();
                file.close();
            }
        }
}
