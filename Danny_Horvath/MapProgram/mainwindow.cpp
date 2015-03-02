#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_LoadFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*.txt);;C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) {                            //If the filename is not empty this means a file has been selected
        QFile file(fileName);                             //Put this in a variable

        if (!file.open(QIODevice::ReadOnly)) {            //If the file can't be opened return an error message
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        }

        QTextStream tStream(&file);                      //Put the full content of the textfile inside a textStream
        QString mapcontent = tStream.readAll();
        map = mapcontent;
        m->setMap(map);
        file.close();
    }
}

void MainWindow::on_NewFile_triggered()
{
    for(int i = 0; i < 400; i++){
        map.append('U');
    }
    m->setMap(map);
    m->show();
}

void MainWindow::on_LoadMap_clicked()
{
    if(map.length() > 0){
        m->show();
    }
}
