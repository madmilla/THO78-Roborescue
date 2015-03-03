#ifndef MAPPING_H
#define MAPPING_H
#include <QString>
#include <QVector>

class Mapping
{
public:
    Mapping();
    ~Mapping();
    bool saveMap(QString fileName);
    bool loadMap(QString fileName);
    bool setObject(int posX, int posY);
    bool setActiveObject(int obj);
    QVector< QVector<int> > getMap();
private:
    static const int size = 20;
    QVector< QVector<int> > grid;
    int activeObject;
};
#endif // MAPPING_H
