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
            //lidar.Start(0,0,0);
        }
    //! catch if the lidar already has been started.
        catch(...){
            //QMessageBox::critical(this,"Lidar has already started");
        }
    }

}


