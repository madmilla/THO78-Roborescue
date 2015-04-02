#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    lidar("\\\\.\\com3"),
    lthread(lidar)
{
    ui->setupUi(this);
    connect(&lthread, SIGNAL(updateUI(const QString)), this, SLOT(appendToTextView(const QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StopScan_triggered()
{
    lidar.stopLidarScan();
    lthread.Stop = true;
}

void MainWindow::on_PauseScan_triggered()
{
    lthread.pause();
}

void MainWindow::on_ResumeScan_triggered()
{
    lthread.resume();
}

void MainWindow::on_SaveScan_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Map"), "/");
    if(!fileName.isEmpty() || !fileName.isNull()) {
        lidar.writeScanDataToFile(fileName.toStdString());
    }
}

void MainWindow::appendToTextView(const QString text)
{
    ui->plainTextEdit->insertPlainText(text);
}

void MainWindow::on_StartScan_triggered()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(QString("Angle\t Distance\t Quality\t\n"));
    lthread.Stop = false;
    lthread.start();
}
