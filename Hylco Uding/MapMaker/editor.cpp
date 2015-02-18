#include "editor.h"
#include "ui_editor.h"
#include <QJsonArray>
Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
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
    for(auto & e : Types){
        ui->listWidget->addItem(e.first);
    }
    for(int i = 0; i<20; i++){
        for(int j = 0; j<20;j++){
            array[i][j] = QJsonArray() ;
        }
    }
}

void Editor::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        QJsonObject typeObject;
        if(ui->listWidget->currentItem() != NULL){
            typeObject["type"] = ui->listWidget->currentItem()->text();
            array[event->pos().y()/(480/height)][event->pos().x()/(480/width)].append(typeObject);
        }
    } else {
        array[event->pos().y()/(480/height)][event->pos().x()/(480/width)] = QJsonArray();
    }
    this->repaint();
}
void Editor::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    for(int i = 0; i < height; i ++){
        for(int j = 0; j < width; j++){
            QJsonArray cellTypes = array[i][j];

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

Editor::~Editor()
{
    delete ui;
}
void Editor::setMap(QJsonObject json){
    QJsonArray rows = json["rows"].toArray();
    this->height = json["height"].toInt();
    this->width = json["width"].toInt();
    ui->name->setText(json["title"].toString());
    for(int i = 0; i < json["height"].toInt(); i ++){
        QJsonArray cellArray = rows[i].toObject()["row"].toArray();
        for(int j = 0; j < json["width"].toInt(); j++){
            QJsonObject cell = cellArray[j].toObject();
            QJsonArray cellTypes = cell["cell"].toArray();
            array[i][j] = cellTypes;
        }
    }
}
void Editor::setSize(int height, int width){
    this->height = height;
    this->width = width;
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width;j++){
            array[i][j] = QJsonArray() ;
        }
    }
}

void Editor::on_Save_clicked()
{
    if(ui->name->text() != ""){
        QJsonObject main;
        QJsonObject sub;
        QJsonArray rows;
        sub["title"] = ui->name->text();
        sub["width"] = width;
        sub["height"] = height;
        QJsonObject *row;
        QJsonArray *cellArray;
        QJsonObject *cell;
        for(int i = 0; i < height; i ++){
            row = new QJsonObject;
            cellArray = new QJsonArray;
            for(int j = 0; j < width; j++){
                cell = new QJsonObject;
                cell->insert("cell",array[i][j]);
                cellArray->append(*cell);
            }
            row->insert("row",*cellArray);
            rows.append(*row);
        }
        sub["rows"] = rows;
        main["map"] = sub;
        QFile file("maps/"+ui->name->text() + ".map");
        QJsonDocument saveDoc(main);
        file.open(QIODevice::WriteOnly);
        file.write(saveDoc.toJson());
        qDebug() << "niet leeg";
    }
    qDebug() << "leeg";
}
