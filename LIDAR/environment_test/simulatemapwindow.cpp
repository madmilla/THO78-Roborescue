#include "simulatemapwindow.h"
#include "ui_simulatemapwindow.h"

SimulateMapWindow::SimulateMapWindow(Map *map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulateMapWindow),
    map(map)
{
    objectx = (drawWidth / map->width);
    objecty = (drawHeight / map->height);
    ui->setupUi(this);
}

SimulateMapWindow::~SimulateMapWindow()
{
    delete ui;
}

void SimulateMapWindow::on_simulateButton_clicked()
{

}

void SimulateMapWindow::mousePressEvent(QMouseEvent * event){
    mousePressed = true;
}


void SimulateMapWindow::paintEvent(QPaintEvent *e){
    if(!mousePressed) return;
    //std::cout << "Paint!" << std::endl;
    QPainter painter(this);
    int y = 0;
    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(getColorById(forx)));
            x++;
        }
        y++;
    }
}

Qt::GlobalColor SimulateMapWindow::getColorById(int id){
    Qt::GlobalColor bColor;
    switch (id) {
    case 0:
        bColor = Qt::white;
    break;
    case 1:
        bColor = Qt::red;
    break;
    case 2:
        bColor = Qt::green;
    break;
    case 3:
        bColor = Qt::blue;
    break;
    default:
        bColor = Qt::black;
    break;
    }
    return bColor;
}
