#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions(){
     newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);  //control+n werkt ook als new file
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcuts(QKeySequence::Open); //control+o werkt ook om te openen
     openAct->setStatusTip(tr("Open an existing file"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
}

void MainWindow::showMap(Qstring fileName){
    for(int i = 0; i < objectMap.getSize(toStdString(fileName)).y; i++){
        for(int j = 0; j < objectMap.getSize(toStdString(fileName).x); j++ ){

        }
    }
}

void MainWindow::newFile(){
    QString fileName = QFileDialog::getSaveFileName(this,  //load map
             tr("Save Address Book"), "",
             tr("Map (*.txt);;All Files (*)"));
    objectMap(20, 20, fileName); //20 is coded map size
    showMap(fileName);
 }

 void MainWindow::open(){

 }

