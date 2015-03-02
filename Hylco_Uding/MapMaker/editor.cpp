#include "editor.h"
#include "ui_editor.h"
#include <QJsonArray>

#include "QMessageBox"
Editor::Editor(QString filename, int height, int width, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    filename == "" ?  map = new Map(height,width) : map = new Map(filename);
    filename == "" ?  ui->name->setText("NewMap") : ui->name->setText(filename);
    for(auto & e : map->getTypes()){
        ui->listWidget->addItem(e.first);
    }

}

void Editor::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        if(ui->listWidget->currentItem() != NULL){
            if(map->containsType(event->pos().x(), event->pos().y(),ui->listWidget->currentItem()->text())){
                map->deleteType(event->pos().x(), event->pos().y(),ui->listWidget->currentItem()->text());
            } else {
                QJsonObject typeObject;
                typeObject["type"] = ui->listWidget->currentItem()->text();
                map->setPixel(event->pos().x(), event->pos().y(),typeObject);
            }
        }
    } else if(event->button() ==Qt::MiddleButton){
        int index = ui->listWidget->currentRow();
        if(++index == ui->listWidget->count())
            index = 0;
        ui->listWidget->setCurrentRow(index);
    } else {
        map->deletePixel(event->pos().x(), event->pos().y());
    }
    this->repaint();
}

void Editor::mouseMoveEvent(QMouseEvent * event){
    if(event->pos().x()> 0 && event->pos().x()< 480 && event->pos().y()> 0 && event->pos().y()< 480){
        if(event->buttons() == Qt::LeftButton){
            if(ui->listWidget->currentItem() != NULL){
                if(!map->containsType(event->pos().x(), event->pos().y(),ui->listWidget->currentItem()->text())){
                    QJsonObject typeObject;
                    typeObject["type"] = ui->listWidget->currentItem()->text();
                    map->setPixel(event->pos().x(), event->pos().y(),typeObject);
                }
            }
        }
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
       map->saveFile(ui->name->text());
       ui->Save->setEnabled(false);
       this->close();
    } else {
        QMessageBox::information(this, tr("Waring"),tr("Enter a Name") );
    }
}


void Editor::closeEvent(QCloseEvent * event){
    if(ui->Save->isEnabled()){
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Warning",
                                                                tr("Are you sure to quit without saving?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
        }
    }
}


void Editor::on_clear_clicked()
{
    map->clear();
    this->repaint();
}
