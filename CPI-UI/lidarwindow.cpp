#include "lidarwindow.h"
#include "ui_lidarwindow.h"

lidarwindow::lidarwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lidarwindow)
{
    ui->setupUi(this);
}

lidarwindow::~lidarwindow()
{
    delete ui;
}


void lidarwindow::on_setRpm_returnPressed()
{

}

void lidarwindow::on_startLidar_clicked()
{

}

void lidarwindow::on_stopLidar_clicked()
{

}
