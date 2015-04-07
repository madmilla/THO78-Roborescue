#include "mainwindow.h"
#include "quadcopterwindow.h"
#include "ui_mainwindow.h"
#include "atvwindow.h"

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
      newWindow = new QuadCopterWindow();
   }else if(button == ui->ATVButton){
      newWindow = new ATVWindow();
   }else if(button == ui->LidarButton){

   }else if(button == ui->ExitButton){

   }else if(button == ui->MapButton){

   }else if(button == ui->RosbeeButton){

   }

   if(newWindow != nulltpr){
      newWindow->show();
      subwindows.push_back(newWindow);
   }
}
