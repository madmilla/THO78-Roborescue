#include "atvwindow.h"
#include "ui_atvwindow.h"

ATVWindow::ATVWindow(ATV * atv, QWidget *parent) :
    QMainWindow(parent),
    atv(atv),
    ui(new Ui::ATVWindow)
{
    ui->setupUi(this);

    connect(ui->abortButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->armButton     , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->shutdownButton, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->steeringScrollBar, SIGNAL(valueChanged(int), this, SLOT(scrollbarValueChanged(int)))
}

ATVWindow::~ATVWindow() {
    delete ui;
}

void ATVWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;

   if(button == ui->abortButton){
      atv->abortMission();
   }else if(button == ui->armButton){
      atv->arm();
   }else if(button == ui->shutdownButton){
      atv->stopMission();
   }
}

void ATVWindow::scrollbarValueChanged(int value){
   if(value == 0) atv->
}
