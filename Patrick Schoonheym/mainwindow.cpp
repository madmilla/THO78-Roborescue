#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->StartButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    for(auto & map : maps) {
        delete map;
    }
}

void MainWindow::readFile(const QString & name) {
    QFile file(name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "could not load image with path" << name << "\n";
        return;
    }

    QTextStream file_stream(&file);
    while(!file_stream.atEnd()) {
        map_data.push_back(file_stream.readLine());
    }
    file.close();
}

void MainWindow::on_openFileButton_clicked()
{
    map_data.clear();
    ui->textEdit->clear();

    const char* name = "Open File";
    const char* path = "C:/Users/Patrick/Documents/firstProject/Maps/";
    const char* extension = "All Files (*.*);; Map Files (*.map*)";

    QString fileName = QFileDialog::getOpenFileName(this, tr(name), path, extension);
    readFile(fileName);

    if(!map_data.empty()) {
        for(const auto & line : map_data) {
            ui->textEdit->append(line);
        }
        ui->StartButton->setEnabled(true);
    }
    else {
        ui->StartButton->setEnabled(false);
    }
}

void MainWindow::on_StartButton_clicked() {
    Map* map = new Map{};
    map->setMap(map_data);
    map->show();
    maps.push_back(map);
}
