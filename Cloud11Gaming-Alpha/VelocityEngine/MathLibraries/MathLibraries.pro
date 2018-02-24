TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Hexagon2D.cpp \
    Randomizer.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Hexagon2D.h \
    Randomizer.h

