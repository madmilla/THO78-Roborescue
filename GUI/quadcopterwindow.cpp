#include "quadcopterwindow.h"
#include "ui_quadcopterwindow.h"
#include "quadcopter.h"
#include "qdebug.h"



QuadCopterWindow::QuadCopterWindow(Quadcopter& quadcopter, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuadCopterWindow),
	quadcopter{ quadcopter }
{

    quadcopter.registerListener(this);




    ui->setupUi(this);
    ui->armedCheck->setEnabled(false);
    ui->controlsBox->setEnabled(false);
    ui->takeOff_LandButton->setEnabled(false);
    ui->rotorStatusBox->setEnabled(false);
    ui->abortButton->setEnabled(false);
    ui->componentBox->setEnabled(false);

}

QuadCopterWindow::~QuadCopterWindow()
{
    delete ui;
}

void QuadCopterWindow::on_sendMaxAltitudeButton_clicked()
{

}

void QuadCopterWindow::on_armButton_clicked()
{
    if (!quadcopter.isArmed()){
        quadcopter.arm();
        //ui->armedCheck->setChecked(true);
        ui->armButton->setText("Disarm");
        ui->takeOff_LandButton->setEnabled(true);
        ui->abortButton->setEnabled(true);
    }
    else{
        quadcopter.disarm();
        //ui->armedCheck->setChecked(false);
        ui->armButton->setText("Arm");
        ui->takeOff_LandButton->setEnabled(false);
        ui->abortButton->setEnabled(false);
    }
}

void QuadCopterWindow::on_takeOff_LandButton_clicked()
{

}

void QuadCopterWindow::on_restartButton_clicked()
{
    quadcopter.restart();
    qDebug()<< "ehhhehehhh";
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
    ui->armedCheck->setChecked(quadcopter.isArmed());

    qDebug() << quadcopter.isArmed();

}

