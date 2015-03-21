#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>


Mapping mapper;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Qt::GlobalColor MainWindow::convertColor(int value)
{
    switch(value)
    {
        case 0: return Qt::black; break;
        case 1: return Qt::blue; break;
        case 2: return Qt::red; break;
        case 3: return Qt::green; break;
        case 4: return Qt::yellow; break;
        case 5: return Qt::gray; break;
        default: return Qt::white; break;
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(
            this,
            tr("About application"),
            tr("Mapping GUI for RoboRescue Map, by Kaalus") );
}

void MainWindow::on_actionLoad_triggered()
{
    ui->tableWidget->clear();

    QString fileName = QFileDialog::getOpenFileName(this,tr("Select map file"), "", tr("Files(*.map)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(
                this,
                tr("Error"),
                tr("Can't read file") );
    }
    else
    {
        std::vector<int> mapData = mapper.openFile(file);

        int counter = 0;
        for(int columns = 0; columns < columnSize; columns++)
        {
            for(int rows = 0; rows < rowSize; rows++){
                ui->tableWidget->setItem(rows, columns, new QTableWidgetItem);
                ui->tableWidget->item(rows ,columns)->setBackgroundColor(convertColor(mapData[counter]));
                counter++;
            }
        }
    }
}
