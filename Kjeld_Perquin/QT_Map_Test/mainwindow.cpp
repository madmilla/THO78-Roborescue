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

    connect(ui->actionGrassTile,SIGNAL(triggered()),display,SLOT(setGrassTile()));
    connect(ui->actionDirtTile,SIGNAL(triggered()),display,SLOT(setDirtTile()));
    connect(ui->actionConcreteTile,SIGNAL(triggered()),display,SLOT(setConcreteTile()));
    connect(ui->actionWaterTile,SIGNAL(triggered()),display,SLOT(setWaterTile()));
    connect(ui->actionEmptyTile,SIGNAL(triggered()),display,SLOT(setEmptyTile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveMap()
{
    DiscardDialog discardDialog;
    if(discardDialog.exec() == QDialog::Accepted)
    {
        emit ui->actionSave->triggered();
    }
}

void MainWindow::on_actionNew_triggered()
{
    if(!saved)
    {
        saveMap();
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

void MainWindow::on_actionOpen_triggered()
{
    if(!saved)
    {
        saveMap();
    }
    filename = QFileDialog::getOpenFileName(this, tr("Open Map"), QString(), tr("Map File (*.map);;All Files(*)"));
    if(!filename.isEmpty())
    {
        std::ifstream mapFile;
        mapFile.open(filename.toStdString().c_str());
        if(mapFile)
        {
            int rows, cols;
            mapFile >> rows >> cols;
            currentMap = new Map(rows,cols);
            mapFile >> *currentMap;
            mapFile.close();
            display->setCurrentMap(currentMap);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(currentMap)
    {
        filename = QFileDialog::getSaveFileName(this, tr("Save Map"), QString(), tr("Map File (*.map);;All Files(*)"));
        if(!filename.isEmpty())
        {
            std::ofstream mapFile;
            mapFile.open(filename.toStdString().c_str());
            mapFile << *currentMap;
            mapFile.close();
            saved = true;
        }
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    if(currentMap)
    {
        if(!filename.isEmpty())
        {
            std::ofstream mapFile;
            mapFile.open(filename.toStdString().c_str());
            mapFile << *currentMap;
            mapFile.close();
            saved = true;
        }
        else
        {
            emit ui->actionSave->triggered();
        }
    }
}
