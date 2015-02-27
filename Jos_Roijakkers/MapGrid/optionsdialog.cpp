#include "optionsdialog.h"
#include "ui_optionsdialog.h"


optionsDialog::optionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionsDialog)
{
    ui->setupUi(this);
     connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

optionsDialog::~optionsDialog()
{
    delete ui;
}

