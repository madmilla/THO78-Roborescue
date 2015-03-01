#include "discarddialog.h"
#include "ui_discarddialog.h"

DiscardDialog::DiscardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiscardDialog)
{
    ui->setupUi(this);
}

DiscardDialog::~DiscardDialog()
{
    delete ui;
}
