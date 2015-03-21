#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maplogic.h"
#include <QCursor>
#include <QMessageBox>

// Constructor that constructs logic
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logic = new mapLogic(this);
}

// Destructor deletes ui and logic
MainWindow::~MainWindow()
{
    delete ui;
    delete logic;
}

// Function that calls openfile and repaints widget
void MainWindow::on_actionOpen_triggered()
{
    logic->openFile();
    this->repaint();
}

// Function that calls savefile
void MainWindow::on_actionSave_triggered()
{
    logic->saveFile();
}

// Function that calls newfile and repaints widget
void MainWindow::on_actionNew_triggered()
{
    logic->newFile();
    this->repaint();
}

// Function called when the Widget needs painting, it paints the grid and map
void MainWindow::paintEvent(QPaintEvent *e){
    (void)e;
    int ** map = logic->getMap();
    QPainter painter(this);

    painter.fillRect(0, 20, 400, 320, Qt::white);

    QPen gridPen(Qt::black);
    int ttlWidth = this->width();
    int ttlHeight = this->height();
    int cellWidth = ttlWidth / 20;
    int cellHeight = (ttlHeight - OFFSET) / 20;

    //Drawing the map
    for(int x = 0; x < 20; x++){
        for(int y = 0; y < 20; y++){
            //Draw rectangle
            //map[x][y]
            QRect cellRect(x*cellWidth, (y*cellHeight)+OFFSET, cellWidth, cellHeight);
            QColor color;
            switch(map[x][y]){
            case EMPTY:
                color = QColor("white");
                break;
            case OBJECT:
                color = QColor("black");
                break;
            case COPTER:
                color = QColor("red");
                break;
            default:
                color = QColor("white");
                break;
            }
            painter.fillRect(cellRect, color);
        }
    }

    painter.setPen(gridPen);
    //Draw vertical lines
    for(int i = 0; i < 20; i++){
        painter.drawLine(i*cellWidth, 0, i*cellWidth, ttlHeight);
    }
    //Draw horizontal lines
    for(int i = 0; i < 20; i++){
        painter.drawLine(0, (i*cellHeight)+OFFSET, ttlWidth, (i*cellHeight)+OFFSET);
    }
}

// Function called when mouse is pressed
void MainWindow::mousePressEvent(QMouseEvent *e){
    QPoint mPos = e->pos();
    logic->mouseClicked(mPos, e->button());
    this->repaint();
}
