#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"
#include "rosbeewindow.h"
#include "lidarwindow.h"
#include "mapwindow.h"

MainWindow::MainWindow(Quadcopter &quadcopter, ATV & atv, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    atv(atv),
    quad(quadcopter)
{
    ui->setupUi(this);

    connect(ui->QuadButton  , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->ATVButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->LidarButton , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->MapButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->RosbeeButton, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->ExitButton  , SIGNAL(clicked()), this, SLOT(handleButton()));
}

MainWindow::~MainWindow(){
   for(QMainWindow * window : subWindows){
      window->close();
      delete window;
   }
   subWindows.clear();
   delete ui;
}

void MainWindow::checkZombies(){
   std::vector<QMainWindow *> newSubWindows;
   for(QMainWindow * subWindow : subWindows){
      if(subWindow->isVisible()){
         newSubWindows.push_back(subWindow);
      }else{
         delete subWindow;
      }
   }
   subWindows = newSubWindows;
}

void MainWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;
   QMainWindow * newWindow = nullptr;

   if(button == ui->QuadButton){
      newWindow = new QuadCopterWindow(quad, this);
   }else if(button == ui->ATVButton){
      newWindow = new ATVWindow(atv, this);
   }else if(button == ui->LidarButton){
      newWindow = new lidarwindow(robotManager->getRobot<Lidar>(lidarId), this);
   }else if(button == ui->MapButton){
      newWindow = new MapWindow(this);
   }else if(button == ui->RosbeeButton){
      newWindow = new RosbeeWindow(robotManager->getRobot<Rosbee>(rosbeeId), this);
   }else if(button == ui->ExitButton){
      for(QMainWindow * window : subWindows){
         window->close();
      }
      this->close();
   }

   if(newWindow != nullptr){
      newWindow->show();
      subWindows.push_back(newWindow);
   }

   checkZombies();
}
