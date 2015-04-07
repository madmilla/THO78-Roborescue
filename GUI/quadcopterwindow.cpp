#include "quadcopterwindow.h"
#include "ui_quadcopterwindow.h"


QuadCopterWindow::QuadCopterWindow(QWidget *parent, Quadcopter& quadcopter) :
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
<<<<<<< HEAD
    qc->arm();
    ui->statusBox->setEnabled(true);
=======
	quadcopter.arm();
>>>>>>> origin/master
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
	ui->pitchValue.display(quadcopter.getPitch());
	ui->rollValue.display(quadcopter.getRoll());
	ui->yawValue.display(quadcopter.getYaw());
	ui->headingValue.display(quadcopter.getHeading());
	ui->altitudeValue.display(quadcopter.getAltitude());
	std::string mode;
	mode << quadcopter.getFlightMode();
	ui->currentModeValue.setText(mode);
}
