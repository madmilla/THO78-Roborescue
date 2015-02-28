/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 	mapeditor.h
* @brief 	MapEditor, allows for editing and reading out terrain maps
* @date Created:	2015-02-27
*
*  @author	Daniël van den Berg
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
*   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*   ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
*   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
*   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
*   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
*   OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <string>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

/**
 * This class represents the mapeditor. The mapeditor is used to create, edit and read out terrain maps.
 **/
class MapEditor
{
public:
    enum Objects{WALL=0,DRONE,TARGET};

    /**
     * @brief getInstance returns the active instance of MapEditor
     * @return the current MapEditor
     */
    static MapEditor &getInstance();

    /**
     * @brief loads a map into the MapEditor.
     * @param mapName the name of the map to be loaded.
     */
    void load(std::string mapName);

    /**
     * @brief getAvailableMaps
     * @return a QStringList with the names of all maps available in the /maps/ folder.
     */
    QStringList getAvailableMaps();

    /**
     * @brief createNewMap creates a new map with the given name, width and height.
     * @param mapName the name of the map.
     *  The map will be saved in the /maps/ folder under this name. ".map" extension is automatically added.
     * @param width the width of the map.
     * @param height the height of the map.
     */
    void createNewMap(std::string mapName, int width = 20, int height = 20);

    /**
     * @brief removeMap removes the map file from the /maps/ folder.
     * @param mapName name of the map to be removed.
     */
    void removeMap(std::string mapName);

    /**
     * @brief placeObject places the specified object at the specified location in the currently loaded map.
     * @param x to place the object at.
     * @param y to place the object at.
     * @param object to be placed at the specified position.
     * @return whether or not placing the object succeeded.
     */
    bool placeObject(int x, int y, Objects object);

    /**
     * @brief getLoadedMap returns the name of the currently loaded map.
     * @return the name of the currently loaded map.
     */
    std::string getLoadedMap();

    /**
     * @brief parseMapName parses the mapName to a set format.
     * Parses the input text to the set format. This means that it'll strip off ".map" if it exists in the input text.
     * @param text to parse to the set format.
     * @return parsed text.
     */
    std::string parseMapName(std::string text);

    /**
     * @brief getObjectsAt returns all objects at a specified location
     * @param x to get the objects from.
     * @param y to get the objects from.
     * @return a QJsonArray containing all the objects at the specified location. Objects are of type MapEditor::Objects.
     */
    QJsonArray getObjectsAt(int x, int y);

    /**
     * @brief removeObject removes the specified object from the specified location.
     * @param x to remove the object from.
     * @param y to remove the object from.
     * @param object to be removed.
     * @return whether or not the object to remove was actually removed. False if the object didn't exist.
     */
    bool removeObject(int x, int y, Objects object);

    /**
     * @brief saveMap saves the currently loaded map.
     * @return whether or not the map was saved successfully.
     */
    bool saveMap();

    /**
     * @brief getMapWidth
     * @return the width of the currently loaded map.
     */
    int getMapWidth();

    /**
     * @brief getMapHeight
     * @return the height of the currently loaded map.
     */
    int getMapHeight();

    template <typename T>
    static Objects toObject(T a){
        return static_cast<Objects>(a);
    }
private:
    std::string loadedMap = "";
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
    MapEditor(const MapEditor &);
    MapEditor& operator=(const MapEditor &);
    MapEditor();
    ~MapEditor();
};

#endif // MAPEDITOR_H
