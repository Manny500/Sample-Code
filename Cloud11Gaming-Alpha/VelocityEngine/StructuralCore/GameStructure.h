#ifndef GAMESTRUCTURE_H
#define GAMESTRUCTURE_H

//General
#include <stdlib.h>

//Project
#include "CommunicationsControl.h"
#include "Settings.h"
#include "ProgressControl.h"
#include "Glossary.h"
#include "PlayerGroupManager.h"
#include "ComponentStackManager.h"
#include "PhysicalSpaceManager.h"
#include "AccessOverride.h"


class GameStructure{


public:


    CommunicationsControl* communicationControl;
    Settings* settings;
    ProgressControl* progressControl;
    Glossary* glossary;
    PlayerGroupManager* playerGroupManager;
    ComponentStackManager* componentStackManager;
    PhysicalSpaceManager* physicalSpaceManager;
    AccessOverride* accessOverride;

    GameStructure();
    ~GameStructure();

    void cascade();



};

#endif // GAMESTRUCTURE_H
