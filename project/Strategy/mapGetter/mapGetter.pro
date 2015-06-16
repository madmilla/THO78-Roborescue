#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T14:44:25
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = mapGetter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
        $$PWD/../../src/communication/persistant_storage/databaseconnector.cpp \
        "$$PWD/../../src/map/Sprint1-MapStructure/line.cpp"\
        "$$PWD/../../src/map/Sprint1-MapStructure/map.cpp"\
        "$$PWD/../../src/map/Sprint1-MapStructure/point.cpp"

HEADERS += \
        $$PWD/../../src/communication/persistant_storage/databaseconnector.h \
        $$PWD/../../src/map/Sprint1-MapStructure/line.hpp \
        $$PWD/../../src/map/Sprint1-MapStructure/map.hpp \
        $$PWD/../../src/map/Sprint1-MapStructure/point.hpp

INCLUDEPATH += "C:\Program Files\MySQL\MySQL Connector C 6.1\lib"
