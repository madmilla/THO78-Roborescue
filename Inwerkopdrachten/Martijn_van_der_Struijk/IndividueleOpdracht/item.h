#ifndef ITEM_H
#define ITEM_H

#include <QTableWidgetItem>


enum class terrain{
    water,
    grass,
    object,
    quadcopter,
    rosbee,
    atv,
    none
};

class item
{
public:
    QTableWidgetItem * terrainTypeInt(int i);

    item(const item & i) = delete;

    terrain t;

    QTableWidgetItem * terrainType();
    void item::changeTerrein(terrain typen);


    item();
    ~item();

private:

};

#endif // ITEM_H
