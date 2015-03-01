#include "mainwindow.h"
#include "ui_mainwindow.h"

QTextStream cout(stdout);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    loadMapList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked(){
    if(ui->listWidget->currentItem()){
        const QString selectedMap = ui->listWidget->currentItem()->text();
        map = new Map(selectedMap);
        map->show();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("No map selected");
        msgBox.exec();
    }
}

void MainWindow::loadMapList(){
    ui->listWidget->clear();
    QDir directory(QDir::currentPath());
    QStringList foundmMaps = directory.entryList(QStringList("*.map"));
    ui->listWidget->addItems(foundmMaps);
}

void MainWindow::on_createEmptyMapButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, "Create empty map","Map name:",
                                         QLineEdit::Normal,"map name", &ok);

    if (ok && !text.isEmpty()){
        if(!QFile::copy("defaultMap.default", text + ".map")){
            QMessageBox msgBox;
            msgBox.setText("Name already used");
            msgBox.exec();
        }
    }
    loadMapList();
}

void MainWindow::on_deleteButton_clicked(){
    if(ui->listWidget->currentItem()){
        const QString selectedMap = ui->listWidget->currentItem()->text();
        QFile::remove(selectedMap);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("No map selected");
        msgBox.exec();
    }
    loadMapList();
}
