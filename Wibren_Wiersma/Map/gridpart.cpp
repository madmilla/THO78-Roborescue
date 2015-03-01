
#include "gridpart.h"
#include <iostream>

struct color{
    unsigned char R, G, B, none;
};

union colorTabel{
    unsigned int colorRepressentation;
    color color;
};

GridPart::GridPart(unsigned int data){
    unsigned char dataColor = 32; //0 to 32 NOT 0 to 31
    for(int i = 0; i < 32; i++){
        if((data & (1 << i)) != 0){
            dataColor = i;
            break;
        }
    }
    colorTabel tabel;
    tabel.colorRepressentation = 0x00FFFFFF * dataColor / 32;
    if(tabel.color.none != 0){
        std::cerr << "Color problem none set. None:" << (int)tabel.color.none << "\n";
    }
    normalColor = QColor{(int)tabel.color.R, (int)tabel.color.G, (int)tabel.color.B};
}

QTableWidgetItem * GridPart::getWidget(){
    QTableWidgetItem * twi =  new QTableWidgetItem();
    twi->setBackgroundColor(normalColor);
    return twi;
}

void GridPart::changeData(unsigned int newData,  QTableWidgetItem * twi){
    unsigned char dataColor = 32; //0 to 32 NOT 0 to 31
    for(int i = 0; i < 32; i++){
        if((newData & (1 << i)) != 0){
            dataColor = i;
            break;
        }
    }
    colorTabel tabel;
    tabel.colorRepressentation = 0x00FFFFFF * dataColor / 32;
    std::cout << dataColor << '/' << tabel.colorRepressentation << '\n';
    if(tabel.color.none != 0){
        std::cerr << "Color problem none set. None:" << (int)tabel.color.none << "\n";
    }
    QColor normalColor = QColor{(int)tabel.color.R, (int)tabel.color.G, (int)tabel.color.B};
    twi->setBackgroundColor(normalColor);
}
