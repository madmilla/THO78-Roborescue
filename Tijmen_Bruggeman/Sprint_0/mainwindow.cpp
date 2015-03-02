#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
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

void MainWindow::on_Load_map_clicked()
{
    ui->listWidget->clear();
    QStringList nameFilter("*.map");
    QDir directory("");
    QStringList maps = directory.entryList(nameFilter);
    ui->listWidget->addItems(maps);
}

void MainWindow::on_Show_map_clicked()
{
    mapEditor->show_map();
}


void MainWindow::on_NewButton_clicked()
{
    bool xBool;
    bool yBool;
    int XSize = ui->XSizeField->displayText().toInt(&xBool);
    int YSize = ui->YSizeField->displayText().toInt(&yBool);
    if(xBool && yBool && YSize!=1){
        Map map("NEW FILE", XSize, YSize);
        mapEditor->setMap(&map);
        mapEditor->show_map();
    }
}
void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    Map * map = new Map(currentText);
    ui->textEdit->clear();
    for(QString line : map->getMap()){
        ui->textEdit->append(line);
    }
    mapEditor->setMap(map);
}
