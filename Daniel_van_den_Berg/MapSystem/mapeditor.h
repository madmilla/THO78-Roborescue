#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <string>
#include <QStringList>

class MapEditor
{
public:
    MapEditor();
    void load(std::string mapName);
    QStringList getAvailableMaps();
    void createNewMap(std::string mapName);
    void removeMap(std::string mapName);
    std::string parseMapName(std::string text);
    void saveMap();
    ~MapEditor();
};

#endif // MAPEDITOR_H
