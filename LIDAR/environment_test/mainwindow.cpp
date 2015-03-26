#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
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
    delete map;
}

void MainWindow::on_newMapButton_clicked()
{
    std::cout << "New Map clicked";
}

void MainWindow::on_editMapButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Map Files (*.map)");

    if (!fileName.isEmpty()) {                            //If the filename is not empty this means a file has been selected
        QFile file(fileName);                             //Put this in a variable

        if (!file.open(QIODevice::ReadOnly)) {            //If the file can't be opened return an error message
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        }
        map = new Map(fileName);
        editMapWindow = new EditMapWindow();
        editMapWindow->showMap(map);
    }
}

void MainWindow::on_simulateButton_clicked()
{
    std::cout << "Simulate Map clicked";
}
