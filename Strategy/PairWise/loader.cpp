#include "loader.h"
#include <QFile>
#include <QTextStream>
Loader::Loader()
{

}

Loader::~Loader()
{

}
Map Loader::getMap(QString s){
    QFile file(s);
    file.open(QIODevice::ReadWrite);
    QTextStream input(&file);
    while(!input.atEnd()){

        QString out = input.readLine();
        //QTextStream(stdout) << out << "\n";
        processLine(out);
    }

    return this->product;



}
void Loader::processLine(QString in){
    for(int i =0; i< in.size();i++){
        QChar current = in.at(i);
        product.addNewTile(current,lastX,lastY);
        lastX++;



    }
    lastX=0;
   lastY++;



}
