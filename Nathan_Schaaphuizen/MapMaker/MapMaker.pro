#-------------------------------------------------
#
# Project created by QtCreator 2015-02-13T12:25:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestProject1
TEMPLATE = app


SOURCES +=\
    Map.cpp \
    Widget.cpp \
    Window.cpp \
    Main.cpp \
    MapUi.cpp

HEADERS  += \
    Map.hpp \
    Widget.hpp \
    Drawable.hpp \
    Window.hpp \
    MouseListener.hpp \
    MapUi.hpp

FORMS    += \
    Widget.ui \
    Window.ui
