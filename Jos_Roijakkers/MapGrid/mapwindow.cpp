#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "savedialog.h"
#include "displaymap.h"
#include "map.h"

MapWindow::MapWindow(QWidget *MainWindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow),
    MainWindow(MainWindow)
{
    ui->setupUi(this);
    DisplayMap* displayWidget = new DisplayMap(this);
    Map* map = new Map();
    displayWidget->setCurrentMap(map);
    connect(ui->isGrass,SIGNAL(clicked(bool)),displayWidget,SLOT(isGrass(bool)));

    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::on_actionSave_triggered()
{
    saveDialog svDialog;
    svDialog.setModal(true);
    svDialog.exec();
}

void MapWindow::on_actionClear_triggered()
{

}

void MapWindow::closeEvent(QCloseEvent *event)
{
    MainWindow->setVisible(true);
}

void MapWindow::on_randomButton_clicked()
{

}

