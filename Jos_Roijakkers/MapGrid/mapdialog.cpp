#include "mapdialog.h"
#include "ui_mapdialog.h"

mapDialog::mapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mapDialog)
{
    ui->setupUi(this);
}

mapDialog::~mapDialog()
{
    delete ui;
}
