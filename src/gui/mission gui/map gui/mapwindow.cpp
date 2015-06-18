#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "glwidget.h"
#include <iostream>

MapWindow::MapWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);

    connect(ui->xAxis, SIGNAL(valueChanged(int)), ui->glWidget, SLOT(rotateX(int)));
    connect(ui->yAxis, SIGNAL(valueChanged(int)), ui->glWidget, SLOT(rotateY(int)));
    connect(ui->zAxis, SIGNAL(valueChanged(int)), ui->glWidget, SLOT(rotateZ(int)));

    connect(ui->buttonUp, SIGNAL(clicked()), ui->glWidget, SLOT(panUp()));
    connect(ui->buttonDown, SIGNAL(clicked()), ui->glWidget, SLOT(panDown()));
    connect(ui->buttonLeft, SIGNAL(clicked()), ui->glWidget, SLOT(panLeft()));
    connect(ui->buttonRight, SIGNAL(clicked()), ui->glWidget, SLOT(panRight()));

    connect(ui->zoom, SIGNAL(valueChanged(int)), ui->glWidget, SLOT(zoom(int)));


    connect(ui->glWidget, SIGNAL(xRotationChanged(int)), ui->xAxis, SLOT(setValue(int)));
    connect(ui->glWidget, SIGNAL(yRotationChanged(int)), ui->yAxis, SLOT(setValue(int)));
    connect(ui->glWidget, SIGNAL(zRotationChanged(int)), ui->zAxis, SLOT(setValue(int)));

    connect(ui->glWidget, SIGNAL(zoomChanged(int)), ui->zoom, SLOT(setValue(int)));
}

MapWindow::~MapWindow()
{
    delete ui;
}
