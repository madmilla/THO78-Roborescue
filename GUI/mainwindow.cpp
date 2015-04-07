#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QuadCopterWindow *qcw = new QuadCopterWindow();
    qcw->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ATVWindow *atvw = new ATVWindow();
    atvw->show();
}
