#include "editor.h"
#include "ui_editor.h"
#include <QJsonArray>

#include "QMessageBox"
Editor::Editor(int height, int width, QJsonObject json,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    json.isEmpty() ?  map = new Map(height,width) : map = new Map(height,width,json);
    json.isEmpty() ?  ui->name->setText("NewMap") : ui->name->setText(json["title"].toString());
    for(auto & e : map->getTypes()){
        ui->listWidget->addItem(e.first);
    }

}

void Editor::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        if(ui->listWidget->currentItem() != NULL){
            QJsonObject typeObject;
            typeObject["type"] = ui->listWidget->currentItem()->text();
            map->setPixel(event->pos().x(), event->pos().y(),typeObject);
        }
    } else {
        map->deletePixel(event->pos().x(), event->pos().y());
    }
    this->repaint();
}

void Editor::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    for(int i = 0; i < map->getHeight(); i ++){
        for(int j = 0; j < map->getWidth(); j++){
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

Editor::~Editor()
{
    delete ui;
    delete map;
}


void Editor::on_Save_clicked()
{
    if(ui->name->text() != ""){
       saveFile();
    } else {
        QMessageBox::information(this, tr("Waring"),tr("Enter a Name") );
    }
}

void Editor::saveFile(){
    QJsonObject main;
    QJsonObject sub;
    QJsonArray rows;
    sub["title"] = ui->name->text();
    sub["width"] = map->getWidth();
    sub["height"] = map->getHeight();
    QJsonObject *row;
    QJsonArray *cellArray;
    QJsonObject *cell;
    for(int i = 0; i < map->getHeight(); i ++){
        row = new QJsonObject;
        cellArray = new QJsonArray;
        for(int j = 0; j < map->getWidth(); j++){
            cell = new QJsonObject;
            cell->insert("cell",map->getPixel(i,j));
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
    this->close();
}
