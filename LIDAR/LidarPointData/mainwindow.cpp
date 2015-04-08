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

void MainWindow::on_StartScan_triggered()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(QString("Angle\t Distance\t Quality\t\n"));
    ui->StartScan->setEnabled(false);
    ui->ResumeScan->setEnabled(false);
    ui->StopScan->setEnabled(true);
    ui->PauseScan->setEnabled(true);

    lthread.Stop = false;
    lthread.start();
}

void MainWindow::on_StopScan_triggered()
{
    lidar.stopLidarScan();
    lthread.Stop = true;
    ui->StopScan->setEnabled(false);
    ui->PauseScan->setEnabled(false);
    ui->ResumeScan->setEnabled(false);
    ui->StartScan->setEnabled(true);
}

void MainWindow::on_PauseScan_triggered()
{
    lthread.pause();
    ui->PauseScan->setEnabled(false);
    ui->StartScan->setEnabled(false);
    ui->StopScan->setEnabled(true);
    ui->ResumeScan->setEnabled(true);
}

void MainWindow::on_ResumeScan_triggered()
{
    lthread.resume();
    ui->ResumeScan->setEnabled(false);
    ui->StartScan->setEnabled(false);
    ui->PauseScan->setEnabled(true);
    ui->StopScan->setEnabled(true);
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
