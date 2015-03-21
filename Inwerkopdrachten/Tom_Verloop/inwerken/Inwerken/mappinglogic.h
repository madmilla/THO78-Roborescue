#ifndef MAPPINGLOGIC_H
#define MAPPINGLOGIC_H
#include <QList>
#include <fstream>

class MapTile
{
public:
    MapTile();
    int getx();
    int gety();
    int getstatus();
    void setx(int X);
    void sety(int Y);
    void setstatus(int stat);
private:
    int x;
    int y;
    int status;
};

class MappingLogic
{
public:
    MappingLogic();
    ~MappingLogic();
    void load_file();
    void save_file();
    void set_tile(int x,int y,int status);
    int get_tile(int x, int y);
    QList<MapTile*> getTiles();

private:
    QList<MapTile*> tiles;
};

#endif // MAPPINGLOGIC_H
