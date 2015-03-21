
#include "gridpart.h"
//#include <iostream>
//#include <QtGlobal>
//#include <QDebug>

struct colorStruct{
    unsigned char R, G, B, none;
};

union colorTabel{
    unsigned int colorRepressentation;
    colorStruct color;
};

GridPart::GridPart(unsigned int data){
    unsigned char dataColor = 32; //0 to 32 NOT 0 to 31
    for(int i = 0; i < 32; i++){
        if((data & (1 << i)) != 0){
            dataColor = i;
            break;
        }
    }
    if(dataColor == 32){
       normalColor = QColor(255, 255, 255);
    }else if(dataColor == 0){
       normalColor = QColor(0, 0, 0);
    }else if(dataColor == 8){
        normalColor = QColor::fromHsv(0, 0, 64);
    } else if(dataColor == 8 * 2){
        normalColor = QColor::fromHsv(0, 0, 64 * 2);
    } else if(dataColor == 8 * 3){
        normalColor = QColor::fromHsv(0, 0, 64 * 3);
    } else{
        if(dataColor > 8 * 3) dataColor -= 3;
        else if(dataColor > 8 * 2) dataColor -= 2;
        else if(dataColor > 8) dataColor -= 1;
        dataColor -= 1;
        if(dataColor % 2){
           normalColor = QColor::fromHsv(360 / 28 * dataColor, 255, 128);
        }else{
           normalColor = QColor::fromHsv(360 / 28 * dataColor, 128, 255);
        }
    }
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
     QColor normalColor;
     if(dataColor == 32){
        normalColor = QColor(255, 255, 255);
     }else if(dataColor == 0){
        normalColor = QColor(0, 0, 0);
     }else if(dataColor == 8){
         normalColor = QColor::fromHsv(0, 0, 64);
     } else if(dataColor == 8 * 2){
         normalColor = QColor::fromHsv(0, 0, 64 * 2);
     } else if(dataColor == 8 * 3){
         normalColor = QColor::fromHsv(0, 0, 64 * 3);
     } else{
         if(dataColor > 8 * 3) dataColor -= 3;
         else if(dataColor > 8 * 2) dataColor -= 2;
         else if(dataColor > 8) dataColor -= 1;
         dataColor -= 1;
         if(dataColor % 2){
            normalColor = QColor::fromHsv(360 / 28 * dataColor, 255, 128);
         }else{
            normalColor = QColor::fromHsv(360 / 28 * dataColor, 128, 255);
         }
     }
     //int h,s,v;
     //normalColor.getHsv(&h, &s, &v);
     //qDebug() << h << '/' << s << '/' << v << '\n';

    twi->setBackgroundColor(normalColor);
}
