TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Accessible.cpp \
    AccessOverride.cpp \
    Attribute.cpp \
    AttributeList.cpp \
    BoolBundle.cpp \
    CharBundle.cpp \
    Collectable.cpp \
    CollectableComponent.cpp \
    CommunicationsControl.cpp \
    Component.cpp \
    ComponentStack.cpp \
    ComponentStackManager.cpp \
    Coordinates.cpp \
    DataBundle.cpp \
    DoubleBundle.cpp \
    GameStructure.cpp \
    GlobalCounters.cpp \
    Glossary.cpp \
    GroupScoreRecord.cpp \
    ID.cpp \
    IntBundle.cpp \
    LocatableCollectableComponent.cpp \
    LocatableComponent.cpp \
    LocatableTradableComponent.cpp \
    Location.cpp \
    LongBundle.cpp \
    MovableCollectableComponent.cpp \
    MovableComponent.cpp \
    MovableTradableComponent.cpp \
    PhysicalSpace.cpp \
    PhysicalSpaceManager.cpp \
    Player.cpp \
    PlayerGroup.cpp \
    PlayerGroupManager.cpp \
    PlayerScoreRecord.cpp \
    ProgressControl.cpp \
    PtrBundle.cpp \
    ScoreTracker.cpp \
    Settings.cpp \
    StatusTracker.cpp \
    StringBundle.cpp \
    TimeTracker.cpp \
    Tradable.cpp \
    TradableComponent.cpp \
    Type.cpp \
    ../MathLibraries/Randomizer.cpp



include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Accessible.h \
    AccessOverride.h \
    Attribute.h \
    AttributeList.h \
    BoolBundle.h \
    CharBundle.h \
    Collectable.h \
    CollectableComponent.h \
    CommunicationsControl.h \
    Component.h \
    ComponentStack.h \
    ComponentStackManager.h \
    Coordinates.h \
    DataBundle.h \
    DoubleBundle.h \
    GameStructure.h \
    GlobalCounters.h \
    Glossary.h \
    GroupScoreRecord.h \
    ID.h \
    IntBundle.h \
    LocatableCollectableComponent.h \
    LocatableComponent.h \
    LocatableTradableComponent.h \
    Location.h \
    LongBundle.h \
    MovableCollectableComponent.h \
    MovableComponent.h \
    MovableTradableComponent.h \
    PhysicalSpace.h \
    PhysicalSpaceManager.h \
    Player.h \
    PlayerGroup.h \
    PlayerGroupManager.h \
    PlayerScoreRecord.h \
    ProgressControl.h \
    PtrBundle.h \
    ScoreTracker.h \
    Settings.h \
    StatusTracker.h \
    StringBundle.h \
    TimeTracker.h \
    Tradable.h \
    TradableComponent.h \
    Type.h \
    ../MathLibraries/Randomizer.h


INCLUDEPATH += $$PWD \
    ../MathLibraries/

