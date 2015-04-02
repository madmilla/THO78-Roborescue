/// @file Map.hpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#ifndef _MAP_HPP
#define _MAP_HPP

#include <vector>
#include <algorithm>

/// Convenient shorthand hand name for the double vector array.
typedef std::vector<std::vector<unsigned char>> Tiles;

/// Class Map
/// @brief Map is a low level structure composed of cells.
///
/// Map is a low level structure composed of cells.
/// Each cell consists of a singel byte, making it possible to have 255 different cell types on a map.
/// A map has a maximum size but it its actual size may vary. The maximum size is decided during compilation.
/// A map is always squared, videlicet the x and y-axis are always the same lenght.
/// Due to it low level implementation the map is usable on embedded systems as long as standard C++ is supported.
/// The down side is, that the map can only effectively be used if 2 times the maximum map size squared is available on the heap.

class Map {
public:
    /// Maxium map size
    ///
    /// This the map diamter. The amount of tiles on a map is this number squerd.
    /// The actual memory use is 2 times this number squared in bytes.
    /// The map can not grow beyond this size. e.g maxMapSize = 20 gives maximum map of 20x20.
    static const int maxMapSize = 1024;

    /// Enum tile types
    ///
    /// Enum class containing the tile types.
    /// You can add/remove/edit tile types using this enum.
    /// The Unknown tile type is required and must be first starting at zero, it's also not to be removed or altered.
    /// The Last tile type is also required and must always be last, it's also not to be removed or altered.
    /// The value of a tile type also determines its merging priority. The priority is sorted low values to high values.
    /// e.g. 1 is the lowest possible priority and 244 the highest.
    enum class TileType : unsigned char{
        /// Unknow, the status of this tile is not known. Keep first, must be lowest.
        Unknown = 0,
        /// Free tile, nothing is on it.
        Free,
        /// Blocked tile, there is a immovable object on this tile.
        Blocked,
        /// Tile occupied by the All Terrain Vehicle.
        ATV,
        /// Tile occupied by the Quadcopter.
        QC,
        /// Tile occupied by the Rosbee.
        Rosbee,
        /// Not a tile status. Keep last, must be highest.
        Last
    };

    /// Struct serializable
    /// @brief Serializable equivalent of the map.
    ///
    /// The struct contains a serializable equivalent of the map.
    /// This can be used to directly save the map to a file, stream or buffer.
    /// The struct has the same size as the maximum possible bytes used by the map.
    /// The diameter is saved as size.
    /// The amount of bytes you have to write/read from this structure is the size squared.
    struct Serializable{
        ///Map diameter, again the actual bytes used is this number squared.
        unsigned int size;
        ///Byte array representing the map, these are necessary all used.
        unsigned char tiles[maxMapSize * maxMapSize];
    };

protected:
    ///Double array of tiles making up the map.
    Tiles tiles;
    ///Map diameter.
    int tileCount;

public:
    /// Constructor
    ///
    /// Used to create a new instance of Map.
    /// Does not do anything special.
    Map();

    /// Resize the map
    ///
    /// Adjust the map diameter.
    /// If the new size is larger than the original the new tiles of type unknown will be added to the map.
    /// Original tiles will be left unaffected.
    /// If the new size is smaller than the original size all excessif tiles will be removed.
    /// If the size is the same nothing will happen.
    /// @param mapSize the new map diameter.
    void resize(unsigned int mapSize);

    /// Add new tile
    ///
    /// Add a tile on the map on position x,y.
    /// If the position already exists the existing tile will be overwritten.
    /// If the position is outside the map bounds the map will be resized to fit the tile.
    /// Note: the origin (0,0) is the most top left tile.
    /// @param x offset on the x-axis.
    /// @param y offset on the y-axys.
    /// @param tileType the type off tile.
    void addTile(unsigned int x, unsigned int y, const TileType &tileType);

    /// Clear map
    ///
    /// Clear the map by setting all the tiles to type Unknown.
    /// This function will not affect the map size.
    void clear();

    /// Merge map
    ///
    /// Merge two maps together.
    /// The map will be resized to the size of the largest map.
    /// A merge is priority based. Low priority tiles will be overwritten by
    /// higher priority tiles on the same position.
    /// @param other is the other map to merge with.
    void merge(const Map &other);

    /// Serialise map
    ///
    /// Create a new serialized map.
    /// This will require a decent amount of memory for larger maps.
    /// Note: The serialized map is independent from the instance and will not be deleted if the instance dies.
    /// @return Pointer to the serialized map struct.
    Serializable* serialise() const;

    /// Get tiles
    ///
    /// Get a copy of all the tiles in the map.
    /// @return A double vector char array representing the map.
    Tiles getTiles() const;

    /// Get map diameter
    ///
    /// Get the current map diameter.
    /// @return The map diameter.
    int getDiameter() const;

};

#endif // _MAP_HPP
