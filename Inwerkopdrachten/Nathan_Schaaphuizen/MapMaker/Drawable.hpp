/// @file Drawable.hpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <QPainter>

/// Class Drawable
/// @brief Interface class for drawing.
///
/// Provides a interface that can be used to draw on target.
/// Inherit from this class if you wish to draw on a widget.
class Drawable{
public:
    /// Virtual draw
    ///
    /// Pure virtual function that provides the draw interface.
    /// This function is called every time a repaint is needed.
    /// @param p painter target.
    virtual void draw(QPainter &p) const = 0;
};

#endif // _DRAWABLE_HPP

