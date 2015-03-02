#include "Mapping.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QtDebug>

Mapping::Mapping():
    grid(size,QVector<int>(size)),
    activeObject(0)
{
}

Mapping::~Mapping(void)
{
}

void Mapping::saveMap(QString fileName)
{
    QFile outfile(fileName);
    if(!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&outfile);

    // Read out grid 2d array
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            out << grid.at(x).at(y);
        }
        out << endl;
    }
}

void Mapping::loadMap(QString fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    int x = 0;
    int y = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();

        for(int i=0; i < line.length(); i++){
            grid[y][x] = line.at(i).digitValue();
            x++;
        }
        x = 0;
        y++;
    }
}

QVector< QVector<int> > Mapping::getMap() {
    return grid;
}

void Mapping::setObject(int posX, int posY) {
    if(posX >= 0 && posX < size && posY >= 0 && posY < size) {
        grid[posY][posX] = activeObject;
    }
}

void Mapping::setActiveObject(int obj) {
    activeObject = obj;
}

