#ifndef MAP_H
#define MAP_H

#include <QColor>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QMainWindow>
#include <string>
#include <vector>
#include <stdlib.h>
#include <QFileDialog>

class Map
{
public:
    Map();
     ~Map();
    void load(QTableWidget * item);
    void save(QTableWidget * item);
    void changeColor(QTableWidgetItem *item);
    void newMap(QTableWidget * item);

};

#endif // MAP_H
