#include "simulatemapwindow.h"
#include "ui_simulatemapwindow.h"
#include <QMouseEvent>
#include <QFileDialog>
#include <QTextEdit>

SimulateMapWindow::SimulateMapWindow(Map *map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulateMapWindow),
    map(map)
{
    objectx = (drawWidth / map->width);
    objecty = (drawHeight / map->height);
    simMap = new SimulateMap(map);
    ui->setupUi(this);
}

SimulateMapWindow::~SimulateMapWindow()
{
    delete ui;
    delete simMap;
    simMap = NULL;
    delete map;
    map = NULL;
}

void SimulateMapWindow::on_simulateButton_clicked()
{
    std::string s = simMap->simulate();
    QString qs = QString::fromStdString(s);
    QTextEdit *txt = new QTextEdit();
    txt->setText(qs);

    txt->show();
}

void SimulateMapWindow::mousePressEvent(QMouseEvent * event){
    if(event->pos().x() < Values::DRAWWIDTH){
       if(selected < 0){
           return;
        }
        int positionx = (event->pos().x() - event->pos().x() % objectx) / objectx;
        int positiony = (event->pos().y() - event->pos().y() % objecty) / objecty;
        if(positionx < map->width  &&  positiony < map->height){
            if(selected == Values::CHECKPOINT){
                simMap->addCheckPoint(positionx,positiony);
            }
            else if(selected == Values::EMPTY){
                simMap->deleteCheckPoint(positionx, positiony);
            }
            map->setMapObject(selected, positiony, positionx);
            update();
            mousePressed = true;
        }
    }
}


void SimulateMapWindow::paintEvent(QPaintEvent */* Unused */){
    if(!mousePressed) return;
    QPainter painter(this);
    int y = 0;
    for(std::vector<int> fory : map->getMapContent()){
        int x = 0;
        for(int forx : fory){
            painter.fillRect((x*objectx),(y*objecty),objectx,objecty,QBrush(getColorById(forx)));
            ++x;
        }
        ++y;
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

void SimulateMapWindow::on_noneButton_clicked()
{
    selected = Values::EMPTY;
}

void SimulateMapWindow::on_checkpointButton_clicked()
{
    selected = Values::CHECKPOINT;
    std::cout << "clicked: " << selected << std::endl;
}

void SimulateMapWindow::on_savePcButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString());

    if (!fileName.isEmpty()) {
        std::string file = fileName.toStdString();
        Pointcloud pC = simMap->getPointCloud();
        pC.savePointsToFile(file);
    }
}
