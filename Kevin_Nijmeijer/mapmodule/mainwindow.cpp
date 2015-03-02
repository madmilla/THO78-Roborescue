//#include <QtGui>
//#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//#include "mapio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    QWidget* topFiller = new QWidget;
    //topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QTableWidget* mapTableWidget = new QTableWidget(this);
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
    //mapTableWidget->horizontalHeader()->setFixedWidth(20);
    //mapTableWidget->verticalHeader()->setFixedHeight(20);


    QWidget* bottomFiller = new QWidget;
    //bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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
}

void MainWindow::displayMap()
{
    std::cout<<"DisplayStart"<<std::endl;
    for (int k=0; k<20; k++)
    {
        std::cout<<"k change"<<std::endl;

        for(int l=0; l<20; l++)
        {
            std::cout<<"l change"<<std::endl;
            QTableWidgetItem* tempitem = new QTableWidgetItem();
            std::cout<<"made widgetitem"<<std::endl;

            tempitem->setBackgroundColor(mb->colorAt(l,k));
            std::cout<<"color requested"<<std::endl;
            mapTableWidget->setItem(k,l,tempitem);
            std::cout<<"item set"<<std::endl;

            //delete tempitem;


        }
    }
    //std::cout<<std::endl;
}



void MainWindow::createMenus()
{

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
