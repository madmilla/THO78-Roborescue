#include "lidarwindow.h"
#include "ui_lidarwindow.h"

//! create the lidar and qwidget
LidarWindow::LidarWindow(Lidar &lidar, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LidarWindow()),
    lidar(lidar)
{
    ui->setupUi(this);
    connect(ui->startLidar,SIGNAL(clicked()),this,SLOT(handleButtonLidar()));
    lidarMissionRunning(false);
}


//! delete the lidarwindow
LidarWindow::~LidarWindow(){
    delete ui;
}

void LidarWindow::handleButtonLidar(){
    //! this function will handle the buttoncall and down below it will be processed.
    QPushButton * button = static_cast<QPushButton *>(sender());

    if(button == nullptr) return;
    //! startlidar has been pressed
    if(button == ui->startLidar){
        try{
            //lidar.Start();
            //lidarMissionRunning(true);
        }
    //! catch if the lidar already has been started.
        catch(...){
            //QMessageBox::critical(this,"Lidar has already started");
        }
    }
    /*else if(button == ui->stopLidar){
        if(!ui->stopLidar->isEnabled()) return;
        //lidar.stopLidar();
        lidarMissionRunning(false);
    }*/
}


void LidarWindow::lidarMissionRunning(bool isRunning){
    //! als de missie start is running false voor het setten
    //! en is stop klaar om ingedrukt te worden
    ui->startLidar->setEnabled(!isRunning);
    //ui->stopLidar->setEnabled(isRunning);

}


/*void LidarWindow::on_startLidar_clicked()
{

}*/
