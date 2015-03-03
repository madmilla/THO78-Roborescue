#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maplogic.h"
#include <QCursor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logic = new mapLogic(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete logic;
}

void MainWindow::on_actionOpen_triggered()
{
    logic->openFile();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::paintEvent(QPaintEvent *e){
    (void)e;
    int ** map = logic->getMap();
    QPainter painter(this);

    //FillRect background(0, 0, 400, 300, Qt::white);
    painter.fillRect(0, 20, 400, 320, Qt::white);

    QPen gridPen(Qt::black);
    int cellWidth = 20;
    int cellHeight = 15;

    painter.setPen(gridPen);
    //Draw vertical lines
    for(int i = 0; i < 20; i++){
        painter.drawLine(i*cellWidth, 0, i*cellWidth, 320);
    }
    //Draw horizontal lines
    for(int i = 0; i < 20; i++){
        painter.drawLine(0, i*cellHeight+20, 400, i*cellHeight+20);
    }

    //Drawing the map
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; i++){
            //Draw rectangle
            //map[x][y]

        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    QPoint mPos = e->pos();
    std::cout << QString::number(mPos.x()).toUtf8().constData() << "; " << QString::number(mPos.y()).toUtf8().constData() << "\n";
    logic->mouseClicked(mPos);
}
