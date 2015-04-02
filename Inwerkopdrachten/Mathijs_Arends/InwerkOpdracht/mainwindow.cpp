#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Widget *widget, QWidget *parent) :
    QMainWindow(parent),
    widget{widget},
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionAddObject_triggered(){


}
void MainWindow::mousePressEvent(QMouseEvent *event){

    Object foo;
    if(selectedType==1){foo.hight= 20;}
    else if(selectedType==2){foo.hight= 10;}

    if(selectedType==1){foo.width=10;}
    else if(selectedType==2){foo.width=20;}
    foo.x= event->x();
    foo.y= event->y();
    foo.type=selectedType;
 widget->addObject(foo);



}

void MainWindow::on_actionSelectObject1_triggered()
{
    selectedType=1;
}

void MainWindow::on_actionSelectObject2_triggered()
{
    selectedType=2;
}

void MainWindow::on_actionSelectFile_triggered()
{
    widget->loadMap();
}

void MainWindow::on_actionQuit_triggered()
{
   QApplication::quit();
}
