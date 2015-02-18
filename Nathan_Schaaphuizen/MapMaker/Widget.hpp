/// @file Widget.hpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#ifndef _WIDGET_HPP
#define _WIDGET_HPP

#include "Drawable.hpp"
#include "MouseListener.hpp"
#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <vector>

/// Class Widget
/// @brief Paint target on which can be drawn.
///
/// Widget can be used as a paint target.
/// Widget makes use of the Drawable and MouseListener interfaces to draw and pass events
/// to other instances.
class Widget : public QWidget{
    Q_OBJECT

private:
    /// List of drawable instances.
    std::vector<Drawable *> drawables;
    /// List of mouse listeners.
    std::vector<MouseListener *> mouseListeners;

    /// Function called whenever there is a re-pain needed, or when the update() or repaint() function is called.
    void paintEvent(QPaintEvent *event) override;
    /// Function called whenever there is a event. This is any keyboard or mouse event.
    bool eventFilter(QObject *obj, QEvent *event) override;

public:
    /// Constructor
    ///
    /// Creates new instance of Widget.
    /// @param parent is parent object.
    explicit Widget(QWidget *parent = 0);

    /// Add a drawable
    ///
    /// Add new drawable witch can paint on the widget.
    /// The drawable cannot be removed and must live as long as the widget does.
    /// @param newDrawable new drawable to be added.
    void addDrawable(Drawable *newDrawable);

    /// Add a mouse listener
    ///
    /// Add new listener which can receive mouse events from the widget.
    /// The mouse listener cannot be removed and must live as long as the widget does.
    /// @param newMouseListener new mouse listener to be added.
    void addMouseListener(MouseListener *newMouseListener);
};

#endif // _WIDGET_HPP
