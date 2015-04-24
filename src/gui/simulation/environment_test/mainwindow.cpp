#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(map != 0){
        delete map;
        map = NULL;
    }
}

void MainWindow::on_newMapButton_clicked()
{
    bool ok;
    QString fileName = QInputDialog::getText(this, "Create map","Map name:",
                                         QLineEdit::Normal,"map name", &ok);
    if(!ok) return;
    int height = QInputDialog::getInt(this, "Create map","Map height:",
                                      newMapBeignSize,newMapMinSize,newMapMaxSize,newMapStepSize, &ok);
    if(!ok) return;
    int width = QInputDialog::getInt(this, "Create map","Map height:",
                                     newMapBeignSize,newMapMinSize,newMapMaxSize,newMapStepSize, &ok);

    if (ok && !fileName.isEmpty()){
        map = new Map(fileName.toStdString() + ".map",height,width);
    }
}

void MainWindow::on_editMapButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Map Files (*.map)");

    if (!fileName.isEmpty()){
        map = new Map(fileName.toStdString());
        editMapWindow = new EditMapWindow(map);
        editMapWindow->show();
    }
}

void MainWindow::on_simulateButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Map Files (*.map)");

    if (!fileName.isEmpty()){
        map = new Map(fileName.toStdString());
        SimulateMapWindow *simulateMapWindow = new SimulateMapWindow(map);
        simulateMapWindow->show();
    }
}
