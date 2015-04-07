#include "atvwindow.h"
#include "ui_atvwindow.h"

ATVWindow::ATVWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATVWindow)
{
    ui->setupUi(this);
}

ATVWindow::~ATVWindow()
{
    delete ui;
}
