#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"
#include "rosbeewindow.h"
#include "lidarwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   QMainWindow * newWindow = nullptr;

   if(button == ui->QuadButton){
      newWindow = new QuadCopterWindow(this);
   }else if(button == ui->ATVButton){
      newWindow = new ATVWindow(this);
   }else if(button == ui->LidarButton){
      newWindow = new LidarWindow(this);
   }else if(button == ui->MapButton){
      //newWindow - new MapWindow(this);
   }else if(button == ui->RosbeeButton){
      newWindow = new RosbeeWindow(this);
   }else if(button == ui->ExitButton){
      for(QMainWindow * window : subwindows){
         window->close();
         delete window;
      }
      subwindows.clear();
      this->close();
   }

   if(newWindow != nulltpr){
      newWindow->show();
      subwindows.push_back(newWindow);
   }
}
