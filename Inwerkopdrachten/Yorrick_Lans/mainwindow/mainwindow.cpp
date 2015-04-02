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
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(loadFile()));

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

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Map File"), "",tr("Map file (*.map);;All Files (*)"));
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
        QString s = activeMap->writeOut();
        out << s;

    }
}

void MainWindow::loadFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Map File"), "",tr("Map file (*.map);;All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        QString s;
        in >> s;
        QStringList list = s.split("\n");
        int row, column;
        int i = 0;
        while(!list[i].isEmpty())
        {
            QString s2 = list[i];
            QStringList list2 = s2.split(" ");
            if(QString::compare(list2[0],";")!=0)
            {
                if(QString::compare(list2[0],"row:")==0)
                {
                    row = list2[1].toInt();
                }
                if(QString::compare(list2[0],"column:")==0)
                {
                    column = list2[1].toInt();
                }
                if(QString::compare(list2[0],"terrain:")==0)
                {
                    if(QString::compare(list2[1],"Water")==0)
                    {
                        activeMap->getCell(row-1,column-1)->changeTerrain(terrainType::water);
                    }
                    else if(QString::compare(list2[1],"Concrete")==0)
                    {
                        activeMap->getCell(row-1,column-1)->changeTerrain(terrainType::concrete);
                    }
                    else if(QString::compare(list2[1],"Grass")==0)
                    {
                        activeMap->getCell(row-1,column-1)->changeTerrain(terrainType::grass);
                    }
                    else if(QString::compare(list2[1],"Wall")==0)
                    {
                        activeMap->getCell(row-1,column-1)->changeTerrain(terrainType::wall);
                    }
                    else if(QString::compare(list2[1],"Empty")==0)
                    {
                        activeMap->getCell(row-1,column-1)->changeTerrain(terrainType::none);
                    }
                }
                if(QString::compare(list2[0],"quadcopter:")==0)
                {
                    if(QString::compare(list2[1],"true")==0)
                    {
                        activeMap->getCell(row-1,column-1)->quadPresent = true;
                    }
                    else
                    {
                        activeMap->getCell(row-1,column-1)->quadPresent = false;
                    }
                }
                if(QString::compare(list2[0],"ATV:")==0)
                {
                    if(QString::compare(list2[1],"true")==0)
                    {
                        activeMap->getCell(row-1,column-1)->ATVPresent = true;
                    }
                    else
                    {
                        activeMap->getCell(row-1,column-1)->ATVPresent = false;
                    }
                }
                if(QString::compare(list2[0],"rosbee:")==0)
                {
                    if(QString::compare(list2[1],"true")==0)
                    {
                        activeMap->getCell(row-1,column-1)->rosbeePresent = true;
                    }
                    else
                    {
                        activeMap->getCell(row-1,column-1)->rosbeePresent = false;
                    }
                }
            }
            ui->tableWidget->setItem(row-1,column-1,activeMap->getCell(row-1,column-1)->formatCell());
            i++;
        }
    }
}

