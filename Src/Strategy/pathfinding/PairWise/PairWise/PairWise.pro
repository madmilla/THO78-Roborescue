TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    ../pairwisemove.cpp \
    ../../Stop-them-spaces/aStar.cpp \
    ../../../Common/ATV.cpp \
    ../../../Common/dimension.cpp \
    ../../../Common/Lidar.cpp \
    ../../../Common/QuadCopter.cpp \
    ../../../Common/route.cpp \
    ../../../Common/virtualRosbee.cpp \
    ../../../Common/waypoint.cpp \
    ../../../../tests/auto/PairWise-test/main.cpp \
    ../../../../Map/MapStructure/map.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../pairwisemove.h \
    ../../Stop-them-spaces/aStar.h \
    ../../../Common/ATV.h \
    ../../../Common/dimension.h \
    ../../../Common/Lidar.h \
    ../../../Common/QuadCopter.h \
    ../../../Common/route.h \
    ../../../Common/virtualRosbee.h \
    ../../../Common/waypoint.h \
    ../../../../Map/MapStructure/mapImplementation.hpp \
    ../../../../Map/MapStructure/map.hpp

