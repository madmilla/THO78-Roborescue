#include "lidarwindow.h"
#include "ui_lidarwindow.h"

#include <QMessageBox>

lidarwindow::lidarwindow(lidar * lidar, QWidget *parent) :
    QMainWindow(parent),
    lidar(lidar),
    ui(new Ui::lidarwindow)
{
    ui->setupUi(this);

    connect(ui->startLidar,SIGNAL(clicked()),this,SLOT(handleButtonLidar()));
    connect(ui->stopLidar,SIGNAL(clicked()),this,SLOT(handleButtonLidar()));
    connect(ui->setRpm,SIGNAL(editingFinished()),this,SLOT(setRpm(int));


}

lidarwindow::~lidarwindow()
{
    delete ui;
}

void lidarwindow::handleButtonLidar(){
    //! this function will handle the buttoncall and down below it will be processed.
    QPushButton * button = static_cast<QPushButton *>(sender());

    if(button == nullptr) return;

    if(button == ui->startLidar){
        try{
            lidar->startLidar();
            lidarMissionRunning(true);
        }
        catch(...){ //moet een exception gemaakt worden voor het afvangen van geen rpm
            QMessageBox::critical(this,"Error:, No rpm set.", "mission already started");
        }
    }
    else if(button == ui->stopLidar){
        if(!ui->stopLidar->isEnabled()) return;
        lidar->stopLidar();
        lidarMissionRunning(true);
    }
}


void lidarwindow::lidarMissionRunning(bool isRunning){
    //! als de missie start is running false voor het setten
    //! en is stop klaar om ingedrukt te worden
    ui->startLidar->setEnabled(!isRunning);
    ui->stopLidar->setEnabled(isRunning);

}


