#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <QDir>
#include <QMessageBox>
#include <regex>
#include <QInputDialog>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    std::regex regex("\\.map$");

    if (ui->fileManagerListWidget->currentItem()->text().toStdString() == "New map"){
        bool ok;
        QString text = QInputDialog::getText(
                    this, tr("QInputDialog::getText()"),
                    tr("Map name:"), QLineEdit::Normal,
                    QDir::home().dirName(), &ok);
        if (ok && !text.isEmpty()){
            mapEditor.createNewMap(std::regex_replace(text.toStdString(),regex,""));
        }
    }
    mapEditor.load(std::regex_replace(ui->fileManagerListWidget->currentItem()->text().toStdString(),regex,""));
}

void MainWindow::on_pushButton_clicked()
{
    loadMaps();
}

void MainWindow::loadMaps(){
    ui->fileManagerListWidget->clear();
    ui->fileManagerListWidget->addItems(mapEditor.getAvailableMaps());
    ui->fileManagerListWidget->addItem("New map");
}

void MainWindow::on_pushButton_2_clicked()
{
    mapEditor.saveMap();
}
