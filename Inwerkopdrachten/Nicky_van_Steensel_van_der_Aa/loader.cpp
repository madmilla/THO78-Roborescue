#include <iostream>
#include "loader.h"
#include "QFile"
#include "QTextStream"

Loader::Loader()
{

}

Loader::~Loader()
{


}

Tile Loader::process_char(QChar lijn)
{
    int x=0;int y=0;
    if(x==20){y++;x=0;}
    x++;
    return Tile(x,y);

}

map Loader::getMap(QString maploc){
    map* mapp = new map();

    QFile file(maploc);
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    QString line = in.readLine();
    while (true) {
        for( int a = 0; a != line.length(); a = a + 1 )
           {
               QTextStream(stdout) << "value of a: " << line.at(a) << endl;
              mapp->mymap.push_back(this->process_char(line.at(a)));
           }
    }
}
