#ifndef MAPBACK_H
#define MAPBACK_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QColor>

class mapBack
{
public:
    mapBack();
    ~mapBack();

    void loader(QString filename);
    void loadEmpty();
    int colorAt(int x, int y);
    QString setRobot(int i);
    //void save(char* savename);
    char currentMap[400];

private:
    void copyMap(char*mArray);
};

#endif // MAPBACK_H
