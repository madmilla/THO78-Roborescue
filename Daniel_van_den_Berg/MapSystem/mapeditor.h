#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <string>
#include <QStringList>

class MapEditor
{
public:
    MapEditor();
    void MapEditor::load(std::string mapName);
    QStringList MapEditor::getAvailableMaps();
    void MapEditor::createNewMap(std::string mapName);
    void MapEditor::saveMap();
    ~MapEditor();
};

#endif // MAPEDITOR_H
