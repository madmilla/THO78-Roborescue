/// @file Widget.cpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#include "Widget.hpp"
#include "Drawable.hpp"
#include "MouseListener.hpp"
#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <vector>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //Install event filter so we can catch mouse events on the widget.
    installEventFilter(this);
}


void Widget::paintEvent(QPaintEvent *event){
    //We are not doing anything with the event.
    //So we void it to indicate that we are not using it.
    //Also to avoid warnings and silence nagging compilers.
    (void)event;
    //Create a new paint object which we going to use to paint on this widget.
    QPainter painter(this);
    //For all the drawables that have registered themselves:
    for(unsigned int i=0; i<drawables.size(); ++i){
        //Call the draw event.
        //The drawable instance itself will use the painter passed as parameter
        //to do the actual drawing.
        drawables[i]->draw(painter);
    }
}


void Widget::addDrawable(Drawable *newDrawable){
    //Register a new drawable.
    drawables.push_back(newDrawable);
}

void Widget::addMouseListener(MouseListener *newMouseListener){
    //Register a new mouse listener.
    mouseListeners.push_back(newMouseListener);
}

bool Widget::eventFilter(QObject *obj, QEvent *event){
    //We are not doing anything with the obj.
    //So we void it to indicate that we are not using it.
    //Also to avoid warnings and silence nagging compilers.
    (void)obj;
    //Check if the type of event was mouse button being pressed
    //or a mouse button being double clicked.
    //A double click is not also registered as mouse button being pressed.
    //mouseButtonPressed() needs to be called on any mouse click.
    //Therefore we check for both normal and double clicks.
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick){
        //Create a mouse event from the general event.
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        //For all the mouse listeners that have registered themselves:
        for(unsigned int i=0; i<mouseListeners.size(); ++i){
            //Call the mouse button pressed event.
            //The mouselistener instance itself will react to the button.
            mouseListeners[i]->mouseButtonPressed(mouseEvent->button(), mouseEvent->x(), mouseEvent->y());
        }
    }
    //Call update so we can redraw any changes that have occurred during the
    //mouse button events.
    update();
    //Return false so other instances may also receive this event.
    return false;
}

