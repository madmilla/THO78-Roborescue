#ifndef MAP_H
#define MAP_H

#include <QVector>


class Map
{
public:
    Map();
    Map(QString mapContent);
    QVector<QVector< int > > getMapContent();
    void setMapContent(QVector<QVector< int > > newMapLayout);
    void setMapObject(int object,int x, int y);
    ~Map();
private:
    QVector<QVector< int > > mapLayout;
    int y = 0;
    int x = 0;
    int width = 0;
    int height = 0;
    int intline = 0;
};

#endif // MAP_H
