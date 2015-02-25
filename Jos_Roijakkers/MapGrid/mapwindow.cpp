#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "savedialog.h"

MapWindow::MapWindow(QWidget *MainWindow, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow),
    MainWindow(MainWindow)
{
    ui->setupUi(this);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            ui->tableWidget->setItem(x, y, new QTableWidgetItem());
        }
    }
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

void MapWindow::closeEvent(QCloseEvent *event)
{
    MainWindow->setVisible(true);
}

