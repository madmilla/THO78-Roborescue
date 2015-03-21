#ifndef MAP_H
#define MAP_H
#include <vector>
#include "tile.h"

class Map
{
public:
    Map(int rows = 0, int columns = 0);

    /*!
     * \brief Return a Tile pointer to the tile on the position
     * specified by the row and column.
     *
     * \param row The row of the tile
     * \param column The column of the tile
     * \return A pointer to the tile on the specified position
     */
    Tile *getTile(int row, int column);

    /*!
     * \brief Return the number of rows in this map.
     *
     * \return The number of rows in this map
     */
    int getRows();

    /*!
     * \brief Return the number of columns in this map.
     *
     * \return The number of columns in this map
     */
    int getColumns();

    /*!
     * \brief Overload of the input operator.
     *
     * This function reads map attribute values from an input stream.
     * and sets them accordingly.
     */
    friend std::istream& operator>>(std::istream&, Map&);

    /*!
     * \brief Overload of the output operator.
     *
     * This function writes map attribute values to an output stream.
     */
    friend std::ostream& operator<<(std::ostream&, Map&);
private:

    /*!
     * \brief Resize the container with tiles to fit
     * the number of rows * the number of columns.
     */
    void resizeTileContainer();

    /*!
     * A vector of Tile pointers making up all rows and columns.
     *
     * Tiles are stored from left to right and top to bottom.
     *
     * It should be noted that due to the nature of Tile inheriting from QObject,
     * whether it is explicitly or not, the assignment operator is removed.
     * Therefore pointers are required.
     */
    std::vector<Tile*> tiles;

    /*!
     * The number of rows in this map.
     */
    int nrOfRows;

    /*!
     * The number of columns in this map.
     */
    int nrOfColumns;
};

#endif // MAP_H
