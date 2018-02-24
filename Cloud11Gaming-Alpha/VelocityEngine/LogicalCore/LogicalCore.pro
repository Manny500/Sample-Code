TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    GameLogic.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    GameLogic.h

