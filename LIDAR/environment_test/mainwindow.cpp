#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QInputDialog>

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
    bool ok;
    QString text = QInputDialog::getText(this, "Create map","Map name:",
                                         QLineEdit::Normal,"map name", &ok);
    if(!ok) return;
    int height = QInputDialog::getInt(this, "Create map","Map height:",
                                      newMapBeignSize,newMapMinSize,newMapMaxSize,newMapStepSize, &ok);
    if(!ok) return;
    int width = QInputDialog::getInt(this, "Create map","Map height:",
                                     newMapBeignSize,newMapMinSize,newMapMaxSize,newMapStepSize, &ok);

    if (ok && !text.isEmpty()){
        QFile newMap(text + ".map");
        if (!newMap.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        QTextStream out(&newMap);
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                out << 0;
            }
            if(y != height - 1)out << '\n';
        }
        newMap.close();
    }
}

void MainWindow::on_editMapButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(), "Map Files (*.map)");

    if (!fileName.isEmpty()) {                            //If the filename is not empty this means a file has been selected
        /*QFile file(fileName);                             //Put this in a variable

        if (!file.open(QIODevice::ReadOnly)) {            //If the file can't be opened return an error message
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        }*/
        map = new Map(fileName);
        editMapWindow = new EditMapWindow(map);
        editMapWindow->show();
    }
}

void MainWindow::on_simulateButton_clicked()
{
    std::cout << "Simulate Map clicked";
}
