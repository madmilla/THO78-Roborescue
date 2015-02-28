#-------------------------------------------------
#
# Project created by QtCreator 2015-02-23T15:09:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapGrid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    exitDialog.cpp \
    optionsdialog.cpp \
    savedialog.cpp \
    mapwindow.cpp \
    map.cpp \
    cell.cpp \
    displaymap.cpp

HEADERS  += mainwindow.h \
    exitDialog.h \
    optionsdialog.h \
    savedialog.h \
    mapwindow.h \
    map.h \
    cell.h \
    displaymap.h

FORMS    += mainwindow.ui \
    exitDialog.ui \
    optionsdialog.ui \
    savedialog.ui \
    mapwindow.ui

RESOURCES += \
    resources.qrc
