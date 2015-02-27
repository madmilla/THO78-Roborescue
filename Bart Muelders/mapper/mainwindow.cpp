#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <iostream>
#include <string>


MainWindow::MainWindow(ObjectMap & objectMap, QWidget *parent) :
    objectMap(objectMap),
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

    refreshMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshMap(){
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(objectMap.isObject(x, y)){
                ui->map->item(x, y)->setText("");
                ui->map->item(x, y)->setBackgroundColor(QColor(255,0,0));
            }
            else{
                ui->map->item(x, y)->setText(QString::number(objectMap.getHeight(x,y)));
                if(objectMap.vehiclePlaced() && objectMap.vehicleAt(x, y)){
                    ui->map->item(x, y)->setBackgroundColor(QColor(255,255,0));
                }
                else{
                    ui->map->item(x, y)->setBackgroundColor(QColor(255 - objectMap.getHeight(x,y),255 - objectMap.getHeight(x,y),255 - objectMap.getHeight(x,y)));
                }
            }
        }
    }
}


void MainWindow::on_actionClear_clicked(){
    objectMap.clear();
    refreshMap();
}


void MainWindow::on_actionSave_clicked(){
    objectMap.save();
}


void MainWindow::on_actionReload_clicked(){
    objectMap.load();
    refreshMap();
}


void MainWindow::on_heightSelection_valueChanged(int arg1)
{
    objectMap.setHeight(ui->map->currentRow(), ui->map->currentColumn(), arg1);
    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setText(QString::number(arg1));
    if(!objectMap.vehicleAt(ui->map->currentRow(), ui->map->currentColumn())){
        ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255 - arg1,255 - arg1, 255 - arg1));
    }
}


void MainWindow::on_radioDriveable_toggled(bool checked)
{
    ui->heightSelection->setReadOnly(!checked);
    ui->vehicleButton->setEnabled(checked);
    if(checked){
        int height = objectMap.getHeight(ui->map->currentRow(), ui->map->currentColumn());

        ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setText(QString::number(height));
        if(objectMap.vehicleAt(ui->map->currentRow(), ui->map->currentColumn())){
            ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255,255,0));
        }
        else{
            ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255 - height,255 - height, 255 - height));
        }
    }
}

void MainWindow::on_radioStaticObject_toggled(bool checked)
{
   objectMap.setObject(ui->map->currentRow(), ui->map->currentColumn(), checked);

   if(checked){
    ui->heightSelection->setValue(0);

    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setText("");
    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255, 0, 0));
   }
}


void MainWindow::on_map_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    ui->radioStaticObject->setCheckable(true);
    ui->radioDriveable->setCheckable(true);

    bool object = objectMap.isObject(currentRow, currentColumn);

    ui->vehicleButton->setEnabled(!object && !objectMap.vehicleAt(currentRow, currentColumn));

    ui->radioStaticObject->setChecked(object);
    ui->radioDriveable->setChecked(!object);
    ui->heightSelection->setReadOnly(object);

    ui->heightSelection->setValue(objectMap.getHeight(currentRow, currentColumn));
}


void MainWindow::on_vehicleButton_clicked()
{
    if(objectMap.vehiclePlaced()){
        int vx = objectMap.vehicleLocation().x;
        int vy = objectMap.vehicleLocation().y;
        ui->map->item(vx, vy)->setBackgroundColor(QColor(255-objectMap.getHeight(vx, vy), 255-objectMap.getHeight(vx, vy), 255-objectMap.getHeight(vx, vy)));
    }
    objectMap.setVehicle(ui->map->currentRow(), ui->map->currentColumn());
    ui->map->item(ui->map->currentRow(), ui->map->currentColumn())->setBackgroundColor(QColor(255, 255, 0));

    ui->vehicleButton->setEnabled(false);
}
