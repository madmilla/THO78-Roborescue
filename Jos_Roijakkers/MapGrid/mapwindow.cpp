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
    displayWidget = new DisplayMap(this);

    connect(ui->isGrass,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isGrass_toggled(bool)));
    connect(ui->isConcrete,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isConcrete_toggled(bool)));
    connect(ui->isDirt,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isDirt_toggled(bool)));
    connect(ui->isWater,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isWater_toggled(bool)));
    connect(ui->isEmpty,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isEmpty_toggled(bool)));
    connect(ui->isQuadcopter,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isQuadcopter_toggled(bool)));
    connect(ui->isATV,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isATV_toggled(bool)));
    connect(ui->isRosbee,SIGNAL(toggled(bool)),displayWidget,SLOT(on_isRosbee_toggled(bool)));


    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::setMap(Map * map)
{
    currentmap = map;
    displayWidget->setCurrentMap(currentmap);
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

