#include "loaddialog.h"
#include "ui_loaddialog.h"

loadDialog::loadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadDialog)
{
    ui->setupUi(this);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

loadDialog::~loadDialog()
{
    delete ui;
}

void loadDialog::on_LoadButton_clicked()
{

}
