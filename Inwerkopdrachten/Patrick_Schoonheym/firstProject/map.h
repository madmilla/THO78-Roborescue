#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QString>
#include <QPoint>
#include <QFile>
#include <QTextStream>
#include <iostream>

class Map
{
private:
    std::vector<QString> map;

public:
    Map();
    ~Map();
    int getHeight();
    int getWidth();
    std::vector<QString>& getMap();
    bool legit_char_checker();
    bool readFile(const QString & name);
    bool hasData();
    bool legit_size_checker();
};

#endif // MAP_H
