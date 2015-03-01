#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QMessageBox>

MainWindow::MainWindow(MappingLogic * mapper,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->mapper = mapper;
    ui->setupUi(this);
    //Connect handlers
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(handleButton()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(actionExit()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(actionLoad()));
    //loadgrid
    LoadGrid();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleButton()
{
    QItemSelectionModel *select = ui->tableWidget->selectionModel();
    QModelIndexList list = select->selectedIndexes();
    for(QModelIndex index : list)
    {
        setCellstatus(index.row(),index.column(),ui->comboBox_2->currentIndex());
        mapper->set_tile(index.row(),index.column(),ui->comboBox_2->currentIndex());
    }
}
void MainWindow::setItemColor(QTableWidgetItem * item,int status)
{
    switch(status)
    {
    case 1:
        item->setBackground(Qt::green);
        break;
    case 2:
        item->setBackground(Qt::red);
        break;
    case 3:
        item->setBackground(Qt::blue);
        break;
    case 4:
        item->setBackground(Qt::black);
        break;
    default:
        item->setBackground(Qt::white);
        break;
    }
}


void MainWindow::LoadGrid()
{
    ui->tableWidget->clearContents();
    for(MapTile * t : mapper->getTiles())
    {
        setCellstatus(t->getx(), t->gety(), t->getstatus());
    }
}

void MainWindow::setCellstatus(int x, int y, int status)
{

    ui->tableWidget->setItem( x,y, new QTableWidgetItem);
    setItemColor(ui->tableWidget->item( x,y),status);
}


void MainWindow::actionLoad()
{

    ui->tableWidget->clearContents();
    mapper->load_file();
    LoadGrid();
}

void MainWindow::actionSave()
{
    mapper->save_file();
}

void MainWindow::actionExit()
{
    close();
}
