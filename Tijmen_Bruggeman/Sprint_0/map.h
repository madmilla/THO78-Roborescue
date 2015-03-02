#ifndef MAP_H
#define MAP_H
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <iostream>
class Map
{
private:
    QVector<QString> map;
    QString fileName;
    int mapWidth;
    int mapHeiht;
public:
    Map(const QString fileName, int width = 0, int height = 0);
    Map();
    ~Map();
    int getWidth();
    QString getFileName();
    int getHeight();
    int checkMap();
    void save();
    void saveAs(QString fileName);
    void setObject(QChar object, int x, int y);
    QVector<QString> getMap();
};

#endif // MAP_H
