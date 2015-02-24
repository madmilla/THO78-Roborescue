#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QtDebug>
#include "mapdisplay.h"
#include "editor.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList nameFilter("*.map");
    QDir directory(QDir::currentPath() + "/maps");
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);
    ui->listWidget->addItems(txtFilesAndDirectories);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_clicked()
{
    if(ui->listWidget->currentItem() != NULL){
        MapDisplay mapDisplay(ui->listWidget->currentItem()->text());
        mapDisplay.setModal(false);
        mapDisplay.exec();

    } else {
         QMessageBox::information(this, tr("Waring"),tr("Didn't selected a file") );
    }
}

void MainWindow::on_Quit_clicked()
{
    exit(0);
}

void MainWindow::on_Editor_clicked()
{

    if(ui->listWidget->currentItem() != NULL){
        Editor editor(ui->listWidget->currentItem()->text());
        editor.setModal(false);
        editor.exec();
    }else {
        QMessageBox::information(this, tr("Waring"),tr("Didn't selected a file") );
    }
}

void MainWindow::on_ReloadFiles_clicked()
{
    ui->listWidget->clear();
    QStringList nameFilter("*.map");
    QDir directory(QDir::currentPath() + "/maps");
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);
    ui->listWidget->addItems(txtFilesAndDirectories);
}

void MainWindow::on_Newmap_clicked()
{
    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != ""){
        Editor editor("",ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
        editor.setModal(false);
        editor.exec();
    }else{
        QMessageBox::information(this, tr("Waring"),tr("Empty height and/or width") );
    }

}

void MainWindow::on_Delete_clicked()
{
    if(ui->listWidget->currentItem() != NULL){
        if(QFile::remove(QDir::currentPath() + "/maps/" +ui->listWidget->currentItem()->text())){
            QMessageBox::information(this, tr("Done"),tr("File deleted") );
            on_ReloadFiles_clicked();
        }else{
            QMessageBox::information(this, tr("Waring"),tr("File didn't exist") );
        }
    }
}
