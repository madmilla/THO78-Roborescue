#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->StartButton->setEnabled(false);

    addImage(":/images/beker.jpg");
    addImage(":/images/deur.jpg");
    addImage(":/images/muur.jpg");
    addImage(":/images/plant.jpg");
    addImage(":/images/tafel.jpg");

    SCREEN_SIZE.setX(480);
    SCREEN_SIZE.setY(480);
}

MainWindow::~MainWindow()
{
    delete ui;

    for(auto& gui : guis) {
        delete gui;
    }
}

void MainWindow::addImage(const QString & name) {
    QPixmap image;

    if(!image.load(name)) {
        qDebug() << "could not load image with path" << name << "\n";
        return;
    }
    images.push_back(image);
}

void MainWindow::on_openFileButton_clicked()
{
    map = nullptr;
    ui->textEdit->clear();

    const char* name = "Open File";
    const char* path = "C:/Users/Patrick/Documents/firstProject/Maps/";
    const char* extension = "All Files (*.*);; Map Files (*.map*)";

    mapName = QFileDialog::getOpenFileName(this, tr(name), path, extension);

    map = new Map{};
    if(!map->readFile(mapName)) {
        return;
    }

    if(map->hasData()) {
        for(const auto & line : map->getMap()) {
            ui->textEdit->append(line);
        }
        ui->StartButton->setEnabled(true);
    }
    else {
        ui->StartButton->setEnabled(false);
    }
}

void MainWindow::on_StartButton_clicked() {

    if(!map->legit_char_checker() || !map->legit_size_checker()) {
        qDebug() << "map is corrupted\n";
        return;
    }

    Gui* gui = new Gui{SCREEN_SIZE, images, map};
    gui->show();
    guis.push_back(gui);
}
