#include <QtWidgets>
#include <iostream>
#include "mainwindow.h"
#include "map.h"
#include "mapcanvas.h"
#include "route.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    map = new Map;
//    mapCanvas = new MapCanvas;
//    setCentralWidget(mapCanvas);

//    mapCanvas->setMap(map);
    //test

    createActions();
    createMenus();

    setWindowTitle(tr("MapEditor"));
    setMinimumSize(480, 520);
    resize(480, 480);
}

MainWindow::~MainWindow(){

}

void MainWindow::newFile(){
    map = new Map;
    mapCanvas->setMap(map);
}

void MainWindow::open(){
    QStringList filePath = QFileDialog::getOpenFileName(this,
            tr("Open map"), "Maps/",
            tr("Map (*.map)")).split("/");
    if(filePath.isEmpty()){
        return;
    }
    QStringList file = filePath.value(filePath.length() -1).split(".");
    QString fileName = file.value(file.length() -2);

    map = Map::loadFromFile(fileName.toStdString().c_str());
    mapCanvas->setMap(map);
    mapCanvas->update();
    std::cout<<"opened"<<std::endl;
}

void MainWindow::save(){
    QStringList filePath = QFileDialog::getOpenFileName(this,
            tr("Open map"), "Maps/",
            tr("Map (*.map)")).split("/");
    if(filePath.isEmpty()){
        return;
    }
    QStringList file = filePath.value(filePath.length() -1).split(".");
    QString fileName = file.value(file.length() -2);

    map->saveToFile(fileName.toStdString().c_str());
    std::cout<<"saved"<<std::endl;
}

void MainWindow::createRoute(){
    Route atvRoute;

    //quadroute->createRoute(map->getObjectMatrix(), map);
    mapCanvas->update();
}

void MainWindow::createActions(){
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    createRouteAct = new QAction(tr("&Create Route"), this);
    createRouteAct->setShortcuts(QKeySequence::Copy);
    createRouteAct->setStatusTip(tr("Create route from quad to finish"));
    connect(createRouteAct, SIGNAL(triggered()), this, SLOT(createRoute()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    runMenu = menuBar()->addMenu(tr("&Run"));
    runMenu->addAction(createRouteAct);
}
