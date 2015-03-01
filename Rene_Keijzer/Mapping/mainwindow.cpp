#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <qjsondocument.h>
#include "map.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(16);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(16);
    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(tableItemClicked(int, int)));
    ui->tableWidget->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLoad_triggered()
{
      QString filename = QFileDialog::getOpenFileName();
      map = new Map(filename.toStdString());
      ui->tableWidget->clearContents();
      ui->tableWidget->setColumnCount(map->width());
      ui->tableWidget->setRowCount(map->height());

      ui->tableWidget->verticalHeader()->setDefaultSectionSize(ui->tableWidget->height() / (map->height()));
      ui->tableWidget->horizontalHeader()->setDefaultSectionSize(ui->tableWidget->width() / (map->width()));

      for(int y = 0; y < map->height(); y++){
          for(int x =0; x < map->width(); x++ ){
              QTableWidgetItem * item = new QTableWidgetItem;

              item->setBackgroundColor(map->cellAt(y,x));
              ui->tableWidget->setItem(y, x, item);
          }
      }
}

void MainWindow::tableItemClicked(int row, int column)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    item = ui->tableWidget->item(row,column);
    item->setBackgroundColor(map->cellAt(row, column, true));
}



void MainWindow::on_actionEdit_triggered()
{
     ui->tableWidget->setDisabled(false);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionSave_2_triggered()
{
    map->save();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Save"), "C:\\", tr("Data File ('.dat'"));
    map->save(file.toStdString());
}
