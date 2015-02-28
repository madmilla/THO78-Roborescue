#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_openFileButton_clicked() {
    mapFile = QFileDialog::getOpenFileName(this,tr("Open map file"), "/", tr("Text files (*.txt)"));
    if (!mapFile.isEmpty()) {
        mapProcessor m;
        m.processMap(mapFile, ui->mapFrame);
    }
}

void MainWindow::on_exitButton_clicked() { //Close the main window, exiting the program.
    this->close();
}
