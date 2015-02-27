#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "savedialog.h"
#include "mapdata.h"

MapWindow::MapWindow(QWidget *MainWindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow),
    MainWindow(MainWindow)
{
    ui->setupUi(this);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    for(int x = 0; x < cellsX; ++x){
        for(int y = 0; y < cellsY; ++y){
            ui->tableWidget->setItem(x, y, new QTableWidgetItem());
        }
    }
}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::on_actionSave_triggered()
{
    saveDialog svDialog;
    svDialog.setModal(true);
    svDialog.exec();
}

void MapWindow::closeEvent(QCloseEvent *event)
{
    MainWindow->setVisible(true);
}

void MapWindow::on_Empty_radioButton_toggled(bool checked)
{
    if(checked){

    }
}

void MapWindow::on_Obstacle_radioButton_toggled(bool checked)
{
    if(checked){

    }
}

void MapWindow::on_Quadcopter_radioButton_toggled(bool checked)
{
    if(checked){

    }
}

void MapWindow::on_ATV_radioButton_toggled(bool checked)
{
    if(checked){

    }
}

void MapWindow::on_Rosbee_radioButton_toggled(bool checked)
{
    if(checked){

    }
}

void MapWindow::on_randomButton_clicked()
{

}
