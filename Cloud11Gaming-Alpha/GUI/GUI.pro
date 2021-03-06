#-------------------------------------------------
#
# Project created by QtCreator 2015-018-30T14:40:50
#
#-------------------------------------------------

QT+= core gui \
     network \
     widgets \
    multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_Client
TEMPLATE = app


SOURCES += main.cpp\
        ../Utilities/Utility.cpp \
        Client.cpp \
        Drop.cpp \
        ChangeSuit.cpp \
        CloudGaming.cpp \
        Chat.cpp \
        SplashScreen.cpp \
        CatanFace.cpp \
        CrazyFace.cpp \
        ../VelocityEngine/LogicalCore/GameLogic.cpp \
        ../VelocityEngine/StructuralCore/Accessible.cpp \
        ../VelocityEngine/StructuralCore/AccessOverride.cpp \
        ../VelocityEngine/StructuralCore/Attribute.cpp \
        ../VelocityEngine/StructuralCore/AttributeList.cpp \
        ../VelocityEngine/StructuralCore/BoolBundle.cpp \
        ../VelocityEngine/StructuralCore/CharBundle.cpp \
        ../VelocityEngine/StructuralCore/Collectable.cpp \
        ../VelocityEngine/StructuralCore/CollectableComponent.cpp \
        ../VelocityEngine/StructuralCore/CommunicationsControl.cpp \
        ../VelocityEngine/StructuralCore/Component.cpp \
        ../VelocityEngine/StructuralCore/ComponentStack.cpp \
        ../VelocityEngine/StructuralCore/ComponentStackManager.cpp \
        ../VelocityEngine/StructuralCore/Coordinates.cpp \
        ../VelocityEngine/StructuralCore/DataBundle.cpp \
        ../VelocityEngine/StructuralCore/DoubleBundle.cpp \
        ../VelocityEngine/StructuralCore/GameStructure.cpp \
        ../VelocityEngine/StructuralCore/GlobalCounters.cpp \
        ../VelocityEngine/StructuralCore/Glossary.cpp \
        ../VelocityEngine/StructuralCore/GroupScoreRecord.cpp \
        ../VelocityEngine/StructuralCore/ID.cpp \
        ../VelocityEngine/StructuralCore/IntBundle.cpp \
        ../VelocityEngine/StructuralCore/LocatableCollectableComponent.cpp \
        ../VelocityEngine/StructuralCore/LocatableComponent.cpp \
        ../VelocityEngine/StructuralCore/LocatableTradableComponent.cpp \
        ../VelocityEngine/StructuralCore/Location.cpp \
        ../VelocityEngine/StructuralCore/LongBundle.cpp \
        ../VelocityEngine/StructuralCore/MovableCollectableComponent.cpp \
        ../VelocityEngine/StructuralCore/MovableComponent.cpp \
        ../VelocityEngine/StructuralCore/MovableTradableComponent.cpp \
        ../VelocityEngine/StructuralCore/PhysicalSpace.cpp \
        ../VelocityEngine/StructuralCore/PhysicalSpaceManager.cpp \
        ../VelocityEngine/StructuralCore/Player.cpp \
        ../VelocityEngine/StructuralCore/PlayerGroup.cpp \
        ../VelocityEngine/StructuralCore/PlayerGroupManager.cpp \
        ../VelocityEngine/StructuralCore/PlayerScoreRecord.cpp \
        ../VelocityEngine/StructuralCore/ProgressControl.cpp \
        ../VelocityEngine/StructuralCore/PtrBundle.cpp \
        ../VelocityEngine/StructuralCore/ScoreTracker.cpp \
        ../VelocityEngine/StructuralCore/Settings.cpp \
        ../VelocityEngine/StructuralCore/StatusTracker.cpp \
        ../VelocityEngine/StructuralCore/StringBundle.cpp \
        ../VelocityEngine/StructuralCore/TimeTracker.cpp \
        ../VelocityEngine/StructuralCore/Tradable.cpp \
        ../VelocityEngine/StructuralCore/TradableComponent.cpp \
        ../VelocityEngine/StructuralCore/Type.cpp \
        ../VelocityEngine/MathLibraries/Hexagon2D.cpp \
        ../VelocityEngine/MathLibraries/Randomizer.cpp \
    CatanChooseResource.cpp

