#ifndef MAPDISPLAYWIDGET_H
#define MAPDISPLAYWIDGET_H
#include <QTableWidget>
#include "tile.h"

class Map;

class MapDisplayWidget : public QTableWidget
{
    Q_OBJECT
public:
    MapDisplayWidget(QWidget* parent = nullptr);

    /*!
     * \brief Set the map to be displayed.
     *
     * \param map Pointer to the new map to be displayed
     */
    void setCurrentMap(Map* map);
private:
    /*!
     * Pointer to the currently displayed map.
     */
    Map* currentMap;

    /*!
     * Pointer to the currently selected tile.
     */
    Tile* currentTile;

    /*!
     * Enum value specifying the most recently selected terrain type.
     */
    Tile::TERRAIN_TYPE currentType;

    /*!
     * \brief Apply all initial settings to the widget.
     */
    void applyInitialSettings();

    /*!
     * \brief Resize the display to correctly display the current map.
     */
    void fitToMap();


private slots:

    /*!
     * \brief Slot method to change the current selected tile.
     *
     * \param row The row position of the newly selected tile
     * \param column The column position of the newly selected column
     */
    void currentTileChanged(int row, int column);

    /*!
     * \brief Slot method to change the current terrain type to GRASS.
     */
    void setGrassTile();

    /*!
     * \brief Slot method to change the current terrain type to DIRT.
     */
    void setDirtTile();

    /*!
     * \brief Slot method to change the current terrain type to CONCRETE.
     */
    void setConcreteTile();

    /*!
     * \brief Slot method to change the current terrain type to WATER.
     */
    void setWaterTile();

    /*!
     * \brief Slot method to change the current terrain type to NONE.
     */
    void setEmptyTile();
};
#endif // MAPDISPLAYWIDGET_H
