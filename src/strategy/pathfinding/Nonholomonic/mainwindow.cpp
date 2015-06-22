#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow),
   status(Status::firstUse)
{
   ui->setupUi(this);
   ui->display->setPathFinding(*new PathFinding(30, Vector<float>(10, 20), *new Map()));

   connect(ui->startButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   connect(ui->obstacelButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   connect(ui->executeButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

   connect(ui->display, SIGNAL(clicked(QPointF)), this, SLOT(fieldClicked(QPointF)));
   connect(ui->display, SIGNAL(executeDone()), this, SLOT(executeDone()));
}

MainWindow::~MainWindow()
{
   delete &ui->display->getPathFinding()->getMap();
   delete ui->display->getPathFinding();
   delete ui;
}

void MainWindow::buttonClicked(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;

   if(button == ui->startButton){
      status = Status::setStart;
   }else if(button == ui->stopButton){
      status = Status::setStop;
   }else if(button == ui->obstacelButton){
      if(status == Status::setObstacel){
         status = Status::None;
         ui->display->pushMapItem();
      }else{
         status = Status::setObstacel;
         ui->display->cancelMapItem();
      }
   } else if(button == ui->executeButton){
      ui->display->execute();
      ui->executeButton->setEnabled(false);
   }

   statusUpdate();
}

void MainWindow::fieldClicked(QPointF position){
   if(status == Status::setStart){
      ui->display->setStartPoint(position);
      status = Status::None;
   }else if(status == Status::setStop){
      ui->display->setStopPoint(position);
      status = Status::None;
   }else if(status == Status::firstUse){
      ui->display->setStartPoint(position);
      status = Status::setStop;
   }else if(status == Status::setObstacel){
      ui->display->getTempMapItem().addPoint(Vector<float>(position.x(), position.y()));
      ui->display->repaint();
   }

   statusUpdate();
}

void MainWindow::statusUpdate(){
   if(status == Status::setStart || status == Status::firstUse){
      ui->infoLabel->setText(tr("Click in map to set start position"));
   }else if(status == Status::setStop){
      ui->infoLabel->setText(tr("Click in map to set stop position"));
   }else if(status == Status::setObstacel){
      ui->infoLabel->setText(tr("Click in map to add obstacel point"));
   }else{
      ui->infoLabel->setText(tr("Choose button to perform action"));
   }

   if(status == Status::setObstacel){
      ui->obstacelButton->setText(tr("Obstacel done"));
   }else{
      ui->obstacelButton->setText(tr("Add obstacel"));
   }
}

void MainWindow::executeDone(){
   ui->executeButton->setEnabled(true);
}
