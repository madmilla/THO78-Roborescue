#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapdisplaywidget.h"
#include "map.h"
#include "mapgraphicsview.h"
#include "newdialog.h"
#include "discarddialog.h"
#include <QFileDialog>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    filename(""),
    saved(true)
{
    ui->setupUi(this);
    MapGraphicsView *view = new MapGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene;
    display = new MapDisplayWidget;
    scene->addWidget(display);
    view->setScene(scene);
    setCentralWidget(view);

    connectSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSignals()
{
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newActionTriggered()));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openActionTriggered()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveActionTriggered()));
    connect(ui->actionSave_As,SIGNAL(triggered()),this,SLOT(saveAsActionTriggered()));

    connect(ui->actionGrassTile,SIGNAL(triggered()),display,SLOT(setGrassTile()));
    connect(ui->actionDirtTile,SIGNAL(triggered()),display,SLOT(setDirtTile()));
    connect(ui->actionConcreteTile,SIGNAL(triggered()),display,SLOT(setConcreteTile()));
    connect(ui->actionWaterTile,SIGNAL(triggered()),display,SLOT(setWaterTile()));
    connect(ui->actionEmptyTile,SIGNAL(triggered()),display,SLOT(setEmptyTile()));
}

void MainWindow::saveOrDiscardChanges()
{
    DiscardDialog discardDialog;
    if(discardDialog.exec() == QDialog::Accepted)
    {
        emit ui->actionSave->triggered();
    }
}

void MainWindow::newActionTriggered()
{
    if(!saved)
    {
        saveOrDiscardChanges();
    }
    NewDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted)
    {
        auto mapDimension = dialog.getValues();
        currentMap = new Map(mapDimension.first,mapDimension.second);
        display->setCurrentMap(currentMap);
        saved = false;
    }
}

void MainWindow::openActionTriggered()
{
    if(!saved)
    {
        saveOrDiscardChanges();
    }
    filename = QFileDialog::getOpenFileName(this, tr("Open Map"), QString(), tr("Map File (*.map);;All Files(*)"));
    if(!filename.isEmpty())
    {
        loadMapFile();
    }
}

void MainWindow::saveActionTriggered()
{
    if(currentMap)
    {
        filename = QFileDialog::getSaveFileName(this, tr("Save Map"), QString(), tr("Map File (*.map);;All Files(*)"));
        if(!filename.isEmpty())
        {
            saveMapFile();
        }
    }
}

void MainWindow::saveAsActionTriggered()
{
    if(currentMap)
    {
        if(!filename.isEmpty())
        {
            saveMapFile();
        }
        else
        {
            emit ui->actionSave->triggered();
        }
    }
}

void MainWindow::saveMapFile()
{
    std::ofstream mapFile(filename.toStdString().c_str());
    mapFile << *currentMap;
    mapFile.close();
    saved = true;
}

void MainWindow::loadMapFile()
{
    std::ifstream mapFile(filename.toStdString().c_str());
    if(mapFile)
    {
        currentMap = new Map();
        mapFile >> *currentMap;
        mapFile.close();
        display->setCurrentMap(currentMap);
    }
}
