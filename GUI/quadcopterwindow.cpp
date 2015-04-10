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
    ui->messageOutput->setReadOnly(true);

    //ui->maxAltitudeInput->setValidator((new QIntValidator(0, 50, this)));

    //ui->maxAltitudeInput->setInputMask("999");
    //ui->maxAltitudeInput->setText("");
    //ui->controlsBox->setEnabled(false);
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

    ui->messageOutput->append("Send Max Altitude Button Clicked With Value ");
    ui->messageOutput->append(ui->maxAltitudeInput->textFromValue(ui->maxAltitudeInput->value()));
    quadcopter.changeAltitude((int)ui->maxAltitudeInput->value());

}

void QuadCopterWindow::on_armButton_clicked()
{
    ui->messageOutput->append("Arm / Disarm Button Clicked");
    if (!quadcopter.isArmed()){
        quadcopter.arm();

    }
    else{
        quadcopter.disarm();

    }
}

void QuadCopterWindow::on_takeOff_LandButton_clicked()
{
    ui->messageOutput->append("Take Off / Land Button Clicked with Max Altitude of: ");
    ui->messageOutput->append(ui->maxAltitudeInput->textFromValue(ui->maxAltitudeInput->value()));
    quadcopter.liftOff((int)ui->maxAltitudeInput->value());
}

void QuadCopterWindow::on_restartButton_clicked()
{
    ui->messageOutput->append("Restart Button Clicked");
    quadcopter.shutdown();

}

void QuadCopterWindow::on_abortButton_clicked()
{
    ui->messageOutput->append("Abort Button Clicked");
    quadcopter.land();
}


void QuadCopterWindow::notifyListener(Subject& subject, StatusText statusText)
{
    ui->pitchValue->display(quadcopter.getPitch());
    ui->rotationValue->display(quadcopter.getRoll());
    ui->yawValue->display(quadcopter.getYaw());
    ui->headingValue->display(quadcopter.getHeading());
    ui->altitudeValue->display(quadcopter.getAltitude());
    ui->armedCheck->setChecked(quadcopter.isArmed());

    if (ui->armedCheck->isChecked()){
        ui->armButton->setText("Disarm");
        ui->takeOff_LandButton->setEnabled(true);
        ui->abortButton->setEnabled(true);
    }
    else {
        ui->armButton->setText("Arm");
        ui->takeOff_LandButton->setEnabled(false);
        ui->abortButton->setEnabled(false);
    }

    std::string printable = "Unknown";
    for (auto & pair : statusTextMap)
    {
        if (pair.second == statusText)
        {
            printable = pair.first;
            break;
        }
    }
    if (statusText != StatusText::NONE){
        qDebug() << printable.c_str();
        ui->messageOutput->append(printable.c_str());
    }
    //qDebug() << printable.c_str();

}

