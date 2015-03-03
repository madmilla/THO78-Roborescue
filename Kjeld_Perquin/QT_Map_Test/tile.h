#ifndef TILE_H
#define TILE_H
#include <QTableWidgetItem>
#include <iostream>
#include <QMetaEnum>

class Tile :  public QObject, public QTableWidgetItem
{
    Q_OBJECT
    Q_ENUMS(TERRAIN_TYPE)
public:
    /*!
     * \brief The VEHICLE_TYPE enum used to add vehicles to a tile.
     */
    enum class VEHICLE_TYPE
    {
        QUADCOPTER,
        ROSBEE,
        ATV
    };

    /*!
     * \brief The TERRAIN_TYPE enum used to set the type of this tile.
     *
     * This enum can't be an enum class as it is used by the Qt meta-enum
     * system to convert from a string to enum and vice-versa.
     */
    enum TERRAIN_TYPE
    {
        NONE,
        WATER,
        DIRT,
        CONCRETE,
        GRASS
    };
    Tile(TERRAIN_TYPE type = TERRAIN_TYPE::NONE,
         bool quadcopter = false,
         bool rosbee = false,
         bool ATV = false);

    /*!
     * \brief Set the terrain type of the this tile.
     *
     * \param type The new terrain type
     */
    void setTerrainType(TERRAIN_TYPE type);

    /*!
     * \brief Request the terrain type of this tile.
     *
     * \return The terrain type of this tile.
     */
    TERRAIN_TYPE getTerrainType();

    /*!
     * \brief Add a vehicle to this tile.
     *
     * \param type The vehicle type to add to this tile.
     */
    void addVehicle(VEHICLE_TYPE type);

    /*!
     * \brief State if the quadcopter is present.
     *
     * \return Boolean stating if the quadcopter is present
     */
    bool isQuadcopterPresent();

    /*!
     * \brief State if the rosbee is present.
     *
     * \return Boolean stating if the rosbee is present
     */
    bool isRosbeePresent();

    /*!
     * \brief State if the ATV is present.
     *
     * \return Boolean stating if the ATV is present
     */
    bool isATVPresent();

    /*!
     * \brief Remove a vehicle from this tile.
     *
     * \param type The type of vehicle to remove
     */
    void removeVehicle(VEHICLE_TYPE type);

    /*!
     * \brief Remove all vehicles from this tile
     * and set the terrain type to NONE
     */
    void clearTile();

    /*!
     * \brief Overload of the output operator.
     *
     * This function writes tile attribute values to an output stream.
     */
    friend std::ostream& operator<<(std::ostream& stream, Tile& tile);

    /*!
     * \brief Overload of the input operator.
     *
     * This function reads tile attribute values from an input stream.
     * and sets them accordingly.
     */
    friend std::istream& operator>>(std::istream& stream, Tile& tile);

private:

    /*!
     * Enum type specifying the terrain type of a tile.
     */
    TERRAIN_TYPE terrainType;

    /*!
     * Boolean stating whether the quadcopter is present or not.
     */
    bool quadcopterPresent;

    /*!
     * Boolean stating whether the ATV is present or not.
     */
    bool ATVPresent;

    /*!
     * Boolean stating whether the rosbee is present or not.
     */
    bool rosbeePresent;

    /*!
     * Meta enum required to convert enums to strings and vice-versa.
     */
    QMetaEnum metaEnum;
};

#endif // TILE_H
