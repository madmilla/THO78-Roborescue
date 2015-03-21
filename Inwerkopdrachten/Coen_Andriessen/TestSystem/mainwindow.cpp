#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QtGui>
#include <stdio.h>
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    map = new Map;
    setCentralWidget(map);
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveMap()));

    loadAct = new QAction(tr("&Load"), this);
    loadAct->setShortcuts(QKeySequence::Open);
    loadAct->setStatusTip(tr("Open the document from disk"));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadMap()));

    closeAct = new QAction(tr("&Close"), this);
    closeAct->setShortcuts(QKeySequence::Close);
    closeAct->setStatusTip(tr("Close"));
    connect(closeAct, SIGNAL(triggered()), this, SLOT(closeMap()));


    fileMenu = menuBar()->addMenu(tr("&Map"));
    fileMenu->addAction(saveAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(closeAct);
    setMinimumSize(480, 480);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showMap()
{

}

void MainWindow::saveMap()
{
    std::cout << "Save" << std::endl;
}

void MainWindow::closeMap()
{
    QCoreApplication::quit();
}

void MainWindow::loadMap()
{
    map->getMap("C:\\Users\\Coen\\Documents\\GitHub\\THO78-Roborescue\\Coen_Andriessen\\TestSystem\\Mapping.txt");
    map->update();
}

