#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <QDir>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <stdlib.h>
#include "mapeditor.h"

MapEditor::Objects MainWindow::selectedObject;
int MainWindow::shouldEdit;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listWidget->addItem(QString("Wall"));
    ui->listWidget->addItem(QString("Drone"));
    ui->listWidget->addItem(QString("Target"));

    loadMaps();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_clicked()
{
    if(ui->fileManagerListWidget->currentItem() == NULL){
        QMessageBox::information(this, tr("Waring"),tr("No file selected.") );
        return;
    }

    if (ui->fileManagerListWidget->currentItem()->text().toStdString() == "New map"){
        bool ok;
        QString text = QInputDialog::getText(
                    this, tr("QInputDialog::getText()"),
                    tr("Map name:"), QLineEdit::Normal,
                    "", &ok);
        int width = QInputDialog::getInt(this,
                                         tr("Width"),tr("Width"),
                                         20,0);
        int height = QInputDialog::getInt(this,
                                         tr("Height"),tr("Height"),
                                         20,0);
        if (ok && !text.isEmpty()){
            MapEditor::getInstance().createNewMap(text.toStdString(),width,height);
        }
    }
    MapEditor::getInstance().load(ui->fileManagerListWidget->currentItem()->text().toStdString());
    loadMaps();
}

void MainWindow::on_pushButton_clicked()
{
    loadMaps();
}

void MainWindow::loadMaps(){
    ui->fileManagerListWidget->clear();
    ui->fileManagerListWidget->addItems(MapEditor::getInstance().getAvailableMaps());
    ui->fileManagerListWidget->addItem("New map");
}

void MainWindow::on_pushButton_2_clicked()
{
    MapEditor::getInstance().saveMap();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->fileManagerListWidget->currentItem() == NULL || ui->fileManagerListWidget->currentItem()->text().toStdString() == "New map"){
        QMessageBox::information(this, tr("Waring"),tr("No file selected.") );
        return;
    }

    MapEditor::getInstance().removeMap(ui->fileManagerListWidget->currentItem()->text().toStdString());
    loadMaps();
}

void MainWindow::on_pushButton_4_clicked()
{
    std::system("explorer .\\maps");
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    selectedObject = MapEditor::toObject(index.row());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    shouldEdit = (index == 2);
}
