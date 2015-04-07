#include "atvwindow.h"
#include "ui_atvwindow.h"

ATVWindow::ATVWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ATVWindow)
{
    ui->setupUi(this);

    connect(ui->abortButton   , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->armButton     , SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->shutdownButton, SIGNAL(clicked()), this, SLOT(handleButton()));
}

ATVWindow::~ATVWindow() {
    delete ui;
}

void ATVWindow::handleButton(){
   QPushButton * button = static_cast<QPushButton *>(sender());
   if(button == nullptr) return;

   if(button == ui->abortButton){

   }else if(button == ui->armButton){

   }else if(button == ui->shutdownButton){

   }
}
