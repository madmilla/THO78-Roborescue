#ifndef MAPLOGIC_H
#define MAPLOGIC_H
#include <QFile>
#include <QVector>
#include <QTextStream>

class MapLogic
{
public:
    MapLogic(QString filename);
    ~MapLogic();

    void updateMap(int y, int x, int newContent);
    int getMapData(int y, int x);

    void saveMap();

    QVector< QVector< int > > mapLayout;

private:
    QString filename;
     const int mapGridSize = 20;

    void loadMap(QString &filename);
};

#endif // MAPLOGIC_H
