#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionExit->setText("Exit");
    ui->actionLoad->setText("Load");
    ui->actionSave->setText("Save");
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    std::cout << "exit pressed \n";
}

void MainWindow::on_actionSave_triggered()
{
    std::cout << "Save pressed \n";
}

void MainWindow::on_actionLoad_triggered()
{
    std::cout << "Load pressed \n";
}
