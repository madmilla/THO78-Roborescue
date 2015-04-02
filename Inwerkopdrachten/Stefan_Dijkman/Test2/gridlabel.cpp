#include "gridlabel.h"

Gridlabel::Gridlabel(QWidget *parent = 0):
    QLabel(parent)
{}

Qt::GlobalColor Gridlabel::convertColor(int code){
    switch(code){
        case 0: return Qt::gray; break;
        case 1: return Qt::black; break;
        case 2: return Qt::blue; break;
        case 3: return Qt::red; break;
        case 4: return Qt::green; break;
        case 5: return Qt::yellow; break;
        case 6: return Qt::white; break;
        default: return Qt::gray; break;
    }
}

void Gridlabel::setColor(int colorCode){
     qpix.fill(convertColor(colorCode));
     this->setPixmap(qpix);
}

