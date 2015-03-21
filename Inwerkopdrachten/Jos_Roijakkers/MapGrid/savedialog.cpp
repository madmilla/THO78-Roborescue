#include "savedialog.h"
#include "ui_savedialog.h"

saveDialog::saveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveDialog)
{
    ui->setupUi(this);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

saveDialog::~saveDialog()
{
    delete ui;
}

void saveDialog::on_saveButton_clicked()
{

}
