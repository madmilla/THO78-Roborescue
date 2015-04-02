#include "map.h"
#include "gridlabel.h"

map::map(QWidget* parent = 0):
    QWidget(parent)
{}

map::map(){}

void map::openFile(QFile &file){
    QTextStream in(&file);

       while(!in.atEnd())
       {
           QString ch = in.read(1);
           if( ch != "\n"){
               int code = ch.toInt();
               color.push_back(code);
           }
       }
       file.close();
       makeGrid();
}

int map::labelColor(int count){
    int colorCode = color[count];
    return colorCode;
}

void map::makeGrid(){
    int count = 0;
    layout = new QGridLayout (this);
    for (int colum = 0; colum < Collums; colum++) {
        for (int row = 0; row < Rows; row++) {
            Gridlabel* label = new Gridlabel(this);
            label->setColor(labelColor(count));
            count++;
            labels[colum][row] = label;
            layout->addWidget(label, colum, row);
        }
    }
}


