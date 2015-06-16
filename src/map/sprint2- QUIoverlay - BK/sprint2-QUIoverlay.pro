#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T19:50:25
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sprint2-QUIoverlay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    algorithms.cpp \
    point.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    line.h \
    algorithms.h \
    point.h \
    datatype.h \
    driver.h \
    exception.h \
    mysql_connection.h \
    mysql_driver.h \
    mysql_error.h \
    resultset.h \
    scoped_ptr.hpp \
    shared_ptr.hpp

FORMS    += mainwindow.ui
