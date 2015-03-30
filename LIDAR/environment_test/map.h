#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QTableWidget>

class Map
{
public:
    Map();
    Map(QString mapContent);
    QVector<QVector< int > > getMapContent();
    void setMapContent(QVector<QVector< int > > newMapLayout);
    void setMapObject(int object,int x, int y);
    void saveMap();
    Qt::GlobalColor getColorById(int id);
    int width = 0;
    int height = 0;
    QString mapName;
    ~Map();

private:
    QVector<QVector< int > > mapLayout;
};

#endif // MAP_H
