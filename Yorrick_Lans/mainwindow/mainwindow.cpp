#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableWidget->resizeColumnsToContents();

    activeMap = new map;

    for(int x=0; x <20; ++x)
    {
        for(int y=0; y<20; ++y)
        {
            ui->tableWidget->setItem(x,y,activeMap->getCell(x,y)->formatCell());
        }
    }
    connectAllSlots();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::currentCellChanged(int xNew, int yNew, int xOld, int yOld)
{
    activeCell = activeMap->getCell(xNew,yNew);
    ui->rowLabel->setText(QString("row: %1").arg(xNew+1));
    ui->columnLabel->setText(QString("column: %1").arg(yNew+1));
    ui->terrainLabel->setText(activeCell->getTerrainAsText());
    if(activeCell->quadPresent)
    {
        ui->quadInfoLabel->setText("quadcopter: true");
    }
    else
    {
        ui->quadInfoLabel->setText("quadcopter: false");
    }
    if(activeCell->ATVPresent)
    {
        ui->ATVInfoLabel->setText("ATV: true");
    }
    else
    {
        ui->ATVInfoLabel->setText("ATV: false");
    }
    if(activeCell->rosbeePresent)
    {
        ui->rosbeeInfoLabel->setText("rosbee: true");
    }
    else
    {
        ui->rosbeeInfoLabel->setText("rosbee: false");
    }
}

void MainWindow::waterButtonPressed()
{
    activeCell->changeTerrain(terrainType::water);
    ui->terrainLabel->setText(activeCell->getTerrainAsText());
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::concreteButtonPressed()
{
    activeCell->changeTerrain(terrainType::concrete);
    ui->terrainLabel->setText(activeCell->getTerrainAsText());
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::grassButtonPressed()
{
    activeCell->changeTerrain(terrainType::grass);
    ui->terrainLabel->setText(activeCell->getTerrainAsText());
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::wallButtonPressed()
{
    activeCell->changeTerrain(terrainType::wall);
    ui->terrainLabel->setText(activeCell->getTerrainAsText());
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::emptyButtonPressed()
{
    activeCell->removeVehicle(vehicleType::quadCopter);
    activeCell->removeVehicle(vehicleType::ATV);
    activeCell->removeVehicle(vehicleType::rosbee);
    activeCell->changeTerrain(terrainType::none);
    ui->terrainLabel->setText(activeCell->getTerrainAsText());
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
    activeMap->writeOut();
}

void MainWindow::quadButtonPressed()
{
    if(activeCell->quadPresent)
    {
        activeCell->removeVehicle(vehicleType::quadCopter);
        ui->quadInfoLabel->setText("quadcopter: false");
    }
    else
    {
        activeCell->placeVehicle(vehicleType::quadCopter);
        ui->quadInfoLabel->setText("quadcopter: true");
    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::ATVButtonPressed()
{
    if(activeCell->ATVPresent)
    {
        activeCell->removeVehicle(vehicleType::ATV);
        ui->ATVInfoLabel->setText("ATV: false");
    }
    else
    {
        activeCell->placeVehicle(vehicleType::ATV);
        ui->ATVInfoLabel->setText("ATV: true");
    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::rosbeeButtonPressed()
{
    if(activeCell->rosbeePresent)
    {
        activeCell->removeVehicle(vehicleType::rosbee);
        ui->rosbeeInfoLabel->setText("rosbee: false");
    }
    else
    {
        activeCell->placeVehicle(vehicleType::rosbee);
        ui->rosbeeInfoLabel->setText("rosbee: true");
    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activeMap->getCell(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::connectAllSlots()
{
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

    connect(ui->pushButtonQuad,SIGNAL(clicked()),this,SLOT(quadButtonPressed()));
    connect(ui->pushButtonATV,SIGNAL(clicked()),this,SLOT(ATVButtonPressed()));
    connect(ui->pushButtonRosbee,SIGNAL(clicked()),this,SLOT(rosbeeButtonPressed()));

    connect(ui->pushButtonWater,SIGNAL(clicked()),this,SLOT(waterButtonPressed()));
    connect(ui->pushButtonConcrete,SIGNAL(clicked()),this,SLOT(concreteButtonPressed()));
    connect(ui->pushButtonGrass,SIGNAL(clicked()),this,SLOT(grassButtonPressed()));
    connect(ui->pushButtonWall,SIGNAL(clicked()),this,SLOT(wallButtonPressed()));
    connect(ui->pushButtonNone,SIGNAL(clicked()),this,SLOT(emptyButtonPressed()));
    connect(ui->tableWidget,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(currentCellChanged(int,int,int,int)));
}

/*void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Address Book"), "",tr("Map file (*.mpf);;All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << contacts;
        for(int x = 0; x < 20; ++x)
        {
            for(int y = 0; y < 20; ++y)
            {
                out << activeMap->getCell(x,y);
            }
        }
    }
}*/

