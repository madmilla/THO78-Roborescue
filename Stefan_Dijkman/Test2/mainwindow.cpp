#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"

#include <QFileDialog>
#include <QMessageBox>


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

void MainWindow::on_actionOpen_File_triggered()
{
    ui->layout->removeWidget(gridWidget); //removes the previous widget, otherwise the widgets will be added beneath each other

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }else{
        gridWidget = new map(this);
        gridWidget->openFile(file);
        if(ui->layout->isEmpty()){
            ui->layout->addWidget(gridWidget);
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
