#include <QtWidgets>

#include "mainwindow.h"
#include "map.h"
#include "mapcanvas.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    map = new Map;
    mapCanvas = new MapCanvas;
    setCentralWidget(mapCanvas);

    mapCanvas->setMap(map);

    createActions();
    createMenus();

    setWindowTitle(tr("MapEditor"));
    setMinimumSize(480, 480);
    resize(480, 480);
}

MainWindow::~MainWindow(){

}

void MainWindow::newFile(){
    map = new Map;
    mapCanvas->setMap(map);
}

void MainWindow::open(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    //QString fileName = tr("C:\\Users\\Bianca\\Desktop\\map.txt");
    map = Map::loadFromFile(fileName.toStdString().c_str());
    mapCanvas->setMap(map);
    mapCanvas->update();
}

void MainWindow::save(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Files (*.*)"));
    //QString fileName = tr("C:\\Users\\Bianca\\Desktop\\map.txt");
    map->saveToFile(fileName.toStdString().c_str());
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
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
}
