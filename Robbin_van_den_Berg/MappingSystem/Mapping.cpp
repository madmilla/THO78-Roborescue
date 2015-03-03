#include "Mapping.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

Mapping::Mapping():
    grid(size,QVector<int>(size)),
    activeObject(0)
{
}

Mapping::~Mapping(void)
{
}

bool Mapping::saveMap(QString fileName)
{
    QFile outfile(fileName);
    if(!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&outfile);

    // Read out grid 2d array
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            out << grid.at(x).at(y);
        }
        out << endl;
    }
    outfile.close();
    return true;
}

bool Mapping::loadMap(QString fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

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
    file.close();
    return true;
}

QVector< QVector<int> > Mapping::getMap() {
    return grid;
}

bool Mapping::setObject(int posX, int posY) {
    if(posX >= 0 && posX < size && posY >= 0 && posY < size) {
        grid[posY][posX] = activeObject;
        return true;
    }
    return false;
}

int Mapping::setActiveObject(int obj) {
    activeObject = obj;
    return activeObject;
}

