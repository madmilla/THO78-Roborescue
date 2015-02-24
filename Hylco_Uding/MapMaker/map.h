#ifndef MAP_H
#define MAP_H
#define MAX_SIZE 50
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QBrush>
#include <stdio.h>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>
class Map
{
public:
    Map();
    Map(int height, int width);
    Map(QString filename);
    ~Map();
    std::map<QString, QBrush> getTypes();
    QBrush getType(QString type);
    QJsonArray getPixel(int x,int y);
    void deleteType(int x, int y, QString type);
    bool containsType(int x, int y, QString type);
    void setPixel(int x,int y, QJsonObject json);
    void deletePixel(int x, int y);
    int getHeight();
    int getWidth();
    void clear();
    void saveFile(QString filename);
private:
    QJsonArray array[MAX_SIZE][MAX_SIZE];
    std::map<QString,QBrush> Types;
    QJsonObject jsonMap;
    int width, height;
};

#endif // MAP_H
