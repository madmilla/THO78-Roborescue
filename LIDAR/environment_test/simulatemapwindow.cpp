#include "simulatemapwindow.h"
#include "ui_simulatemapwindow.h"

SimulateMapWindow::SimulateMapWindow(Map *map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulateMapWindow),
    map(map)
{
    ui->setupUi(this);
}

SimulateMapWindow::~SimulateMapWindow()
{
    delete ui;
}

void SimulateMapWindow::on_simulateButton_clicked()
{

}
