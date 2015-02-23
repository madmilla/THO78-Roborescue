#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapreadfailure.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    map{nullptr},
    isDisplayingFile{false}
{
    ui->setupUi(this);

    connect(ui->actionClose_program, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionCreate_new, SIGNAL(triggered()), this, SLOT(createFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
}

MainWindow::~MainWindow() {
    closeFile();
    delete ui;
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Data (*.dat)"));
    if(fileName != nullptr){
        openFile(fileName.toStdString());
    }
}

void MainWindow::openFile(std::string filename){
    closeFile();
    try{
        map = new Map(filename);
        setDisplayingFile(true);
    }catch(MapReadFailure prf){
        QMessageBox::critical(
                    this,
                    tr("Error while loading file"),
                    QString::fromStdString(std::string{"Error while loading file: "} + prf.what())
        );
        closeFile();
    }
}

void MainWindow::createFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "/home", tr("Data (*.dat)"));
    if(fileName != nullptr){
        bool ok;
        int width = QInputDialog::getInt(this, tr("Width of map"), "Input the WIDTH of the map", 1, 1, 2147483647, 1, &ok);
        if(!ok) return;
        int height = QInputDialog::getInt(this, tr("Height of map"), "Input the HEIGHT of the map", 1, 1, 2147483647, 1, &ok);
        if(!ok) return;
        Map::createEmpty(fileName.toStdString(), (unsigned int)height, (unsigned int)width);
        openFile(fileName.toStdString());
    }
}

void MainWindow::saveFile(){
    if(map != nullptr) map->save();
}

void MainWindow::closeFile(){
    if(map != nullptr){
        delete map;
        map = nullptr;
        setDisplayingFile(false);
    }
}

void MainWindow::setDisplayingFile(bool value){
    if(value != isDisplayingFile){
        ui->actionClose->setEnabled(value);
        ui->actionSave->setEnabled(value);
        ui->actionCreate_new->setEnabled(!value);
        ui->actionOpen->setEnabled(!value);
        isDisplayingFile = value;
    }
}
