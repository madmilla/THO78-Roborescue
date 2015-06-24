#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"
#include "rosbeewindow.h"
#include "lidarwindow.h"
//#include "mapwindow.h"

MainWindow::MainWindow(Quadcopter &quadcopter, ATV & atv, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    atv(atv),
    quad(quadcopter)
{
    ui->setupUi(this);
    server = new UDPServer(robotManager);
    connect(ui->QuadButton  , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->ATVButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->LidarButton , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->MapButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->RosbeeButton, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->ExitButton  , SIGNAL(clicked()), this, SLOT(handleButton()));
    quadWindow = nullptr;
    atvWindow = nullptr;
    MainWindow::ScanforRosbee();
    MainWindow::ScanforLidar();
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
      if(!quadWindow){
        quadWindow = new QuadCopterWindow(quad, this);
      }
      quadWindow->show();
   }else if(button == ui->ATVButton){
      if(!atvWindow){
        atvWindow = new ATVWindow(atv, this);
      }
      atvWindow->show();
   }else if(button == ui->LidarButton){
      MainWindow::ScanforLidar();
   }else if(button == ui->MapButton){
      //newWindow = new MapWindow(this);
   }else if(button == ui->RosbeeButton){
      MainWindow::ScanforRosbee();
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


void MainWindow::ScanforRosbee(){
    for(auto * robots : robotManager.getRobots<Rosbee>()){
        ui->Rosbeelist->addItem(new QListWidgetItem(QString(robots->getId())));
    }
}

void MainWindow::ScanforLidar(){
    for(auto * robots : robotManager.getRobots<Lidar>()){
        ui->Lidarlist->addItem(new QListWidgetItem(QString(robots->getId())));
    }
}

