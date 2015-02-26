#include "mainwindow.h"
#include "ui_mainwindow.h"
bool clicked = false;

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
    char* text;
    if(clicked == false)
    {
        clicked = true;
        text = "test";
    }
    else
    {
        clicked = false;
        text = "tekst";
    }
    ui->label->setText(text);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect rect(10.0, 20.0, 80.0, 60.0);
    painter.drawRect(rect);
    painter.fillRect(rect,Qt::red);

}
