#include "rosbeewindow.h"
#include "ui_rosbeewindow.h"

#include "exceptions.h"

#include <QMessageBox>

RosbeeWindow::RosbeeWindow(Rosbee * rosbee, QWidget *parent) :
   QDockWidget(parent),
   rosbee(rosbee),
   ui(new Ui::RosbeeWindow),
   timer(new QTimer())
{
   ui->setupUi(this);

   connect(ui->startButton, SIGNAL(clicked()), this, SLOT(handleButton()));
   connect(ui->abortButton, SIGNAL(clicked()), this, SLOT(handleButton()));
   connect(ui->stopButton , SIGNAL(clicked()), this, SLOT(handleButton()));
   connect(    timer      , SIGNAL(timeout()), this, SLOT(timerTick()));

   timer->start(1000);

   unsigned int result = rosbee->init();
   QLabel * iRL = ui->initResultLabel;
   if(result == 0){
      iRL->setText("All OK");
      QPalette palette = iRL->palette();
      palette.setColor(iRL->foregroundRole(), Qt::green);
      iRL->setPalette(palette);
   }else{
      QString errorComponents = "";
      for(int i = 0; i < 32; i++){
         if((result & (1 << i)) != 0){
            if(errorComponents != ""){
               errorComponents += QString(", ") + QString::number(i);
            }else{
               errorComponents += QString::number(i);
            }
         }
      }

      iRL->setText(tr("Component ids failed: ") + errorComponents);
      QPalette palette = iRL->palette();
      palette.setColor(iRL->foregroundRole(), Qt::red);
      iRL->setPalette(palette);
   }
}

RosbeeWindow::~RosbeeWindow()
{
   delete ui;
}

void RosbeeWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;

   if(button == ui->startButton){
      if(!ui->startButton->isEnabled()) return;

      try{
         //DPoint missionLocation(ui->startLocationLineEdit->text().toStdString());
         rosbee->startMission();
         SetMissionRunning(true);
      }catch(CannotParseException){
         QMessageBox::critical(this, "Error: No valid start location", "No valid start location. Use x, y(, z)");
      }
   } else if(button == ui->abortButton){
      if(!ui->abortButton->isEnabled()) return;

      rosbee->abortMission();
      SetMissionRunning(false);
      ui->startButton->setEnabled(false);
   } else if(button == ui->stopButton){
      if(!ui->stopButton->isEnabled()) return;

      rosbee->stopMission();
      SetMissionRunning(false);
   }
}

void RosbeeWindow::SetMissionRunning(bool is_mission_running){
   ui->startButton          ->setEnabled(!is_mission_running);
   //ui->startLocationLineEdit->setEnabled(!is_mission_running);
   ui->abortButton          ->setEnabled( is_mission_running);
   ui->stopButton           ->setEnabled( is_mission_running);
}

void RosbeeWindow::timerTick(){
   ui->batteryBar->setValue(static_cast<int>(rosbee->batteryStatus()));
   ui->statusValueLabel->setText(QString::fromStdString(rosbee->getStatus()));
}
