#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_map_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Map"), "/");
    map.loadMap(fileName);
}

void MainWindow::on_actionSave_map_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Map"), "/");
    map.saveMap(fileName);
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::paintEvent(QPaintEvent *e) {
    QVector< QVector<int> > grid = map.getMap();
    int gridCount = grid.length();
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QPainter painter(this);

    // Read out grid 2d array
    for(int x = 0; x < gridCount; x++) {
        for(int y = 0; y < gridCount; y++) {
            switch(grid.at(x).at(y)) {
                case 0:
                    // Free
                    brush.setColor(Qt::white);
                break;
                case 1:
                    // Quadcopter
                    brush.setColor(Qt::red);
                break;
                case 2:
                    // Rosbee
                    brush.setColor(Qt::yellow);
                break;
                case 3:
                    // ATV
                    brush.setColor(Qt::cyan);
                break;
                case 4:
                    // Wall
                    brush.setColor(Qt::black);
                break;
                default:
                    brush.setColor(Qt::green);
            }

            QRect rec((y+1)*recSize,30 + (x+1)*recSize,recSize,recSize);
            painter.fillRect(rec, brush);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        int posX = (event->x() - (event->x() % recSize))/recSize -1;
        int posY = (event->y() - (event->y() % recSize))/recSize -3;

        map.setObject(posX, posY);
        update();
    }
}

void MainWindow::on_freeButton_clicked()
{
    map.setActiveObject(0);
}

void MainWindow::on_quadcopterButton_clicked()
{
    map.setActiveObject(1);
}

void MainWindow::on_rosbeeButton_clicked()
{
    map.setActiveObject(2);
}

void MainWindow::on_atvButton_clicked()
{
    map.setActiveObject(3);
}

void MainWindow::on_wallButton_clicked()
{
    map.setActiveObject(4);
}
