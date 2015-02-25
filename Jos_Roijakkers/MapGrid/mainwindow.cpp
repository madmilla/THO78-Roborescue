#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exitDialog.h"
#include "mapdialog.h"
#include "loaddialog.h"
#include "savedialog.h"
#include "optionsdialog.h"


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
    mapDialog mpDialog;
    mpDialog.setModal(true);
    mpDialog.exec();
}

void MainWindow::on_actionLoad_triggered()
{
    loadDialog ldDialog;
    ldDialog.setModal(true);
    ldDialog.exec();
}

void MainWindow::on_actionSave_triggered()
{
    saveDialog svDialog;
    svDialog.setModal(true);
    svDialog.exec();
}

void MainWindow::on_actionOptions_triggered()
{
    optionsDialog opDialog;
    opDialog.setModal(true);
    opDialog.exec();
}
