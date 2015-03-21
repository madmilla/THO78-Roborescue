/// @file MapUi.hpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#ifndef _MAPUI_HPP
#define _MAPUI_HPP

#include "Map.hpp"
#include "Drawable.hpp"
#include "MouseListener.hpp"
#include <fstream>
#include <QEvent>
#include <QMouseEvent>
#include <QSize>
#include <QPainter>

/// Class MapLoadException
/// @brief Exception thrown by map load failure.
///
/// Exception thrown by map load failure.
/// Contains a error message.
class MapLoadException : std::exception{
private:
    /// Error message explaining what went wrong.
    std::string error;
public:
    /// Constructor
    ///
    /// Creates a new instance of MapLoadException.
    /// @param newError the error messages.
    MapLoadException(const std::string &newError);

    /// What
    ///
    /// Get what went wrong.
    /// @return The error messages.
    virtual const char * what() const throw() override;
};


/// Class MapUi
/// @brief Class adding a GUI to the Map.
///
/// This class adds a GUI to the Map.
/// Allows to map to be displayed on a Qt widget.
/// Also add functionality to save load a Map from file.
/// Additionally, a map can be exported as a image file.
class MapUi: public Map, public Drawable, public MouseListener{
protected:
     /// Tile colors mapped to tile type.
     std::map<TileType, Qt::GlobalColor> tileColors;
     /// Display size of a tile in pixels.
     int tileSize;
     /// Whenever to show grid or not.
     bool isShowGrid;

public:
    /// Constructor
    ///
    /// Creates a new instance of MapUi.
    /// Does not do anything special.
    MapUi();

    /// Draw
    ///
    /// Draw the map on a Qt widget.
    /// This function is called by the widget self.
    /// @param p handle to the Qt paint tool.
    void draw(QPainter &p) const override;

    /// Mouse button pressed
    ///
    /// Function called by the widget if a mouse button is pressed.
    /// @param button the mouse button pressed.
    /// @param x relative mouse position on the x-axis of the widget at the time of the button press.
    /// @param y relative mouse position on the y-axis of the widget at the time of the button press.
    void mouseButtonPressed(const Qt::MouseButton &button, int x, int y) override;

    /// Save map
    ///
    /// Save map to file.
    /// @param fileName path to or filename.
    void save(const std::string &fileName) const;

    /// Load map
    ///
    /// Load map from file.
    /// @param fileName path to or filename.
    void load(const std::string &fileName);

    /// Load map
    ///
    /// Load map from Serializable struct.
    /// @param serializedMap pointer to struct.
    void load(const Serializable* serializedMap);

    /// Fit in window
    ///
    /// Resize the tiles to fit in a window of size windowSize.
    /// Resize is done on integer base.
    /// e.g. the window size must be divisible by the amount of tiles.
    /// @param windowSize size of the window to fit on.
    void fitInWindow(const QSize &windowSize);

    /// Show grid
    ///
    /// Whenever to draw the map grid or not.
    /// @param b set to true to show or to false to hide grid.
    void showGrid(bool b);

    /// Is the grid shown
    ///
    /// Whenever the grid is shown or not.
    /// @return true if grid is shown false if not.
    bool isGridShown() const;

    /// Save as image
    ///
    /// Save the map as a image.
    /// @param fileName path to or filename.
    /// @param format image format.
    void saveAsImage(const std::string &fileName, const QImage::Format &format) const;

};

#endif // _MAPUI_HPP
