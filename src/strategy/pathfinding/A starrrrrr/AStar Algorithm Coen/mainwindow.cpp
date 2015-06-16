/**
 * @file mainwindow.cpp
 * @author Coen Andriessen
 * @version 1.4
 */

#include "mainwindow.h"

/**
 * Constructor of MainWindow.
 *
 * @param map
 * @param rosbee
 * @param parent
 */

MainWindow::MainWindow(Map * map, Rosbee * rosbee, scanArea * scanarea, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->map = map;
    this->rosbee = rosbee;
    this->scanarea = scanarea;
    mapcanvas = new mapCanvas;

    setCentralWidget(mapcanvas);
    mapcanvas->setMap(map);
    mapcanvas->setRosbee(rosbee);

    // Create saveAct.
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveMap()));

    // Create loadAct.
    loadAct = new QAction(tr("&Load"), this);
    loadAct->setShortcuts(QKeySequence::Open);
    loadAct->setStatusTip(tr("Open the document from disk"));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadMap()));

    // Create closeAct.
    closeAct = new QAction(tr("&Close"), this);
    closeAct->setShortcuts(QKeySequence::Close);
    closeAct->setStatusTip(tr("Close"));
    connect(closeAct, SIGNAL(triggered()), this, SLOT(closeMap()));

    // Creat Menu.
    fileMenu = menuBar()->addMenu(tr("&Map"));
    fileMenu->addAction(saveAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(closeAct);
    setMinimumSize(480, 480);

}

/**
 * Destructor of myXXXDevice.
 */

MainWindow::~MainWindow(){
    delete ui;
}

/**
 * Function to save the loaded map.
 */

void MainWindow::saveMap(){
    // Is not ready
    std::cout << "Save" << std::endl;
}

/**
 * Function to close the loaded map/application.
 */

void MainWindow::closeMap(){
    QCoreApplication::quit();
}

/**
 * Function to load the map by given path and calls update from mapcanvas and start the
 * scanning algorithm from the class scanarea.
 */

void MainWindow::loadMap(){
    //map->loadMap("C:\\Users\\coen__000\\Documents\\TestSystem\\Map1.txt");
    mapcanvas->update();
    //scanarea->run();
}
