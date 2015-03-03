#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QString>
#include <QPoint>
#include <qDebug>
#include <QFile>
#include <QTextStream>

class Map
{
private:
    std::vector<QString> map;

public:
    Map();
    ~Map();
    const int getHeight();
    const int getWidth();
    std::vector<QString>& getMap();
    const bool legit_char_checker();
    const bool readFile(const QString & name);
    const bool hasData();
    const bool legit_size_checker();
};

#endif // MAP_H
