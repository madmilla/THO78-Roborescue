#include "exitDialog.h"
#include "ui_exitDialog.h"

exitDialog::exitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exitDialog)
{
    ui->setupUi(this);
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(quit()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

exitDialog::~exitDialog()
{
    delete ui;
}

void exitDialog::quit(){
    exit(0);
}
