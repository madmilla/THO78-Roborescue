#include "editmapwindow.h"
#include "ui_editmapwindow.h"

EditMapWindow::EditMapWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMapWindow)
{
    ui->setupUi(this);
}

EditMapWindow::~EditMapWindow()
{
    delete ui;
}

void EditMapWindow::showMap(Map *map)
{
    mapLayout = map->getMap();
}

void EditMapWindow::on_obstacleButton_clicked()
{

}

void EditMapWindow::on_saveMapButton_clicked()
{

}
