#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"
#include "rosbeewindow.h"
#include "lidarwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rosbee(new Rosbee())
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
   for(QMainWindow * window : subwindows){
      window->close();
      delete window;
   }
   subwindows.clear();
   delete ui;
}

void MainWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;
   QMainWindow * newWindow = nullptr;

   if(button == ui->QuadButton){
      newWindow = new QuadCopterWindow(this);
   }else if(button == ui->ATVButton){
      newWindow = new ATVWindow(this);
   }else if(button == ui->LidarButton){
      newWindow = new lidarwindow(this);
   }else if(button == ui->MapButton){
      //newWindow - new MapWindow(this);
   }else if(button == ui->RosbeeButton){
      newWindow = new RosbeeWindow(rosbee, this);
   }else if(button == ui->ExitButton){
      for(QMainWindow * window : subwindows){
         window->close();
         delete window;
      }
      subwindows.clear();
      this->close();
   }

   if(newWindow != nullptr){
      newWindow->show();
      subwindows.push_back(newWindow);
   }
}
