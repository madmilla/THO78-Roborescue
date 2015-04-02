#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    mb = new mapBack();
    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    QWidget* topFiller = new QWidget;

    mapTableWidget = new QTableWidget(this);
    mapTableWidget->setRowCount(20);
    mapTableWidget->setColumnCount(20);
    for (int i = 0; i<20; i++)
    {
        mapTableWidget->setRowHeight(i,24);
        mapTableWidget->setColumnWidth(i,24);
    }
    mapTableWidget->setShowGrid(false);
    mapTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mapTableWidget->setSortingEnabled(false);

    QWidget* bottomFiller = new QWidget;

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(mapTableWidget);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);
    createActions();
    createMenus();

    setWindowTitle(tr("Map Module"));
    setMinimumSize(520,580);
    resize(520,580);
}

void MainWindow::newFile()
{
    mb->loadEmpty();
    displayMap();
}

void MainWindow::open()
{
    QFileDialog fileDialog;
    filename = fileDialog.getOpenFileName(this,tr("Open file"), "/", tr("Text files (*.txt)"));
    if (!filename.isEmpty()) {
        mb->loader(filename);
        displayMap();
    }
}

void MainWindow::save()
{

}

void MainWindow::exit()
{
    this->close();
}

void MainWindow::insAtv()
{
    QTableWidgetItem* atvI = new QTableWidgetItem(mb->setRobot(1));
    atvI->setBackgroundColor(mb->colorAt(mapTableWidget->currentColumn(),mapTableWidget->currentRow()));
    mapTableWidget->setItem(mapTableWidget->currentRow(),mapTableWidget->currentColumn(),atvI);
}

void MainWindow::insDrone()
{
    QTableWidgetItem* droneI = new QTableWidgetItem(mb->setRobot(2));
    droneI->setBackgroundColor(mb->colorAt(mapTableWidget->currentColumn(),mapTableWidget->currentRow()));
    mapTableWidget->setItem(mapTableWidget->currentRow(),mapTableWidget->currentColumn(),droneI);
}

void MainWindow::insRosbee()
{
    QTableWidgetItem* rosI = new QTableWidgetItem(mb->setRobot(3));
    rosI->setBackgroundColor(mb->colorAt(mapTableWidget->currentColumn(),mapTableWidget->currentRow()));
    mapTableWidget->setItem(mapTableWidget->currentRow(),mapTableWidget->currentColumn(),rosI);
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the document to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    closeAction = new QAction(tr("E&xit"), this);
    closeAction->setShortcuts(QKeySequence::Quit);
    closeAction->setStatusTip(tr("Exit the application"));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

    addAtv = new QAction(tr("&ATV"),this);
    addAtv->setStatusTip(tr("Insert all terrain vehicle at selected location"));
    connect(addAtv, SIGNAL(triggered()), this, SLOT(insAtv()));


    addDrone = new QAction(tr("&Drone"),this);
    addDrone->setStatusTip(tr("Insert quadcopter drone at selected location"));
    connect(addDrone, SIGNAL(triggered()), this, SLOT(insDrone()));

    addRosbee = new QAction(tr("&Rosbee"),this);
    addRosbee->setStatusTip(tr("Insert Rosbee-LiDAR unit at selected location"));
    connect(addRosbee, SIGNAL(triggered()), this, SLOT(insRosbee()));
}

void MainWindow::displayMap()
{
    for (int k=0; k<20; k++)
    {
        for(int l=0; l<20; l++)
        {
            QTableWidgetItem* tempitem = new QTableWidgetItem();
            tempitem->setBackgroundColor(mb->colorAt(l,k));
            mapTableWidget->setItem(k,l,tempitem);
        }
    }
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);

    addObjMenu = menuBar()->addMenu(tr("&Insert"));
    addObjMenu->addAction(addRosbee);
    addObjMenu->addAction(addAtv);
    addObjMenu->addAction(addDrone);
}

MainWindow::~MainWindow()
{
    delete ui;
}
