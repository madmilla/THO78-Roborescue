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

        case(terreinTypen::none):

        break;

    }
    return item;
    //if(!quadPresent){
    //    item->setBackground(Qt::magenta);
    //}
   // if(!rosbeePresent){
    //    item->setBackground(Qt::yellow);
   // }
    //if(!atvPresent){
    //    item->setBackground(Qt::red);

   // }
     // ifjes onder switch die naderhand quad en atv en rosbee toevoegen
}

void  cells::changeTerrein(terreinTypen typen){
    omgeving = typen;
}

void cells::toggleQuad()
{
    if(quadPresent){
        quadPresent = false;
    }
    else{
        quadPresent = true;
    }
}

void cells::toggleAtv()
{
    if(atvPresent){
        atvPresent = false;
    }
    else{
       atvPresent = true;
    }

}

void cells::toggleRosbee()
{
    if(rosbeePresent){
        rosbeePresent = false;
    }
    else{
        rosbeePresent = true;
    }

}


// iedere cel eigen identiteit (kleur)
