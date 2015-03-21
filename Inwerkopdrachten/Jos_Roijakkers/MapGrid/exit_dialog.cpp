#include "exit_dialog.h"
#include "ui_exit_dialog.h"

Exit_Dialog::Exit_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exit_Dialog)
{
    ui->setupUi(this);
}

Exit_Dialog::~Exit_Dialog()
{
    delete ui;
}
