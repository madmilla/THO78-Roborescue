#include "quadcopterwindow.h"
#include "ui_quadcopterwindow.h"
#include "quadcopter.h"

QuadCopterWindow::QuadCopterWindow(Quadcopter& quadcopter, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuadCopterWindow),
	quadcopter{ quadcopter }
{
    ui->setupUi(this);
    //ui->statusBox->setEnabled(false);

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
    ui->statusBox->setEnabled(true);
    quadcopter.arm();
}

void QuadCopterWindow::on_takeOff_LandButton_clicked()
{

}

void QuadCopterWindow::on_shutdownButton_clicked()
{
	quadcopter.shutdown();
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

void QuadCopterWindow::notifyListener(Subject& subject)
{
    ui->pitchValue->display(quadcopter.getPitch());
    ui->rotationValue->display(quadcopter.getRoll());
    ui->yawValue->display(quadcopter.getYaw());
    ui->headingValue->display(quadcopter.getHeading());
    ui->altitudeValue->display(quadcopter.getAltitude());
}
