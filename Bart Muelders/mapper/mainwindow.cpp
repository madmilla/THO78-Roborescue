#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <iostream>
#include <string>
#include <QFile>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionClear, SIGNAL(triggered()),this, SLOT(on_actionClear_clicked()));
    connect(ui->actionReload, SIGNAL(triggered()),this, SLOT(on_actionReload_clicked()));
    connect(ui->actionSave, SIGNAL(triggered()),this, SLOT(on_actionSave_clicked()));

    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            ui->map->setItem(x, y, new QTableWidgetItem());
        }
    }

    loadMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveMap(){
    QFile file("test.map");
    QJsonDocument saveDoc(json);
    file.open(QIODevice::WriteOnly);
    file.write(saveDoc.toJson());
}


void MainWindow::loadMap(){
    QFile file("test.map");
    if(file.exists()){
        file.open(QIODevice::ReadOnly);
        QJsonDocument jsonFile(QJsonDocument::fromJson(file.readAll()));
        json = jsonFile.object();
        refreshMap();
    }
    else{
        clearMap();
    }
}


void MainWindow::clearMap(){
    for(int x = 0; x < 20; ++x){
        QJsonObject yObjects;
        for(int y = 0; y < 20; ++y){
            QJsonObject cell;
            cell["height"] = 0;
            cell["object"] = false;
            yObjects[QString::number(y)] = cell;
        }
        json[QString::number(x)] = yObjects;
    }
    refreshMap();
}


void MainWindow::refreshMap(){
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(isObject(x, y)){
                ui->map->item(x, y)->setText("");
                ui->map->item(x, y)->setBackgroundColor(QColor(255,0,0));
            }
            else{
                ui->map->item(x, y)->setText(QString::number(getHeight(x,y)));
                ui->map->item(x, y)->setBackgroundColor(QColor(255 - getHeight(x,y),255 - getHeight(x,y),255 - getHeight(x,y)));
            }
        }
    }
}


void MainWindow::setHeight(int x, int y, int height)
{
    QJsonObject object = json[QString::number(x)].toObject()[QString::number(y)].toObject();
    QJsonObject xObject = json[QString::number(x)].toObject();

    object["height"] = height;
    xObject[QString::number(y)] = object;

    json[QString::number(x)] = xObject;
}

void MainWindow::setObject(int x, int y, bool object)
{
    QJsonObject o = json[QString::number(x)].toObject()[QString::number(y)].toObject();
    QJsonObject xObject = json[QString::number(x)].toObject();

    o["object"] = object;
    xObject[QString::number(y)] = o;

    json[QString::number(x)] = xObject;
}


bool MainWindow::isObject(int x, int y)
{
    return json[QString::number(x)].toObject()[QString::number(y)].toObject()["object"].toBool();
}

int MainWindow::getHeight(int x, int y)
{
    return json[QString::number(x)].toObject()[QString::number(y)].toObject()["height"].toInt();
}

void MainWindow::on_actionClear_clicked(){
    clearMap();
}


void MainWindow::on_actionSave_clicked(){
    saveMap();
}


void MainWindow::on_actionReload_clicked(){
    loadMap();
}


void MainWindow::on_heightSelection_valueChanged(int arg1)
{
    setHeight(ui->map->currentRow(), ui->map->currentColumn(), arg1);
    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setText(QString::number(arg1));
    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255 - arg1,255 - arg1, 255 - arg1));
}


void MainWindow::on_radioDriveable_toggled(bool checked)
{
    ui->heightSelection->setReadOnly(!checked);

    int height = getHeight(ui->map->currentRow(), ui->map->currentColumn());

    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setText(QString::number(height));
    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255 - height,255 - height, 255 - height));
}

void MainWindow::on_radioObject_toggled(bool checked)
{
   setObject(ui->map->currentRow(), ui->map->currentColumn(), checked);

   ui->heightSelection->setValue(0);

   ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setText("");
   ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255, 0, 0));
}


void MainWindow::on_map_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    //enealbe buttons
    ui->radioObject->setCheckable(true);
    ui->radioDriveable->setCheckable(true);

    bool object = isObject(currentRow, currentColumn);

    ui->radioObject->setChecked(object);
    ui->radioDriveable->setChecked(!object);
    ui->heightSelection->setReadOnly(object);

    ui->heightSelection->setValue(getHeight(currentRow, currentColumn));
}
