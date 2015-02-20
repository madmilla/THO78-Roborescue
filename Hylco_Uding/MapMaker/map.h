#ifndef MAP_H
#define MAP_H
#define MAX_SIZE 50
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QBrush>
#include <stdio.h>
class Map
{
public:
    Map();
    Map(int height, int width, QJsonObject = QJsonObject());
    ~Map();
    std::map<QString, QBrush> getTypes();
    QBrush getType(QString type);
    QJsonArray getPixel(int x,int y);
    void setPixel(int x,int y, QJsonObject json);
    void deletePixel(int x, int y);
    int getHeight();
    int getWidth();
private:
    QJsonArray array[MAX_SIZE][MAX_SIZE];
    std::map<QString,QBrush> Types;
    QJsonObject jsonMap;
    int width, height;
};

#endif // MAP_H
