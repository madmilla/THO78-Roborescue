#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}

Map::~Map()
{
    delete ui;
}

void Map::show_map(){
    this->setFixedWidth(480);
    exec();
}
void Map::paintEvent(QPaintEvent *e){
    if(mousePressed && editing){
        QPoint point = this->mapFromGlobal(QCursor::pos());
        if(point.x()<480){
            if(point.x()<0){return;}
            else if(point.y()<0){ return;}
            if(!editing){return;}
            int XPosition = (point.x() - (point.x()% objectSize))/objectSize;
            int YPosition = (point.y() - (point.y()% objectSize))/objectSize;
            if((YPosition> current_map.size()-1)|| XPosition> current_map[1].length()-1){
                return;
            }
            current_map[YPosition][XPosition] = current_object;

        }
    }
    QPainter painter(this);
    if(current_map.size() == 0){
        painter.drawLine(10,10,100,100);
        painter.fillRect(100,100,100,100,QBrush(Qt::green));
    }
    else{
        if(current_map.size() <= current_map[1].length()){
            objectSize = screen_height/current_map[1].length();
        }
        else{
            objectSize = screen_witdh/current_map.size();
        }
        int x;
        int y = 0;
        for(QString line : current_map){
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
void Map::setMap(QVector<QString> v, QString filename){
    if(filename == "NEW MAP"){
        ui->saveButton->setEnabled(false);
    }
    else{
        ui->saveButton->setEnabled(true);
    }
    fileName = filename;
    current_map.clear();
    for(QString string : v){
        current_map.push_back(string);
    }
}
void Map::mousePressEvent(QMouseEvent * event){
    mousePressed = true;
    if(event->pos().x()<480){
        if(!editing){return;}
        int XPosition = (event->pos().x() - (event->pos().x()% objectSize))/objectSize;
        int YPosition = (event->pos().y() - (event->pos().y()% objectSize))/objectSize;
        if((YPosition> current_map.size()-1)|| XPosition> current_map[1].length()-1){
            return;
        }
        current_map[YPosition][XPosition] = current_object;
        update();
    }
}
void Map::mouseReleaseEvent(QMouseEvent *event){
    mousePressed = false;
}

void Map::on_pushButton_clicked()
{
    editing = true;
    this->setFixedWidth(600);
}

void Map::on_grass_clicked()
{
    current_object = Objects::Grass;
}

void Map::on_car_clicked()
{
    current_object = Objects::Car;
}

void Map::on_water_clicked()
{
    current_object = Objects::Water;
}

void Map::on_wall_clicked()
{
    current_object = Objects::Wall;
}

void Map::on_stone_clicked()
{
    current_object = Objects::Stone;
}

void Map::on_saveButton_clicked()
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    for(QString line : current_map){
        file.write(line.toStdString().c_str());
        file.write("\n");
    }
    file.close();
}

void Map::on_saveAsButton_clicked()
{
    if(ui->saveName->displayText()=="" ||ui->saveName->displayText()=="Vul naam in" ){
        ui->saveName->setText("Vul naam in");
        return;
    }
    fileName = ui->saveName->displayText().toStdString().c_str();
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    for(QString line : current_map){
        file.write(line.toStdString().c_str());
        file.write("\n");
    }
    file.close();
    ui->saveButton->setEnabled(true);
}

void Map::on_tree_clicked()
{
    current_object = Objects::Tree;
}

void Map::on_quad_clicked()
{
    current_object = Objects::Quad;
}
