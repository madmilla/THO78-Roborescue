#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtWidgets>
#include <QFileDialog>

#include "fileloader.h"
#include "filewriter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enableRadioButtons(false);
}

MainWindow::MainWindow(MapSystem* mapSystem, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mapSystem{mapSystem}
{
    ui->setupUi(this);
    enableRadioButtons(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    enableRadioButtons(true);
    qDebug() << "Trying to get new map";
    Map * m = mapSystem->createNewMap();
    qDebug() << "Trying to set new map";
    ui->mapViewer->setMap(m);
    ui->mapViewer->repaint();
    qDebug("New");
}

void MainWindow::on_actionOpen_triggered()
{
    auto fileName = QFileDialog::getOpenFileName(this,
        "Open Map", "/home/", "Map Files (*.map)");

    qDebug() << "Trying to open map: " << fileName;
    if(fileName != "")
    {
        Map * m = mapSystem->openMap(fileName);
        ui->mapViewer->setMap(m);
        enableRadioButtons(true);
    }
    qDebug("Open");
}

void MainWindow::on_actionSave_as_triggered()
{
    if(mapSystem->canSave())
    {
        auto fileName = QFileDialog::getSaveFileName(this,
                          "Save Map", "/home/", "Map Files (*.map)");
        if(fileName != "")
        {
            mapSystem->saveMap(fileName);
        }
    }
    else
    {
        QMessageBox saveErrorBox;
        saveErrorBox.setText("Unable to save.");
        saveErrorBox.setInformativeText("Please open a map first before trying to save.");
        saveErrorBox.setDefaultButton(QMessageBox::Ok);
        saveErrorBox.exec();
    }
}

void MainWindow::on_actionExit_triggered()
{
    qDebug("Quit");
    QApplication::quit();
}

void MainWindow::enableRadioButtons(bool b)
{
    ui->atvButton->setEnabled(b);
    ui->wallButton->setEnabled(b);
    ui->quadButton->setEnabled(b);
    ui->treeButton->setEnabled(b);
    ui->emptyButton->setEnabled(b);
    ui->actionSave_as->setEnabled(b);
}

void MainWindow::on_emptyButton_clicked()
{
    ui->mapViewer->setSelectedObject(ObjectType::Empty);
}

void MainWindow::on_wallButton_clicked()
{
    ui->mapViewer->setSelectedObject(ObjectType::Wall);
}

void MainWindow::on_treeButton_clicked()
{
    ui->mapViewer->setSelectedObject(ObjectType::Tree);
}

void MainWindow::on_quadButton_clicked()
{
    ui->mapViewer->setSelectedObject(ObjectType::Quad);
}

void MainWindow::on_atvButton_clicked()
{
    ui->mapViewer->setSelectedObject(ObjectType::ATV);
}

