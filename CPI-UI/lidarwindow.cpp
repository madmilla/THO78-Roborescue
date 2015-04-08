#include "lidarwindow.h"
#include "ui_lidarwindow.h"



lidarwindow::lidarwindow(lidar * l, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lidarwindow()),
    l(l),
    timer(new QTimer())
{
    ui->setupUi(this);

    connect(ui->startLidar,SIGNAL(clicked()),this,SLOT(handleButtonLidar()));
    connect(ui->stopLidar,SIGNAL(clicked()),this,SLOT(handleButtonLidar()));
    connect(ui->setRpm,SIGNAL(returnPressed()),this,SLOT(setRpm()));
    connect(timer,SIGNAL(timeout()),this,SLOT(timerPassed()));

    timer->start(1000);
    lidarMissionRunning(false);

}



lidarwindow::~lidarwindow(){
    delete ui;
}

void lidarwindow::setRpm(){
        qDebug() << "dit is het ingevuld rpm " << ui->setRpm->text();

}

void lidarwindow::handleButtonLidar(){
    //! this function will handle the buttoncall and down below it will be processed.
    QPushButton * button = static_cast<QPushButton *>(sender());

    if(button == nullptr) return;

    if(button == ui->startLidar){
        try{
            l->startLidar();
            lidarMissionRunning(true);
        }
        catch(...){ //moet een exception gemaakt worden voor het afvangen van geen rpm
            QMessageBox::critical(this,"Error:, No rpm set.", "mission already started");
        }
    }
    else if(button == ui->stopLidar){
        if(!ui->stopLidar->isEnabled()) return;
        l->stopLidar();
        lidarMissionRunning(false);
    }
}


void lidarwindow::lidarMissionRunning(bool isRunning){
    //! als de missie start is running false voor het setten
    //! en is stop klaar om ingedrukt te worden
    ui->startLidar->setEnabled(!isRunning);
    ui->stopLidar->setEnabled(isRunning);

}


void lidarwindow::timerPassed(){
    ui->showRpm->setNum(l->rpmStatus());
    ui->showStatus->setText(QString::fromStdString(l->getStatus()));
}

