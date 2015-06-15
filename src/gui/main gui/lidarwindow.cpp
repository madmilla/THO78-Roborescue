#include "lidarwindow.h"
#include "ui_lidarwindow.h"

LidarWindow::LidarWindow(Lidar &lidar, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lidarwindow()),
    lidar(lidar)
{
    ui->setupUi(this);

    connect(ui->startLidar,SIGNAL(clicked()),this,SLOT(handleButtonLidar()));
    lidarMissionRunning(false);
}



LidarWindow::~LidarWindow(){
    delete ui;
}



void LidarWindow::handleButtonLidar(){
    //! this function will handle the buttoncall and down below it will be processed.
    QPushButton * button = static_cast<QPushButton *>(sender());

    if(button == nullptr) return;

    if(button == ui->startLidar){
        try{
            lidar.startLidar();
            lidarMissionRunning(true);
        }
        catch(...){ //moet een exception gemaakt worden voor het afvangen van geen rpm
            QMessageBox::critical(this,"Error:, No rpm set.", "mission already started");
        }
    }
    else if(button == ui->stopLidar){
        if(!ui->stopLidar->isEnabled()) return;
        lidar.stopLidar();
        lidarMissionRunning(false);
    }
}


void LidarWindow::lidarMissionRunning(bool isRunning){
    //! als de missie start is running false voor het setten
    //! en is stop klaar om ingedrukt te worden
    ui->startLidar->setEnabled(!isRunning);
    ui->stopLidar->setEnabled(isRunning);

}


void LidarWindow::on_startLidar_clicked()
{

}
