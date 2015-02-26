#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <string>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class MapEditor
{
public:
    MapEditor();

    enum Objects{WALL=0,DRONE,TARGET};

    void load(std::string mapName);
    QStringList getAvailableMaps();
    void createNewMap(std::string mapName, int width = 20, int height = 20);
    void removeMap(std::string mapName);
    bool placeObject(int x, int y, Objects object);
    std::string getLoadedMap();
    std::string parseMapName(std::string text);
    void saveMap();
    ~MapEditor();
private:
    std::string loadedMap = "";
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
};

#endif // MAPEDITOR_H
