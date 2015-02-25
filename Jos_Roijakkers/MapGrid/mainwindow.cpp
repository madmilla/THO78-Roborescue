#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exitDialog.h"
#include "mapwindow.h"
#include "loaddialog.h"
#include "savedialog.h"
#include "optionsdialog.h"
#include "stdlib.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_sliderMoved(int position)
{

    if(position > oldValue){
        ui->label_3->setGeometry(ui->label_3->pos().x(),ui->label_3->pos().y()+1,ui->label_3->height(),ui->label_3->width());
    }
    else{
        ui->label_3->setGeometry(ui->label_3->pos().x(),ui->label_3->pos().y()-1,ui->label_3->height(),ui->label_3->width());
    }
    oldValue = position;
}

void MainWindow::on_actionExit_triggered()
{
    exitDialog exDialog;
    exDialog.setModal(true);
    exDialog.exec();
}

void MainWindow::on_actionNew_Grid_triggered()
{
    mpWindow = new MapWindow(this);
    mpWindow->show();
    this->setVisible(false);
}

void MainWindow::on_actionLoad_triggered()
{
    loadDialog ldDialog;
    ldDialog.setModal(true);
    ldDialog.exec();
}

void MainWindow::on_actionOptions_triggered()
{
    optionsDialog opDialog;
    opDialog.setModal(true);
    opDialog.exec();
}


