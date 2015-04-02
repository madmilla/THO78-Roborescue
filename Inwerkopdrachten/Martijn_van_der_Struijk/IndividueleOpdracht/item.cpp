#include "item.h"


item::item():
    t(terrain::none)
{
}

item::~item()
{

}

QTableWidgetItem * item::terrainType(){
    QTableWidgetItem * Item = new QTableWidgetItem;
    switch(t){
        case(terrain::object):
            Item->setBackground(Qt::red);
        break;
        case(terrain::water):
            Item->setBackground(Qt::blue);
        break;
        case(terrain::grass):
            Item->setBackground(Qt::green);
        break;
        case(terrain::quadcopter):
            Item->setBackground(Qt::black);
        break;
        case(terrain::rosbee):
            Item->setBackground(Qt::yellow);
        break;
        case(terrain::atv):
            Item->setBackground(Qt::gray);
        break;
        case(terrain::none):
            Item->setBackground(Qt::white);\
        break;
    }

    return Item;
}

QTableWidgetItem * item::terrainTypeInt(int i){
    QTableWidgetItem * Item = new QTableWidgetItem;

    switch(i){
        case(2):
            Item->setBackground(Qt::red);
        break;
        case(0):
            Item->setBackground(Qt::blue);
        break;
        case(1):
            Item->setBackground(Qt::green);
        break;
        case(3):
            Item->setBackground(Qt::black);
        break;
        case(4):
            Item->setBackground(Qt::yellow);
        break;
        case(5):
            Item->setBackground(Qt::gray);
        break;
        case(6):
            Item->setBackground(Qt::white);\
        break;
    }
    return Item;

}

void item::changeTerrein(terrain typen){
t = typen;
}

