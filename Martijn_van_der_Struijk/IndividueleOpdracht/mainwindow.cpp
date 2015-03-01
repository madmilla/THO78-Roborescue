#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <Qlabel>
#include <fstream>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    map * m = new map;
    activemap = m;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
   ui->grid->clear();
   rosbee = false;
   quadCopter = false;
   atv = false;
}

void MainWindow::on_actionSave_triggered()
{
    saveFile = QFileDialog::getSaveFileName(this, tr("Save file"), QString(), tr("Data (*.txt)"));
    savefile(saveFile);

}

void MainWindow::on_actionLoad_triggered()
{
    loadFile();

}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_Water_on_clicked(bool checked)
{

    if (checked){
        activeGrid->changeTerrein(terrain::water);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::water;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
    }
}

void MainWindow::on_Object_on_clicked(bool checked)
{
    if (checked){
        activeGrid->changeTerrein(terrain::object);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::object;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
    }

}

void MainWindow::on_Grass_on_clicked(bool checked)
{
    if (checked){
        activeGrid->changeTerrein(terrain::grass);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::grass;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
    }

}

void MainWindow::on_QuadCopter_on_clicked(bool checked)
{
    if (checked && !quadCopter ){
        activeGrid->changeTerrein(terrain::quadcopter);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::quadcopter;
        quadX = ui->grid->currentRow();
        quadY = ui->grid->currentColumn();
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
        quadCopter = true;
    }

}

void MainWindow::on_Rosbee_on_clicked(bool checked)
{
    if (checked  && !rosbee){
        activeGrid->changeTerrein(terrain::rosbee);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::rosbee;
        rosbeeX = ui->grid->currentRow();
        rosbeeY = ui->grid->currentColumn();
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
        rosbee = true;
    }

}

void MainWindow::on_Atv_on_clicked(bool checked)
{
    if (checked && !atv){
        activeGrid->changeTerrein(terrain::atv);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::atv;
        atvX = ui->grid->currentRow();
        atvY = ui->grid->currentColumn();
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
        atv = true;
    }

}

void MainWindow::on_None_on_clicked(bool checked)
{
    if (checked && ui->grid->currentRow() == quadX && ui->grid->currentColumn() == quadY ){
        activeGrid->changeTerrein(terrain::none);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::none;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
        quadCopter = false;
    }
    else if (checked && ui->grid->currentRow() == atvX && ui->grid->currentColumn() == atvY){
        activeGrid->changeTerrein(terrain::none);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::none;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
        atv = false;
    }
    else if (checked && ui->grid->currentRow() == rosbeeX && ui->grid->currentColumn() == rosbeeY){
        activeGrid->changeTerrein(terrain::none);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::none;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
        rosbee = false;
    }
    else if (checked){
        activeGrid->changeTerrein(terrain::none);
        activemap->getcel(ui->grid->currentRow(),ui->grid->currentColumn())->t = terrain::none;
        ui->grid->setItem(ui->grid->currentRow(),ui->grid->currentColumn(),activeGrid->terrainType());
    }

}



void MainWindow::savefile(const QString &name)
{
    QFile file(name);

    if (file.open(QFile::WriteOnly))
    {
        QTextStream data( &file );
        for (int r = 0; r < ui->grid->rowCount(); ++r){
            for( int c = 0; c < ui->grid->columnCount(); ++c ){
                data << (int)activemap->getcel(r,c)->t << " ";
                std::cout << (int)activemap->getcel(r,c)->t;
            }
        }
      file.close();
    }
}


void MainWindow::loadFile()
{

      fileName = QFileDialog::getOpenFileName(this, ("Open File"), NULL, ("Data (*.txt)"));
      std::ifstream loadFile;
      loadFile.open(fileName.toStdString().c_str());
      if(loadFile){
        for (int r = 0; r < ui->grid->rowCount() ; ++r){
            for( int c = 0; c < ui->grid->columnCount() ; ++c ){
            int i;
            loadFile >> i;
            ui->grid->setItem(r,c,activeGrid->terrainTypeInt(i));
            if(i==3){
                quadCopter = true;
                quadX = r;
                quadY = c;
            }
            else if(i==4){
                rosbee = true;
                rosbeeX= r;
                rosbeeY=c;
            }

            else if(i==5){
                atv = true;
                atvX = r;
                atvY = c;
            }
            }

        }

     }
}










