#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openFileButton, SIGNAL(released()), this, SLOT(openFile()));
    connect(ui->exitButton, SIGNAL(released()), this, SLOT(exit()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::exit() { //Close the main window, exiting the program.
    this->close();
}

void MainWindow::openFile() { //Opens a file dialog, passes selected file to mapProcessor
    QFileDialog fileDialog;
    mapFile = fileDialog.getOpenFileName(this,tr("Open map file"), "/", tr("Text files (*.txt)"));
    if(m.processMap(mapFile, ui->mapView, ui->legendView)){
        ui->mapView->update();
        qDebug() << "map updated!";
        ui->mapView->show();
        ui->legendView->update();
        qDebug() << "legend updated!";
        ui->legendView->show();
    }
}
