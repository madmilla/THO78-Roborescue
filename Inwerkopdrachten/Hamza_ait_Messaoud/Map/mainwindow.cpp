#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(25);
    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(tableItemClicked(int, int)));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(20);
    ui->tableWidget->setRowCount(20);

    newFile();

    createActions();
    createMenus();

    setWindowTitle(tr("Mapper"));
    setMinimumSize(550, 550);
    resize(600, 600);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tableItemClicked(int row, int column)
{
    map.changeColor(ui->tableWidget->item(row,column));
}

void MainWindow::open()
{
    map.load(ui->tableWidget);
    std::cout << "file Open" << std::endl;
}

void MainWindow::save()
{
    map.save(ui->tableWidget);
    std::cout << "file Saved" << std::endl;
}

void MainWindow::newFile()
{
    map.newMap(ui->tableWidget);
    std::cout << "New File" << std::endl;
}

void MainWindow::createActions()
{
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::Save);
    newAct->setStatusTip(tr("Open a new File"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
}
