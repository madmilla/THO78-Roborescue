#include "quadcopterwindow.h"
#include "ui_quadcopterwindow.h"

QuadCopterWindow::QuadCopterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuadCopterWindow)
{
    ui->setupUi(this);
}

QuadCopterWindow::~QuadCopterWindow()
{
    delete ui;
}
