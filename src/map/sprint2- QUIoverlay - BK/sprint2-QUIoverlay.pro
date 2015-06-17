#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T19:50:25
#
#-------------------------------------------------

QT       += core gui opengl

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sprint2-QUIoverlay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    algorithms.cpp \
    point.cpp \
    points.cpp \
    map.cpp \
    line.cpp \
    polygon.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    algorithms.h \
    point.hpp \
    points.h \
    datatype.h \
    driver.h \
    exception.h \
    mysql_connection.h \
    mysql_driver.h \
    mysql_error.h \
    resultset.h \
    scoped_ptr.hpp \
    shared_ptr.hpp \
    lines.h \
    map.hpp \
    polygon.hpp \
    line.hpp

FORMS    += mainwindow.ui
