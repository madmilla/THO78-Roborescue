#ifndef MAP_H
#define MAP_H

#include "gridlabel.h"

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class map : public QWidget
{

public:  
    map(QWidget* parent);

    map(); //for testing

    void openFile(QFile& file);
    int labelColor(int count);
    void makeGrid();


private:
    static const int Rows = 20;
    static const int Collums = 20;

    Gridlabel* labels[Collums][Rows];
    Gridlabel* label = new Gridlabel(this);
    QGridLayout* layout;
    std::vector<int> color;
};

#endif // MAP_H
