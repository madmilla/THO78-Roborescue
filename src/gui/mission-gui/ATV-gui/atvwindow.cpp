#include "atvwindow.h"
#include "ui_atvwindow.h"

#include <QtCore/QDebug>

ATVWindow::ATVWindow(ATV & atv, QWidget *parent) :
    QMainWindow(parent),
    atv(atv),
    ui(new Ui::ATVWindow)
{
    ui->setupUi(this);

    //atv.registerListener(this);

    connect(ui->abortButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->shutdownButton, SIGNAL(clicked()), this, SLOT(handleButton()));

    connect(ui->steeringScrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollbarValueChanged(int)));
}

ATVWindow::~ATVWindow() {
    delete ui;
}

void ATVWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;

   if(button == ui->abortButton){
      if(!ui->abortButton->isEnabled()) return;
   }else if(button == ui->shutdownButton){
      if(!ui->shutdownButton->isEnabled()) return;
      atv.shutdown();
   }
}

void ATVWindow::scrollbarValueChanged(int value){
   value = 0; //resolve warning
   ui->steeringScrollBar->setValue(atv.getSteeringDirection());
}

void ATVWindow::notifyListener(Subject&, StatusText statusText){
   ui->speedLCD->display(atv.getGroundSpeed());
   ui->dialLCD->display(atv.getHeading());
   ui->batteryStatusBar->setValue(atv.getBatteryRemaining());
   ui->steeringScrollBar->setValue(atv.getSteeringDirection());

   std::string printable = "Unknown";
   for (auto & pair : statusTextMap)
   {
       if (pair.second == statusText)
       {
           printable = pair.first;
           break;
       }
   }
   if (statusText != StatusText::NONE){
       qDebug() << printable.c_str();
       ui->messageOutput->append(printable.c_str());
   }
}
