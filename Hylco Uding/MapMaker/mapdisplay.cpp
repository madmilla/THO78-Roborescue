#include "mapdisplay.h"
#include "ui_mapdisplay.h"

MapDisplay::MapDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDisplay)
{
    ui->setupUi(this);
    Types["wall"] =  QBrush(Qt::red);
    Types["water"] =  QBrush(Qt::blue);
    Types["free"] =  QBrush(Qt::white,Qt::DiagCrossPattern);
    Types["grass"] = QBrush(Qt::green);
    Types["stone"] = QBrush(Qt::lightGray);
    Types["wood"] = QBrush(QColor(139,69,19));
    Types["quad"] = QBrush(Qt::black,Qt::CrossPattern);
    Types["avu"] = QBrush(Qt::darkYellow,Qt::CrossPattern);
}

MapDisplay::~MapDisplay()
{
    delete ui;
}

void MapDisplay::setMap(QJsonObject json){
    this->json = json;
}

void MapDisplay::mousePressEvent(QMouseEvent * event){
   int height = json["height"].toInt();
   int width = json["width"].toInt();
   if(event->pos().x()<480)
   ui->listWidget->clear();
   QJsonArray cellTypes = json["rows"].toArray()[event->pos().y()/(480/height)].toObject()["row"].toArray()[event->pos().x()/(480/width)].toObject()["cell"].toArray();
   for(int i = 0; i < cellTypes.size(); ++i)
       ui->listWidget->addItem(cellTypes[i].toObject()["type"].toString());
}

void MapDisplay::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    int height = json["height"].toInt();
    int width = json["width"].toInt();
    QRect rect(0,0,480/width,480/height);
    QJsonArray rows = json["rows"].toArray();
    for(int i = 0; i <= json["height"].toInt(); i ++){
        QJsonArray cellArray = rows[i].toObject()["row"].toArray();
        for(int j = 0; j <= json["width"].toInt(); j++){
            QJsonObject cell = cellArray[j].toObject();
            QJsonArray cellTypes = cell["cell"].toArray();
            bool isFree =false;
            bool isQuad =false;
            bool isAvu =false;
            for(int cellTypeIndex = 0; cellTypeIndex < cellTypes.size(); ++cellTypeIndex){
                QString item = cellTypes[cellTypeIndex].toObject()["type"].toString();
                item == "free"||isFree?isFree=true:isFree=false;
                item == "quad"||isQuad?isQuad=true:isQuad=false;
                item == "avu"||isAvu?isAvu=true:isAvu=false;
                painter.fillRect(j*(480/width),i*(480/height),480/width,480/height,Types[item]);
            }
            if(isFree)
                painter.fillRect(j*(480/width),i*(480/height),480/width,480/height,Types["free"]);
            if(isQuad)
                painter.fillRect(j*(480/width),i*(480/height),480/width,480/height,Types["quad"]);
            if(isAvu)
                painter.fillRect(j*(480/width),i*(480/height),480/width,480/height,Types["avu"]);
        }
    }
}
