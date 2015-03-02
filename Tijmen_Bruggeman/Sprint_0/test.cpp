#include "test.h"
#include <iostream>
Test::Test()
{

}

Test::~Test()
{

}

void Test::Test_1(){
    MapEditor map;
    QFile file("test_1.map");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QVector<QString> load_map;
    QTextStream stream(&file);
    file.seek(0);
    QString line = stream.readLine();

    while(!line.isNull()){
        load_map.push_back(line);
        line = stream.readLine();
    }
    //int i = map.setMap(load_map,"test_1.map");
    int i = 0;
    if(i == -1){
        std::cout << "Deze map heeft geen goed formaat: ";
    }
    else{
        std::cout << "Deze map heeft een goed formaat";
    }
    file.close();
    std::cout << "Deze map is "<<map.width()<<"X"<<map.height()<<" groot";
    for(QString string: load_map){
        std::cout << string.toStdString() <<"\n";
    }
}
