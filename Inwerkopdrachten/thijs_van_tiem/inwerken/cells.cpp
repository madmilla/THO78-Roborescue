#include "cells.h"




cells::cells():
    omgeving(terreinTypen::none),
    quadPresent(false),
    atvPresent(false),
    rosbeePresent(false)
{

}

cells::~cells()
{

}

QTableWidgetItem * cells::formatCell()
{
    QTableWidgetItem * item = new QTableWidgetItem;
    switch(omgeving){
        case(terreinTypen::water):
            item->setBackground(Qt::blue);
        break;

        case(terreinTypen::concrete):
            item->setBackground(Qt::black);
        break;

        case(terreinTypen::green):
            item->setBackground(Qt::green);
        break;

        case(terreinTypen::quad):
        item->setBackground(Qt::magenta);
        break;

        case(terreinTypen::rosbee):
        item->setBackground(Qt::yellow);
        break;

        case(terreinTypen::atv):
        item->setBackground(Qt::red);
        break;

        case(terreinTypen::none):

        break;

    }
    return item;

}

QTableWidgetItem * cells::formatCellLoad(int p)
{
    QTableWidgetItem * item = new QTableWidgetItem;
    switch(p){
        case(0):
            item->setBackground(Qt::blue);
        break;

        case(1):
            item->setBackground(Qt::black);
        break;

        case(2):
            item->setBackground(Qt::green);
        break;

        case(3):
        item->setBackground(Qt::magenta);
        break;

        case(4):
        item->setBackground(Qt::yellow);
        break;

        case(5):
        item->setBackground(Qt::red);
        break;

        case(6):

        break;

    }
    return item;

}

void  cells::changeTerrein(terreinTypen typen){
    omgeving = typen;
}




// iedere cel eigen identiteit (kleur)
