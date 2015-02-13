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

void MainWindow::paintEvent(QPaintEvent * e){

}


void MainWindow::on_Load_clicked()
{
    if(ui->listWidget->currentItem() != NULL){
        qDebug() << QDir::currentPath() << "/maps/" << ui->listWidget->currentItem()->text();
        QFile loadFile(QDir::currentPath() + "/maps/" + ui->listWidget->currentItem()->text() );
        if(loadFile.exists()){
            qDebug() << "Exist";
            loadFile.open(QIODevice::ReadOnly);
            QJsonDocument file(QJsonDocument::fromJson(loadFile.readAll()));
            QJsonObject mainJson(file.object());
            QJsonObject subJson(mainJson["map"].toObject());
            if(!subJson.isEmpty()){
                MapDisplay mapDisplay;
                mapDisplay.setModal(false);
                mapDisplay.setMap(subJson);
                mapDisplay.exec();
            } else {
                QMessageBox::information(this, tr("Waring"),tr("File isn't a valid JSON file") );
            }
        }
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
    Editor editor;
    editor.setModal(false);
    if(ui->listWidget->currentItem() != NULL){
        QFile loadFile(QDir::currentPath() + "/maps/" + ui->listWidget->currentItem()->text() );
        loadFile.open(QIODevice::ReadOnly);
        QJsonDocument file(QJsonDocument::fromJson(loadFile.readAll()));
        QJsonObject mainJson(file.object());
        QJsonObject subJson(mainJson["map"].toObject());
        editor.setMap(subJson);
        qDebug() << "Set the map";
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
        Editor editor;
        editor.setModal(false);
        editor.setSize(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
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
