#ifndef MAP_H
#define MAP_H

#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>

class ObjectMap
{
public:
    ObjectMap();
    ~ObjectMap();

    struct VehicleLocation{
        int x;
        int y;
        VehicleLocation::VehicleLocation(int xp, int yp):x(xp),y(yp){}
    };

    void save();

    void load();

    void clear();

    void setHeight(int x, int y, int height);

    void setObject(int x, int y, bool object);

    bool isObject(int x, int y);

    int getHeight(int x, int y);

    void setVehicle(int x, int y);

    bool vehiclePlaced();

    bool vehicleAt(int x, int y);

    VehicleLocation vehicleLocation();
private:
    const QString fileName = "objects.map";
    const int maxX = 20;
    const int maxY = 20;
    QJsonObject json;
};

#endif // MAP_H
