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

void MainWindow::on_newMap_clicked()
{
    for(int i = 0; i < 400; i++){
            map.append('U');
        }
        editMap->setMap(map);
        editMap->show();
}

void MainWindow::on_loadMap_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*.txt);;C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        }

        QTextStream tStream(&file);
        QString mapData = tStream.readAll();
        map = mapData;
        editMap->setMap(map);
        file.close();
        editMap->show();
    }
}