HEADERS  += \
         ../Utilities/Utility.h \
        Client.h \
        CloudGaming.h \
        Drop.h \
        ChangeSuit.h \
        Chat.h \
        SplashScreen.h \
        CatanFace.h \
        CrazyFace.h \
        ../VelocityEngine/LogicalCore/GameLogic.h \
        ../VelocityEngine/StructuralCore/Accessible.h \
        ../VelocityEngine/StructuralCore/AccessOverride.h \
        ../VelocityEngine/StructuralCore/Attribute.h \
        ../VelocityEngine/StructuralCore/AttributeList.h \
        ../VelocityEngine/StructuralCore/BoolBundle.h \
        ../VelocityEngine/StructuralCore/CharBundle.h \
        ../VelocityEngine/StructuralCore/Collectable.h \
        ../VelocityEngine/StructuralCore/CollectableComponent.h \
        ../VelocityEngine/StructuralCore/CommunicationsControl.h \
        ../VelocityEngine/StructuralCore/Component.h \
        ../VelocityEngine/StructuralCore/ComponentStack.h \
        ../VelocityEngine/StructuralCore/ComponentStackManager.h \
        ../VelocityEngine/StructuralCore/Coordinates.h \
        ../VelocityEngine/StructuralCore/DataBundle.h \
        ../VelocityEngine/StructuralCore/DoubleBundle.h \
        ../VelocityEngine/StructuralCore/GameStructure.h \
        ../VelocityEngine/StructuralCore/GlobalCounters.h \
        ../VelocityEngine/StructuralCore/Glossary.h \
        ../VelocityEngine/StructuralCore/GroupScoreRecord.h \
        ../VelocityEngine/StructuralCore/ID.h \
        ../VelocityEngine/StructuralCore/IntBundle.h \
        ../VelocityEngine/StructuralCore/LocatableCollectableComponent.h \
        ../VelocityEngine/StructuralCore/LocatableComponent.h \
        ../VelocityEngine/StructuralCore/LocatableTradableComponent.h \
        ../VelocityEngine/StructuralCore/Location.h \
        ../VelocityEngine/StructuralCore/LongBundle.h \
        ../VelocityEngine/StructuralCore/MovableCollectableComponent.h \
        ../VelocityEngine/StructuralCore/MovableComponent.h \
        ../VelocityEngine/StructuralCore/MovableTradableComponent.h \
        ../VelocityEngine/StructuralCore/PhysicalSpace.h \
        ../VelocityEngine/StructuralCore/PhysicalSpaceManager.h \
        ../VelocityEngine/StructuralCore/Player.h \
        ../VelocityEngine/StructuralCore/PlayerGroup.h \
        ../VelocityEngine/StructuralCore/PlayerGroupManager.h \
        ../VelocityEngine/StructuralCore/PlayerScoreRecord.h \
        ../VelocityEngine/StructuralCore/ProgressControl.h \
        ../VelocityEngine/StructuralCore/PtrBundle.h \
        ../VelocityEngine/StructuralCore/ScoreTracker.h \
        ../VelocityEngine/StructuralCore/Settings.h \
        ../VelocityEngine/StructuralCore/StatusTracker.h \
        ../VelocityEngine/StructuralCore/StringBundle.h \
        ../VelocityEngine/StructuralCore/TimeTracker.h \
        ../VelocityEngine/StructuralCore/Tradable.h \
        ../VelocityEngine/StructuralCore/TradableComponent.h \
        ../VelocityEngine/StructuralCore/Type.h\
        ../VelocityEngine/MathLibraries/Hexagon2D.h \
        ../VelocityEngine/MathLibraries/Randomizer.h \
    CatanChooseResource.h


FORMS    += \
    ServerSettings.ui \
    Drop.ui \
    ChangeSuit.ui \
    CloudGaming.ui \
    Chat.ui \
    CatanFace.ui \
    CrazyFace.ui \
    SplashScreen.ui \
    CatanChooseResource.ui


RESOURCES += \
    map.qrc

INCLUDEPATH += $$PWD \
    ../VelocityEngine/StructuralCore/ \
    ../VelocityEngine/LogicalCore/ \
    ../VelocityEngine/MathLibraries/ \
    ../Games/

