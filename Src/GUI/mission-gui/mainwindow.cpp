#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"
#include "rosbeewindow.h"
#include "lidarwindow.h"

//#include "mapwindow.h"

MainWindow::MainWindow(UDPServer & server,Quadcopter &quadcopter, ATV & atv, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    atv(atv),
    quad(quadcopter),
	server(server)
{
    ui->setupUi(this);
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
    //ui->Rosbeelist->addItem(new QListWidgetItem(QString("test1")));
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

void MainWindow::on_Rosbeelist_itemClicked(QListWidgetItem * item){
    for(auto * robots : robotManager.getRobots<Rosbee>()){
        if(item->text()== "Rosbee "+QString::number(robots->getId())){
            QMainWindow * rosbeewindow = new RosbeeWindow(*robots,this);
            rosbeewindow->show();
            rosbeewindow->setWindowTitle(item->text());
            break;
        }
    }
}

void MainWindow::on_Lidarlist_itemClicked(QListWidgetItem *item){
    for(auto * robots : robotManager.getRobots<Lidar>()){
        if(item->text() == "Lidar "+QString::number(robots->getId())){
            QMainWindow * lidarwindow = new LidarWindow(*robots,this);
            lidarwindow->setWindowTitle(item->text());
            lidarwindow->show();
            break;
        }
    }
}

void MainWindow::ScanforRosbee(){
    std::cout<< robotManager.getRobots<Rosbee>().size();
    for(auto * robots : robotManager.getRobots<Rosbee>()){
        bool found = false;
        for(int row = 0; row <ui->Rosbeelist->count();row++ ){
            if (ui->Rosbeelist->item(row)->text() == "Rosbee "+QString::number(robots->getId())){
                found = true;
                break;
            }
        }
         if(!found){
            ui->Rosbeelist->addItem(new QListWidgetItem("Rosbee "+QString::number((robots->getId()))));
        }
    }
}

void MainWindow::ScanforLidar(){
    for(auto * robots : robotManager.getRobots<Lidar>()){
        bool found = false;
        for(int row = 0; row <ui->Lidarlist->count();row++ ){
            if (ui->Lidarlist->item(row)->text() == "Lidar "+QString::number(robots->getId())){
                found = true;
                break;
            }
        }
         if(!found){
            ui->Lidarlist->addItem(new QListWidgetItem("Lidar "+QString::number((robots->getId()))));
        }
    }
}




