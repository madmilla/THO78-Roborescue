#ifndef MAPPING_H
#define MAPPING_H
#include <QString>
#include <QVector>

class Mapping
{
public:
    Mapping();
    ~Mapping();
    void saveMap(QString fileName);
    void loadMap(QString fileName);
    void setObject(int posX, int posY);
    void setActiveObject(int obj);
    QVector< QVector<int> > getMap();
private:
    static const int size = 20;
    QVector< QVector<int> > grid;
    int activeObject;
};
#endif // MAPPING_H
