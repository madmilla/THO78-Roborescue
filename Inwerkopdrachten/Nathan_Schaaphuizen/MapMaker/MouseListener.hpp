/// @file MouseListener.hpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#ifndef _MOUSELISTENER_HPP
#define _MOUSELISTENER_HPP

#include <QMouseEvent>

/// Class MouseListener
/// @brief Interface class for mouse events.
///
/// Provides a interface that can be used to receive mouse events.
/// Inherit from this class if you wish to receive mouse events.
class MouseListener{
public:
    /// Virtual mouse button pressed
    ///
    /// Pure virtual function that provides the mouse button pressed interface.
    /// This function is called every time a mouse button is pressed.
    /// @param button mouse button that is pressed
    /// @param x relative position of the mouse button on the x-axis.
    /// @param y relative position of the mouse button on the y-axis.
    virtual void mouseButtonPressed(const Qt::MouseButton &button, int x, int y) = 0;
};

#endif // _MOUSELISTENER_HPP

