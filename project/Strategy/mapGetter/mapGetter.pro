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
        "$$PWD/../../../src/communication/persistant_storage/databaseconnector.cpp"\
        "$$PWD/../../../src/communication/persistant_storage/QRCode.cpp"\
        "$$PWD/../../../src/map/MapStructure/line.cpp"\
        "$$PWD/../../../src/map/MapStructure/map.cpp"\
        "$$PWD/../../../src/map/MapStructure/polygon.cpp"\
        "$$PWD/../../../src/map/MapStructure/point.cpp"

HEADERS +=
        "$$PWD/../../../src/communication/persistant_storage/databaseconnector.h"\
        "$$PWD/../../../src/communication/persistant_storage/QRCode.h"\
        "$$PWD/../../../src/map/MapStructure/line.hpp"\
        "$$PWD/../../../src/map/MapStructure/map.hpp"\
        "$$PWD/../../../src/map/MapStructure/polygon.h"\
        "$$PWD/../../../src/map/MapStructure/point.hpp"

INCLUDEPATH += "$$PWD"
