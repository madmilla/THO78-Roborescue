#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include "fileloader.h"
#include "filewriter.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    ui->mapViewer->setMap(new Map);
    ui->mapViewer->repaint();
    qDebug("New");
}

void MainWindow::on_actionOpen_triggered()
{
    enableRadioButtons(true);
    FileLoader fileLoader;
    ui->mapViewer->setMap(fileLoader.openMap(this));
    qDebug("Open");
}

void MainWindow::on_actionSave_as_triggered()
{
    Map* map = ui->mapViewer->getMap();
    if(map == nullptr)
    {
        QMessageBox saveErrorBox;
        saveErrorBox.setText("Unable to save.");
        saveErrorBox.setInformativeText("Please open a map first before trying to save.");
        saveErrorBox.setDefaultButton(QMessageBox::Ok);
        int ret = saveErrorBox.exec();
    }
    else
    {
        FileWriter fileWriter(map);
        fileWriter.saveFile(this);
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

