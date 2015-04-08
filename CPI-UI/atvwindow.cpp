#include "atvwindow.h"
#include "ui_atvwindow.h"

ATVWindow::ATVWindow(ATV * atv, QWidget *parent) :
    QMainWindow(parent),
    atv(atv),
    timer(new QTimer()),
    ui(new Ui::ATVWindow)
{
    ui->setupUi(this);

    connect(ui->abortButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->armButton     , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->shutdownButton, SIGNAL(clicked()), this, SLOT(handleButton()));

    connect(ui->steeringScrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollbarValueChanged(int)));

    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    timer->start(1000);
}

ATVWindow::~ATVWindow() {
    delete ui;
}

void ATVWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;

   if(button == ui->abortButton){
      atv->emergencyStop();
      armed(false);
   }else if(button == ui->armButton){
      if(!ui->armButton->isEnabled()) return;
      atv->arm();
      armed(true);
   }else if(button == ui->shutdownButton){
      atv->stopMission();
      armed(false);
   }
}

void ATVWindow::scrollbarValueChanged(int value){
   if(value < 0){
      atv->turnLeft(-value);
   }else{
      atv->turnRight(value);
   }
}

void ATVWindow::timerTick(){
   ui->batteryStatusBar->setValue(static_cast<int>(atv->batteryStatus()));
   ui->speedLCD->display(atv->speed());
}

void ATVWindow::armed(bool is_armed){
   ui->armButton->setEnabled(!is_armed);
   ui->abortButton->setEnabled(is_armed);
   ui->shutdownButton->setEnabled(is_armed);
   ui->steeringScrollBar->setEnabled(is_armed);
}
