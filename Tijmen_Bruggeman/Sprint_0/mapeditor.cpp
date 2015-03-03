#include "mapEditor.h"
#include "ui_mapeditor.h"

MapEditor::MapEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapEditor)
{
    ui->setupUi(this);
}

MapEditor::~MapEditor()
{
    delete ui;
}

void MapEditor::show_map(){
    if(map->getFileName()== "NEW FILE"){
        ui->saveButton->setVisible(false);
    }
    editing = false;
    ui->pushButton->setVisible(true);
    this->setFixedWidth(480);
    exec();
}
void MapEditor::paintEvent(QPaintEvent *e){
    if(mousePressed && editing){
        QPoint point = this->mapFromGlobal(QCursor::pos());
        if(point.x()<480){
            if(point.x()<0){return;}
            else if(point.y()<0){ return;}
            if(!editing){return;}
            int XPosition = (point.x() - (point.x()% objectSize))/objectSize;
            int YPosition = (point.y() - (point.y()% objectSize))/objectSize;
            if((YPosition> map->getHeight()-1)|| XPosition> map->getWidth()-1){
                return;
            }
            map->setObject(current_object,XPosition,YPosition);

        }
    }
    QPainter painter(this);
    if(map->getHeight() == 0){
        painter.drawLine(10,10,100,100);
        painter.fillRect(100,100,100,100,QBrush(Qt::green));
    }
    else{
        if(map->getWidth() <= map->getHeight()){
            objectSize = screen_height/map->getWidth();
        }
        else{
            objectSize = screen_witdh/map->getHeight();
        }
        int x;
        int y = 0;
        for(QString line : map->getMap()){
            x = 0;
            for(char ch : line.toStdString()){
                switch(ch){
                case Objects::Quad:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::red));
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::Dense4Pattern));
                    break;
                case Objects::Water:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::blue));
                    break;
                case Objects::Stone:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::black));
                    break;
                case Objects::Wall:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::yellow));
                    break;
                case Objects::Grass:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::green));
                    break;
                case Objects::Unknown:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::darkGray));
                    break;
                case Objects::Tree:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::darkGreen));
                    break;
                case Objects::Car:
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::red));
                    painter.fillRect(x*objectSize,y*objectSize,objectSize,objectSize,QBrush(Qt::Dense6Pattern));
                    break;
                }

                x++;
            }
            y++;
        }
    }
    if(mousePressed){
        update();
    }
}


void MapEditor::setMap(Map * newMap){
    if(map != NULL){
        delete map;
    }
    map = newMap;
}
void MapEditor::mousePressEvent(QMouseEvent * event){
    mousePressed = true;
    if(event->pos().x()<480){
        if(!editing){return;}
        int XPosition = (event->pos().x() - (event->pos().x()% objectSize))/objectSize;
        int YPosition = (event->pos().y() - (event->pos().y()% objectSize))/objectSize;
        if((YPosition> map->getHeight()-1)|| XPosition> map->getWidth()-1){
            return;
        }
        map->setObject(current_object,XPosition,YPosition);
        update();
    }
}
void MapEditor::mouseReleaseEvent(QMouseEvent *event){
    mousePressed = false;
}

void MapEditor::on_pushButton_clicked()
{
    editing = true;
    ui->pushButton->setVisible(false);
    this->setFixedWidth(600);
}

void MapEditor::on_grass_clicked()
{
    current_object = Objects::Grass;
}

void MapEditor::on_car_clicked()
{
    current_object = Objects::Car;
}

void MapEditor::on_water_clicked()
{
    current_object = Objects::Water;
}

void MapEditor::on_wall_clicked()
{
    current_object = Objects::Wall;
}

void MapEditor::on_stone_clicked()
{
    current_object = Objects::Stone;
}

void MapEditor::on_saveButton_clicked()
{
    map->save();
}

void MapEditor::on_saveAsButton_clicked()
{

    if(ui->saveName->displayText()=="" ||ui->saveName->displayText()=="Vul naam in" ){
        ui->saveName->setText("Vul naam in");
        return;
    }
    QString fileName = ui->saveName->displayText().toStdString().c_str();
    map->saveAs(fileName);
    ui->saveButton->setVisible(true);
}

void MapEditor::on_tree_clicked()
{
    current_object = Objects::Tree;
}

void MapEditor::on_quad_clicked()
{
    current_object = Objects::Quad;
}
