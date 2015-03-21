#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
}

NewDialog::~NewDialog()
{
    delete ui;
}

std::pair<int, int> NewDialog::getValues()
{
    return {ui->spinBox->value(), ui->spinBox_2->value()};
}
