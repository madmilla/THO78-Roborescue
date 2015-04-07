#include "quadcopterwindow.h"
#include "ui_quadcopterwindow.h"


QuadCopterWindow::QuadCopterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuadCopterWindow)
{
    qc = new Quadcopter();
    ui->setupUi(this);
}

QuadCopterWindow::~QuadCopterWindow()
{
    delete ui;
}



void QuadCopterWindow::on_toggleControlModeButton_clicked()
{

}

void QuadCopterWindow::on_sendMaxAltitudeButton_clicked()
{

}

void QuadCopterWindow::on_armButton_clicked()
{

}

void QuadCopterWindow::on_takeOff_LandButton_clicked()
{

}

void QuadCopterWindow::on_shutdownButton_clicked()
{

}

void QuadCopterWindow::on_abortButton_clicked()
{

}

void QuadCopterWindow::on_sendButton_clicked()
{

}

void QuadCopterWindow::on_forwardButton_pressed()
{

}

void QuadCopterWindow::on_rightButton_pressed()
{

}

void QuadCopterWindow::on_backwardButton_pressed()
{

}

void QuadCopterWindow::on_leftButton_pressed()
{

}
