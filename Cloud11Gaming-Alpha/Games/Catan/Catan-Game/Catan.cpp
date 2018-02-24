#include "Catan.h"


Catan::Catan(){}


Catan::~Catan(){

    cascade();
}


/**
 * @brief Catan::staticSettings sets the player number and number of physical spaces.
 */
void Catan::staticSettings(){

    settings->maxPlayers = 4;
    settings->maxPhysicalSpaces = 2;
}


void Catan::startCommunication(){}


void Catan::dynamicSettings(){}


/**
 * @brief Catan::startProgress sets the number of players per round and adds 8 status values indicating free road
 * and free settlements each of the four players has.
 */
void Catan::startProgress(){

    progressControl->timeTracker->turnPerRound = 4;
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(0, "Free Road Red", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(1, "Free Road Yellow", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(2, "Free Road Green", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(3, "Free Road Blue", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(4, "Free Settlement Red", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(5, "Free Settlement Yellow", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(6, "Free Settlement Green", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(7, "Free Settlement Blue", 2));

    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(8, "Initial Settlements Red", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(9, "Initial Settlements Yellow", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(10, "Initial Settlements Green", 2));
    progressControl->statusTracker->getExtraStatuses()->addAttribute(new Attribute(11, "Initial Settlements Blue", 2));
}


/**
 * @brief Catan::buildGlossary builds types that are used by multiple stacks, components, locations and players.
 */
void Catan::buildGlossary(){

    Type* newType;

    /* Public or player-owned stacks */
    glossary->addComponentStackType(new Type(0, "Clay"));
    glossary->addComponentStackType(new Type(1, "Wool"));
    glossary->addComponentStackType(new Type(2, "Ore"));
    glossary->addComponentStackType(new Type(3, "Food"));
    glossary->addComponentStackType(new Type(4, "Lumber"));

    /* Public stacks */
    newType = new Type(5, "Development Cards");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Clay Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(1, "Wool Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(2, "Ore Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(3, "Food Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(4, "Lumber Cost", 0));
    glossary->addComponentStackType(newType);
    glossary->addComponentStackType(new Type(6, "Road Red"));
    glossary->addComponentStackType(new Type(7, "Road Yellow"));
    glossary->addComponentStackType(new Type(8, "Road Green"));
    glossary->addComponentStackType(new Type(9, "Road Blue"));
    glossary->addComponentStackType(new Type(10, "Settlement Red"));
    glossary->addComponentStackType(new Type(11, "Settlement Yellow"));
    glossary->addComponentStackType(new Type(12, "Settlement Green"));
    glossary->addComponentStackType(new Type(13, "Settlement Blue"));
    glossary->addComponentStackType(new Type(14, "City Red"));
    glossary->addComponentStackType(new Type(15, "City Yellow"));
    glossary->addComponentStackType(new Type(16, "City Green"));
    glossary->addComponentStackType(new Type(17, "City Blue"));
    glossary->addComponentStackType(new Type(18, "Special Achievements"));
    glossary->addComponentStackType(new Type(19, "Robber"));

    /* Player-owned stacks */
    newType = new Type(20, "Road");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Clay Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(1, "Wool Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(2, "Ore Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(3, "Food Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(4, "Lumber Cost", 1));
    glossary->addComponentStackType(newType);
    newType = new Type(21, "Settlement");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Clay Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(1, "Wool Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(2, "Ore Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(3, "Food Cost", 1));
    newType->getAttributeList()->addAttribute(new Attribute(4, "Lumber Cost", 1));
    glossary->addComponentStackType(newType);
    newType = new Type(22, "City");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Clay Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(1, "Wool Cost", 0));
    newType->getAttributeList()->addAttribute(new Attribute(2, "Ore Cost", 3));
    newType->getAttributeList()->addAttribute(new Attribute(3, "Food Cost", 2));
    newType->getAttributeList()->addAttribute(new Attribute(4, "Lumber Cost", 0));
    glossary->addComponentStackType(newType);
    glossary->addComponentStackType(new Type(23, "Knight"));
    glossary->addComponentStackType(new Type(24, "Road Building"));
    glossary->addComponentStackType(new Type(25, "Year of Plenty"));
    glossary->addComponentStackType(new Type(26, "Monopoly"));
    glossary->addComponentStackType(new Type(27, "Victory Point"));

    /* Components */
    glossary->addComponentType(new Type(0, "Clay"));
    glossary->addComponentType(new Type(1, "Wool"));
    glossary->addComponentType(new Type(2, "Ore"));
    glossary->addComponentType(new Type(3, "Food"));
    glossary->addComponentType(new Type(4, "Lumber"));
    glossary->addComponentType(new Type(5, "Knight"));
    glossary->addComponentType(new Type(6, "Road Building"));
    glossary->addComponentType(new Type(7, "Year of Plenty"));
    glossary->addComponentType(new Type(8, "Monopoly"));
    glossary->addComponentType(new Type(9, "Victory Point"));
    glossary->addComponentType(new Type(10, "Road"));
    glossary->addComponentType(new Type(11, "Settlement"));
    glossary->addComponentType(new Type(12, "City"));
    glossary->addComponentType(new Type(13, "Longest Road"));
    glossary->addComponentType(new Type(14, "Largest Army"));
    glossary->addComponentType(new Type(15, "Robber"));

    /* Locations */
    newType = new Type(0, "Hills");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 0, "Clays"));
    glossary->addLocationType(newType);
    newType = new Type(1, "Pasture");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 1, "Wool"));
    glossary->addLocationType(newType);
    newType = new Type(2, "Mountain");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 2, "Ore"));
    glossary->addLocationType(newType);
    newType = new Type(3, "Fields");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 3, "Food"));
    glossary->addLocationType(newType);
    newType = new Type(4, "Forest");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 4, "Lumber"));
    glossary->addLocationType(newType);
    newType = new Type(5, "Desert");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 5, "Nothing"));
    glossary->addLocationType(newType);
    newType = new Type(6, "Sea");
    newType->getAttributeList()->addAttribute(new Attribute(0, "Resource Production", 6, "Nothing"));
    glossary->addLocationType(newType);

    /* Players */
    glossary->addPlayerType(new Type(0, "Red"));
    glossary->addPlayerType(new Type(1, "Yellow"));
    glossary->addPlayerType(new Type(2, "Green"));
    glossary->addPlayerType(new Type(3, "Blue"));

    newType = NULL;
}


/**
 * @brief Catan::setActualPlayers sets the number of actual players in this game
 * @param actualPlayer
 */
void Catan::setActualPlayers(unsigned int actualPlayer){

    settings->actualPlayers = actualPlayer;
}


/**
 * @brief Catan::buildPlayerGroups creates players, adds their score object, attributes and then adds then to PlayerGroupManager.
 */
void Catan::buildPlayerGroups(){

    PlayerGroup* onlyGroup = new PlayerGroup();
    Player* newPlayer;

    for (int i = 0; i < settings->actualPlayers; i ++){

        newPlayer = new Player(progressControl->globalCounters->playerCreatedCount);
        progressControl->globalCounters->incrementPlayerCount();
        newPlayer->setType(glossary->getPlayerType(i)); // Player's color code.

        PlayerScoreRecord* scoreRecord = new PlayerScoreRecord(newPlayer->getID()); // Attaches score.
        newPlayer->setScoreRecord(scoreRecord);
        progressControl->scoreTracker->addPlayerScoreRecord(scoreRecord);

        /* Adds player-owned stacks */
        for (unsigned int k = 0; k < 5; k ++)
            newPlayer->getCollected()->addComponentStack(new ComponentStack(glossary->getComponentStackType(k)));
        for (unsigned int k = 0; k < 8; k ++)
            newPlayer->getCollected()->addComponentStack(new ComponentStack(glossary->getComponentStackType(20+k)));

        newPlayer->getAttributeList()->addAttribute(new Attribute(0, "Max road length", 0));
        newPlayer->getAttributeList()->addAttribute(new Attribute(1, "Knights played", 0));


        onlyGroup->addPlayer(newPlayer);
    }

    playerGroupManager->addPlayerGroup(onlyGroup);

    onlyGroup = NULL;
    newPlayer = NULL;
}


/**
 * @brief Catan::setPlayerName sets the name of player indicated by its index
 * @param playerIndex
 * @param name
 */
void Catan::setPlayerName(unsigned int playerIndex, std::string name){

    playerGroupManager->getPlayerGroupAt(0)->getPlayerAt(playerIndex)->setName(name);
}


/**
 * @brief Catan::buildComponentStacks builds components of the game.
 */
void Catan::buildComponentStacks(){

    ComponentStack* newStack;

    /* Adds resource cards */
    for (unsigned int i = 0; i < 5; i ++){
        newStack = new ComponentStack(glossary->getComponentStackType(i));
        for (unsigned int k = 0; k < 95; k++){
            Component* rscCard = new Component(glossary->getComponentType(i));
            newStack->addComponent(rscCard);
            rscCard = NULL;
        }
        componentStackManager->addComponentStack(newStack);
    }
    newStack = NULL;

    /* Adds development cards */
    newStack = new ComponentStack(glossary->getComponentStackType(5));

    for (unsigned int i = 0; i < 14; i ++){
        Component* knightCard = new Component(glossary->getComponentType(5));
        newStack->addComponent(knightCard);
        knightCard = NULL;
    }
    for (unsigned int i = 0; i < 2; i ++){
        Component* roadCard = new Component(glossary->getComponentType(6));
        newStack->addComponent(roadCard);
        roadCard = NULL;
    }
    for (unsigned int i = 0; i < 2; i ++){
        Component* plentyCard = new Component(glossary->getComponentType(7));
        newStack->addComponent(plentyCard);
        plentyCard = NULL;
    }
    for (unsigned int i = 0; i < 2; i ++){
        Component* monoCard = new Component(glossary->getComponentType(8));
        newStack->addComponent(monoCard);
        monoCard = NULL;
    }
    for (unsigned int i = 0; i < 5; i ++){
        Component* victoryCard = new Component(glossary->getComponentType(9));
        newStack->addComponent(victoryCard);
        victoryCard = NULL;
    }
    newStack->randomizeOrder(10);
    componentStackManager->addComponentStack(newStack);
    newStack = NULL;

    /* Adds construction cards */
    for (unsigned int i = 0; i < 4; i ++){

        newStack = new ComponentStack(glossary->getComponentStackType(6 + i));
        for (unsigned int k = 0; k < 15; k ++){
            Component* road = new LocatableCollectableComponent(glossary->getComponentType(10));
            newStack->addComponent(road);
            road = NULL;
        }
        componentStackManager->addComponentStack(newStack);
        newStack = NULL;

        newStack = new ComponentStack(glossary->getComponentStackType(10 + i));
        for (unsigned int k = 0; k < 5; k ++){
            Component* settle = new LocatableCollectableComponent(glossary->getComponentType(11));
            newStack->addComponent(settle);
            settle = NULL;
        }
        componentStackManager->addComponentStack(newStack);
        newStack = NULL;

        newStack = new ComponentStack(glossary->getComponentStackType(14 + i));
        for (unsigned int k = 0; k < 4; k ++){
            Component* city = new LocatableCollectableComponent(glossary->getComponentType(12));
            newStack->addComponent(city);
            city = NULL;
        }
        componentStackManager->addComponentStack(newStack);
        newStack = NULL;
    }

    /* Adds special cards */
    newStack = new ComponentStack(glossary->getComponentStackType(18));
    Component* longestRoad = new CollectableComponent(glossary->getComponentType(13));
    newStack->addComponent(longestRoad);
    longestRoad = NULL;
    Component* largestArmy = new CollectableComponent(glossary->getComponentType(14));
    newStack->addComponent(largestArmy);
    largestArmy = NULL;
    componentStackManager->addComponentStack(newStack);
    newStack = NULL;

    /* Adds robber */
    newStack = new ComponentStack(glossary->getComponentStackType(19));
    LocatableComponent* robber = new LocatableComponent(glossary->getComponentType(15));
    robber->setCoordinates(-2, 0, 0, 0);
    robber->deactivate();
    newStack->addComponent(robber);
    robber = NULL;
    componentStackManager->addComponentStack(newStack);
    newStack = NULL;
}


/**
 * @brief Catan::buildPhysicalSpaces creates physical spaces (map, grid) that are used to track physical locations of
 * game components.
 */
void Catan::buildPhysicalSpaces(){

    /* Adds terrains map */
    PhysicalSpace* terrainMap;

    terrainMap = new PhysicalSpace(0, "Terrain");
    /* Formation 66 >> 6 : composite shape; 6 : cell shape. */
    /* Layout 001 >> 00 : top left cell rotation; 1 : top left cell not at corner. */
    terrainMap->defineSpace(66, 1, 7, 7, 1);
    terrainMap->offsetOrigin(3, 3, 0); // Origin offset.

    /* Assign location types. */
    terrainMap->assignLocation(0, -2, 0, glossary->getLocationType(4));
    terrainMap->assignLocation(1, -2, 0, glossary->getLocationType(1));
    terrainMap->assignLocation(2, -2, 0, glossary->getLocationType(3));

    terrainMap->assignLocation(-1, -1, 0, glossary->getLocationType(0));
    terrainMap->assignLocation(0, -1, 0, glossary->getLocationType(2));
    terrainMap->assignLocation(1, -1, 0, glossary->getLocationType(0));
    terrainMap->assignLocation(2, -1, 0, glossary->getLocationType(1));

    terrainMap->assignLocation(-2, 0, 0, glossary->getLocationType(5));
    terrainMap->assignLocation(-1, 0, 0, glossary->getLocationType(4));
    terrainMap->assignLocation(0, 0, 0, glossary->getLocationType(3));
    terrainMap->assignLocation(1, 0, 0, glossary->getLocationType(4));
    terrainMap->assignLocation(2, 0, 0, glossary->getLocationType(3));

    terrainMap->assignLocation(-2, 1, 0, glossary->getLocationType(0));
    terrainMap->assignLocation(-1, 1, 0, glossary->getLocationType(1));
    terrainMap->assignLocation(0, 1, 0, glossary->getLocationType(1));
    terrainMap->assignLocation(1, 1, 0, glossary->getLocationType(2));

    terrainMap->assignLocation(-2, 2, 0, glossary->getLocationType(2));
    terrainMap->assignLocation(-1, 2, 0, glossary->getLocationType(3));
    terrainMap->assignLocation(0, 2, 0, glossary->getLocationType(4));

    terrainMap->assignLocation(0, -3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(1, -3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(2, -3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(3, -3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(3, -2, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(3, -1, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(3, 0, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(2, 1, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(1, 2, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(0, 3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-1, 3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-2, 3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-3, 3, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-3, 2, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-3, 1, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-3, 0, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-2, -1, 0, glossary->getLocationType(6));
    terrainMap->assignLocation(-1, -2, 0, glossary->getLocationType(6));


    /* Assign chits */
    terrainMap->getLocation(0, -2, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 11));
    terrainMap->getLocation(1, -2, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 12));
    terrainMap->getLocation(2, -2, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 9));

    terrainMap->getLocation(-1, -1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 4));
    terrainMap->getLocation(0, -1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 6));
    terrainMap->getLocation(1, -1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 5));
    terrainMap->getLocation(2, -1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 10));

    terrainMap->getLocation(-2, 0, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 100));
    terrainMap->getLocation(-1, 0, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 3));
    terrainMap->getLocation(0, 0, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 11));
    terrainMap->getLocation(1, 0, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 4));
    terrainMap->getLocation(2, 0, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 8));

    terrainMap->getLocation(-2, 1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 8));
    terrainMap->getLocation(-1, 1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 10));
    terrainMap->getLocation(0, 1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 9));
    terrainMap->getLocation(1, 1, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 3));

    terrainMap->getLocation(-2, 2, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 5));
    terrainMap->getLocation(-1, 2, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 2));
    terrainMap->getLocation(0, 2, 0)->getAttributeList()->addAttribute(new Attribute(0, "Chit Number", 6));

    physicalSpaceManager->addPhysicalSpace(terrainMap);
    terrainMap = NULL;

    /* Adds grid map */
    PhysicalSpace* gridMap;

    gridMap = new PhysicalSpace(1, "Grid");
    gridMap->defineSpace(66, 1, 9, 9, 5);
    gridMap->offsetOrigin(4, 4, 0);

    for (int z = 0; z < 2; z ++){
        for (int y = -4; y < 5; y ++){
            for (int x = -4; x < 5; x ++){

                Location* loc = new Location(x, y, z, 1);
                loc->getAttributeList()->addAttribute(new Attribute(0, "Red Claim", 0));
                loc->getAttributeList()->addAttribute(new Attribute(1, "Yellow Claim", 0));
                loc->getAttributeList()->addAttribute(new Attribute(2, "Green Claim", 0));
                loc->getAttributeList()->addAttribute(new Attribute(3, "Blue Claim", 0));

                gridMap->assignLocation(x, y, z, loc);
                loc = NULL;
            }
        }
    }

    physicalSpaceManager->addPhysicalSpace(gridMap);
    gridMap = NULL;
}


/**
 * @brief Catan::startGame sets global accesses(pointers) to current player, group and robber.
 */
void Catan::startGame(){

    accessOverride->playerGroupAccess = playerGroupManager->getPlayerGroupAt(0); // The only player group.
    accessOverride->playerAccess = accessOverride->playerGroupAccess->getPlayerAt(0); // Current player.
    accessOverride->componentAccess = componentStackManager->getComponentStackAt(19)->getComponentAt(0); // Robber.
}


void Catan::stage(){}
void Catan::round(){}
void Catan::turn(){}
void Catan::move(){}
void Catan::updateScores(){}
void Catan::clearDeactivated(){}
void Catan::input(){}
void Catan::output(){}
void Catan::cleanUp(){}
void Catan::endGame(){}


/**
 * @brief Catan::rollDice rolls the dice, returns the result and produce resources or activates robber based on results.
 * @return
 */
unsigned int Catan::rollDice(){


    unsigned int result = rndm::dice(2);

    if (result != 7){

        for (int y = -2; y < 3; y ++){
            for (int x = -2; x < 3; x ++){
                AttributeList* attList = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(x, y, 0)->getAttributeList();
                if (attList->getAttributeCount() == 0) break;
                if ((unsigned int)attList->getAttributeValue(0)== result)
                { // If result matches Chit Number of a hex, produce from that hex
                    produceFromHex(x, y);
                }
            }
        }

    } else {

        accessOverride->componentAccess->activate(); // Activate robber.
    }

    return result;
}


int Catan::transfer(ComponentStack* sender, ComponentStack* receiver, unsigned int transferAmount){

    if (transferAmount == 0) return 0;

    for (unsigned int i = 0; i < transferAmount; i ++){
        if (sender->getComponentCount() == 0) return 0;
        receiver->addComponent(sender->retrieveComponentFromTop());
    }

    return 1;
}


void Catan::produceFromHex(int x, int y){

    using namespace hex2dvef0d;

    LocatableComponent* robber = static_cast<LocatableComponent*>(accessOverride->componentAccess);

    if (robber->getX() != x || robber->getY() != y){ // If robber is not on location ...

        Location* hexLoc = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(x, y, 0);

        int rscCode = (int)(hexLoc->getType()->getAttributeList()->getAttributeValue(0));

        if (rscCode < 5){ // resource = 5 means desert (nothing)

            Location* loc;

            loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f0vx(x), f0vy(y), f0vz());
            produceFromIntersection(loc, rscCode);

            loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f60vx(x), f60vy(y), f60vz());
            produceFromIntersection(loc, rscCode);

            loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f120vx(x), f120vy(y), f120vz());
            produceFromIntersection(loc, rscCode);

            loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f180vx(x), f180vy(y), f180vz());
            produceFromIntersection(loc, rscCode);

            loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f240vx(x), f240vy(y), f240vz());
            produceFromIntersection(loc, rscCode);

            loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f300vx(x), f300vy(y), f300vz());
            produceFromIntersection(loc, rscCode);

        }

        hexLoc = NULL;

    } // Else: no resource are produced.

}


void Catan::produceFromIntersection(Location* interLoc, int rscCode){

    for (int i = 0; i < 4; i ++){ // Checks each of the four players' claim

        int claim = (int)(interLoc->getAttributeList()->getAttributeValue(i));

        if (claim > 10){ // Player has settlement or city

            transfer(componentStackManager->getComponentStackAt(rscCode),
                     accessOverride->playerGroupAccess->getPlayerAt(i)->getCollected()->getComponentStackAt(rscCode),
                     claim / 10);

            break; // Stops searching once one player is found to have settlement or city.
        }
    }
}


void Catan::produceFromInitial(int x, int y, int z){

    using namespace hex2dvef0d;

    Location* f1;
    Location* f2;
    Location* f3;
    int rscCode1;
    int rscCode2;
    int rscCode3;

    if (z == 0){

        f1 = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(v60fx(x), v60fy(y), v60fz());
        f2 = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(v180fx(x), v180fy(y), v180fz());
        f3 = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(v300fx(x), v300fy(y), v300fz());
        rscCode1 = (int) f1->getType()->getAttributeList()->getAttributeValue(0);
        rscCode2 = (int) f2->getType()->getAttributeList()->getAttributeValue(0);
        rscCode3 = (int) f3->getType()->getAttributeList()->getAttributeValue(0);

    } else if (z == 1){

        f1 = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(v0fx(x), v0fy(y), v0fz());
        f2 = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(v120fx(x), v120fy(y), v120fz());
        f3 = physicalSpaceManager->getPhysicalSpaceAt(0)->getLocation(v240fx(x), v240fy(y), v240fz());
        rscCode1 = (int) f1->getType()->getAttributeList()->getAttributeValue(0);
        rscCode2 = (int) f2->getType()->getAttributeList()->getAttributeValue(0);
        rscCode3 = (int) f3->getType()->getAttributeList()->getAttributeValue(0);

    }

    if (rscCode1 < 5){
        transfer(componentStackManager->getComponentStackAt(rscCode1),
                 accessOverride->playerAccess->getCollected()->getComponentStackAt(rscCode1), 1);}
    if (rscCode2 < 5){
        transfer(componentStackManager->getComponentStackAt(rscCode2),
                 accessOverride->playerAccess->getCollected()->getComponentStackAt(rscCode2), 1);}
    if (rscCode3 < 5){
        transfer(componentStackManager->getComponentStackAt(rscCode3),
                 accessOverride->playerAccess->getCollected()->getComponentStackAt(rscCode3), 1);}

    f1 = NULL;
    f2 = NULL;
    f3 = NULL;
}


void Catan::bulkSendResources(unsigned int senderIndex, unsigned int receiverIndex, unsigned int clayAmount,
                              unsigned int woolAmount, unsigned int oreAmount, unsigned int foodAmount,
                              unsigned int lumberAmount){

    sendResources(senderIndex, receiverIndex, 0, clayAmount);
    sendResources(senderIndex, receiverIndex, 1, woolAmount);
    sendResources(senderIndex, receiverIndex, 2, oreAmount);
    sendResources(senderIndex, receiverIndex, 3, foodAmount);
    sendResources(senderIndex, receiverIndex, 4, lumberAmount);
}


void Catan::sendResources(unsigned int senderIndex, unsigned int receiverIndex, unsigned int rscCode, unsigned int sendAmount){

    transfer(accessOverride->playerGroupAccess->getPlayerAt(senderIndex)->getCollected()->getComponentStackAt(rscCode),
             accessOverride->playerGroupAccess->getPlayerAt(receiverIndex)->getCollected()->getComponentStackAt(rscCode), sendAmount);
}


/* Construction >> 0: road; 1: settlement; 2:city */
int Catan::placeConstruction(int x, int y, int z, unsigned int construction){

    unsigned int playerIndex = progressControl->timeTracker->turn;

    using namespace hex2dvef0d;

    Player* player = accessOverride->playerAccess;

    if (construction == 0){ // Road

        Location* e = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(x, y, z);
        Location* v1;
        Location* v2;

        if (!(e->isEmpty())) return 0; // Occupied

        if (z == 2){

            v1 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(e60vx(x), e60vy(y), e60vz());
            v2 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(e240vx(x), e240vy(y), e240vz());

        } else if (z == 3){

            v1 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(e0vx(x), e0vy(y), e0vz());
            v2 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(e180vx(x), e180vy(y), e180vz());

        } else if (z == 4){

            v1 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(e120vx(x), e120vy(y), e120vz());
            v2 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(e300vx(x), e300vy(y), e300vz());

        }

        if (v1->getAttributeList()->getAttributeValue(playerIndex) == 0
                && v2->getAttributeList()->getAttributeValue(playerIndex) == 0) return 0; // Unconnected

        ComponentStack* roadStack = componentStackManager->getComponentStackAt(6 + playerIndex);
        if (roadStack->isEmpty()) return 0; // Out of roads

        /* If allowed to build road ... */

        Component* cmptRoad = roadStack->retrieveComponentFromTop();
        player->getCollected()->getComponentStackAt(5)->addComponent(cmptRoad);
        LocatableComponent* road = static_cast<LocatableComponent*>(cmptRoad);
        e->addLocatableComponent(road);

        /* Buying a road increases player's claim of the intersection by 1. */
        v1->getAttributeList()->addToAttributeValue(playerIndex, 1);
        v2->getAttributeList()->addToAttributeValue(playerIndex, 1);

        /* If any of the two end points of this road has exactly two claims by player,
         * it means tha longest roads of this player is increased by one. */
        if ((int)(v1->getAttributeList()->getAttributeValue(playerIndex)) % 10 == 2
                || (int)(v2->getAttributeList()->getAttributeValue(playerIndex)) % 10 == 2)
            player->getAttributeList()->addToAttributeValue(0, 1); // Max road length is increased by 1.

        if (accessOverride->playerAccess->getAttributeList()->getAttributeValue(0) >= 5){

            CollectableComponent* longestRoad = static_cast<CollectableComponent*>(componentStackManager->getComponentStackAt(18)->getComponentAt(1));

            if (longestRoad->getOwnerID() == NULL){

                longestRoad->setOwnerID(accessOverride->playerAccess->getID());
                progressControl->scoreTracker->getPlayerScoreRecord(accessOverride->playerAccess->getID())->addToAltScore1(2);

            } else {

                progressControl->scoreTracker->getPlayerScoreRecord(longestRoad->getOwnerID())->addToAltScore1(-2);
                longestRoad->setOwnerID(accessOverride->playerAccess->getID());
                progressControl->scoreTracker->getPlayerScoreRecord(accessOverride->playerAccess->getID())->addToAltScore1(2);
            }

        }


    } else if (construction == 1){ // Settlement

        Location* v = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(x, y, z);
        Location* v1;
        Location* v2;
        Location* v3;

        if (!(v->isEmpty())) return 0; // Occupied

        if (z == 0){

            v1 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(v0vx(x), v0vy(y), v0vz());
            v2 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(v120vx(x), v120vy(y), v120vz());
            v3 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(v240vx(x), v240vy(y), v240vz());

        } else if (z == 1){

            v1 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(v60vx(x), v60vy(y), v60vz());
            v2 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(v180vx(x), v180vy(y), v180vz());
            v3 = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(v300vx(x), v300vy(y), v300vz());

        }

        if (!(v1->isEmpty() && v2->isEmpty() && v3->isEmpty())) return 0; // Distance Rule

        /* A player's first two initial settlements don't have to be connected. */
        if (progressControl->statusTracker->getExtraStatuses()->getAttributeValue(8 + playerIndex) == 0){
            if (v->getAttributeList()->getAttributeValue(playerIndex) == 0) return 0; // Unconnected
        } else {
            progressControl->statusTracker->getExtraStatuses()->addToAttributeValue(8 + playerIndex, -1);
            produceFromInitial(x, y, z);
        }

        ComponentStack* settleStack = componentStackManager->getComponentStackAt(10 + playerIndex);
        if (settleStack->isEmpty()) return 0; // Out of settlements

        /* If allowed to build settlement ... */

        Component* cmptSettle = settleStack->retrieveComponentFromTop();
        player->getCollected()->getComponentStackAt(6)->addComponent(cmptSettle);
        LocatableComponent* settle = static_cast<LocatableComponent*>(cmptSettle);
        v->addLocatableComponent(settle);

        /* Buying a settlement increases player's claim of the intersection by 10. */
        v->getAttributeList()->addToAttributeValue(playerIndex, 10);

        /* Buying a settlement increase player's VP by 1. */
        progressControl->scoreTracker->getPlayerScoreRecord(player->getID())->addToAltScore1(1);


    } else if (construction == 2){ // City

        Location* v = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(x, y, z);
        if ((int)(v->getAttributeList()->getAttributeValue(playerIndex))/10 != 1) return 0; // No settlement

        ComponentStack* cityStack = componentStackManager->getComponentStackAt(14 + playerIndex);
        if (cityStack->isEmpty()) return 0; // No more city

        /* If allowed to build city ... */

        Component* cmptCity = cityStack->retrieveComponentFromTop();
        player->getCollected()->getComponentStackAt(7)->addComponent(cmptCity);
        LocatableComponent* city = static_cast<LocatableComponent*>(cmptCity);
        v->addLocatableComponent(city);

        /* Buying a city increases player's claim of the intersection by 10. */
        v->getAttributeList()->addToAttributeValue(playerIndex, 10);

        /* Buying a city increase player's VP by 1. */
        progressControl->scoreTracker->getPlayerScoreRecord(player->getID())->addToAltScore1(1);
    }

    makePayment(construction);
    return 1;
}


int Catan::affordable(unsigned int purchasable){

    if (purchasable < 2){
        if (countFreeStuff(purchasable) > 0){
            return 1;}
    }

    unsigned int clayCost;
    unsigned int woolCost;
    unsigned int oreCost;
    unsigned int foodCost;
    unsigned int lumberCost;

    Type* purchasableType;

    if (purchasable == 0){ // Road

        purchasableType = glossary->getComponentStackType(20);
        clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
        woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
        oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
        foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
        lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

    } else if (purchasable == 1){ // Settlement

        purchasableType = glossary->getComponentStackType(21);
        clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
        woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
        oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
        foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
        lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

    } else if (purchasable == 2){ // City

        purchasableType = glossary->getComponentStackType(22);
        clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
        woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
        oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
        foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
        lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

    } else if (purchasable == 3){ // Development Card

        purchasableType = glossary->getComponentStackType(5);
        clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
        woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
        oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
        foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
        lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

    }

    Player*  player = accessOverride->playerAccess;

    if (player->getCollected()->getComponentStackAt(0)->getComponentCount() < clayCost) return 0;
    if (player->getCollected()->getComponentStackAt(1)->getComponentCount() < woolCost) return 0;
    if (player->getCollected()->getComponentStackAt(2)->getComponentCount() < oreCost) return 0;
    if (player->getCollected()->getComponentStackAt(3)->getComponentCount() < foodCost) return 0;
    if (player->getCollected()->getComponentStackAt(4)->getComponentCount() < lumberCost) return 0;

    return 1;
}


void Catan::makePayment(unsigned int purchasable){

    int noFreeStuff = 1;

    if (purchasable < 2){

        if (countFreeStuff(purchasable) > 0) {
            updateFreeStuff(purchasable, -1);
            noFreeStuff = 0;
        }
    }


    if (noFreeStuff == 1){

        unsigned int clayCost;
        unsigned int woolCost;
        unsigned int oreCost;
        unsigned int foodCost;
        unsigned int lumberCost;

        Type* purchasableType;

        if (purchasable == 0){ // Road

            purchasableType = glossary->getComponentStackType(20);
            clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
            woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
            oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
            foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
            lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

        } else if (purchasable == 1){ // Settlement

            purchasableType = glossary->getComponentStackType(21);
            clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
            woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
            oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
            foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
            lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

        } else if (purchasable == 2){ // City

            purchasableType = glossary->getComponentStackType(22);
            clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
            woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
            oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
            foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
            lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

        } else if (purchasable == 3){ // Development Card

            purchasableType = glossary->getComponentStackType(5);
            clayCost = (int)purchasableType->getAttributeList()->getAttributeValue(0);
            woolCost = (int)purchasableType->getAttributeList()->getAttributeValue(1);
            oreCost = (int)purchasableType->getAttributeList()->getAttributeValue(2);
            foodCost = (int)purchasableType->getAttributeList()->getAttributeValue(3);
            lumberCost = (int)purchasableType->getAttributeList()->getAttributeValue(4);

        }

        Player* player = accessOverride->playerAccess;

        transfer(player->getCollected()->getComponentStackAt(0), componentStackManager->getComponentStackAt(0), clayCost);
        transfer(player->getCollected()->getComponentStackAt(1), componentStackManager->getComponentStackAt(1), woolCost);
        transfer(player->getCollected()->getComponentStackAt(2), componentStackManager->getComponentStackAt(2), oreCost);
        transfer(player->getCollected()->getComponentStackAt(3), componentStackManager->getComponentStackAt(3), foodCost);
        transfer(player->getCollected()->getComponentStackAt(4), componentStackManager->getComponentStackAt(4), lumberCost);

    }
}


int Catan::buyDevelopment(){

    if (componentStackManager->getComponentStackAt(5)->isEmpty()) return 0;

    Component* devCard = componentStackManager->getComponentStackAt(5)->retrieveComponentFromTop();

    int cardCode = devCard->getType()->getLabel();

    accessOverride->playerAccess->getCollected()->getComponentStackAt(cardCode + 3)->addComponent(devCard);

    makePayment(3); // 3 means pay for dev card.
    return 1;
}


int Catan::robberActivated(){

    if (accessOverride->componentAccess->isDeactivated()) return 0;
    else return 1;
}


void Catan::moveRobber(int x, int y){

    using namespace hex2dvef0d;

    LocatableComponent* robber = static_cast<LocatableComponent*>(accessOverride->componentAccess);

    robber->setX(x);
    robber->setY(y);

    Location* loc;

    loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f0vx(x), f0vy(y), f0vz());
    robIntersection(loc);

    loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f60vx(x), f60vy(y), f60vz());
    robIntersection(loc);

    loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f120vx(x), f120vy(y), f120vz());
    robIntersection(loc);

    loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f180vx(x), f180vy(y), f180vz());
    robIntersection(loc);

    loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f240vx(x), f240vy(y), f240vz());
    robIntersection(loc);

    loc = physicalSpaceManager->getPhysicalSpaceAt(1)->getLocation(f300vx(x), f300vy(y), f300vz());
    robIntersection(loc);


    accessOverride->componentAccess->deactivate();
}



void Catan::robIntersection(Location* interLoc){

    int playerIndex = progressControl->timeTracker->turn;

    for (int i = 0; i < 4; i ++){ // Checks each of the four players' claim

        if (i == playerIndex) i ++;

        if (i > 3) break;

        int claim = (int)(interLoc->getAttributeList()->getAttributeValue(i));

        if (claim > 10){ // Player has settlement or city

            int iteration = 0;

            while(iteration < 12){

                unsigned int rscCode = rndm::rndInc(0, 4);

                int success =  transfer(accessOverride->playerGroupAccess->getPlayerAt(i)->getCollected()->getComponentStackAt(rscCode),
                                        accessOverride->playerAccess->getCollected()->getComponentStackAt(rscCode),
                                        1);
                if (success)
                    break;

                iteration ++;
            }

            break;
        }

    }

}


int Catan::playKnight(){

    Component* knight = accessOverride->playerAccess->getCollected()->getComponentStackAt(8)->retrieveComponentFromTop();

    if (knight == NULL) return 0;

    accessOverride->playerAccess->getAttributeList()->addToAttributeValue(1, 1); // Increment player's Knight Played Attribute

    if (accessOverride->playerAccess->getAttributeList()->getAttributeValue(1) > 3){

        CollectableComponent* largestArmy = static_cast<CollectableComponent*>(componentStackManager->getComponentStackAt(18)->getComponentAt(1));

        if (largestArmy->getOwnerID() == NULL){

            largestArmy->setOwnerID(accessOverride->playerAccess->getID());
            progressControl->scoreTracker->getPlayerScoreRecord(accessOverride->playerAccess->getID())->addToAltScore1(2);

        } else {

            progressControl->scoreTracker->getPlayerScoreRecord(largestArmy->getOwnerID())->addToAltScore1(-2);
            largestArmy->setOwnerID(accessOverride->playerAccess->getID());
            progressControl->scoreTracker->getPlayerScoreRecord(accessOverride->playerAccess->getID())->addToAltScore1(2);
        }

    }

    delete knight;
    knight = NULL;

    accessOverride->componentAccess->activate();
    return 1;
}


int Catan::playRoadBuilding(){

    Component* rb = accessOverride->playerAccess->getCollected()->getComponentStackAt(9)->retrieveComponentFromTop();

    if (rb == NULL) return 0;

    updateFreeStuff(0, 2);

    delete rb;
    rb = NULL;

    return 1;
}


int Catan::playYOP(int rscCode){

    Component* yop = accessOverride->playerAccess->getCollected()->getComponentStackAt(10)->retrieveComponentFromTop();

    if (yop == NULL) return 0;

    transfer(componentStackManager->getComponentStackAt(rscCode),
             accessOverride->playerAccess->getCollected()->getComponentStackAt(rscCode),
             2);

    delete yop;
    yop = NULL;

    return 1;
}


int Catan::playMonopoly(int rscCode){

    Component* mono = accessOverride->playerAccess->getCollected()->getComponentStackAt(11)->retrieveComponentFromTop();

    if (mono == NULL) return 0;

    for (unsigned int i = 0; i < 4; i ++){
        transfer(accessOverride->playerGroupAccess->getPlayerAt(i)->getCollected()->getComponentStackAt(rscCode),
                 accessOverride->playerAccess->getCollected()->getComponentStackAt(rscCode),
                 accessOverride->playerGroupAccess->getPlayerAt(i)->getCollected()->getComponentStackAt(rscCode)->getComponentCount());
    }

    delete mono;
    mono = NULL;

    return 1;
}


int Catan::playVictoryPoint(){

    int pointsInHand;
    pointsInHand = accessOverride->playerAccess->getCollected()->getComponentStackAt(12)->getComponentCount();

    if (pointsInHand == 0) return 0;

    progressControl->scoreTracker->getPlayerScoreRecord(accessOverride->playerAccess->getID())->addToAltScore1(pointsInHand);

    accessOverride->playerAccess->getCollected()->getComponentStackAt(12)->removeAllComponents();

    return 1;
}


/* Purchasable = 0 for road, = 1 for settlement. */
void Catan::updateFreeStuff(unsigned int purchasable, int update){

    int playerCode = accessOverride->playerAccess->getID()->getSerialID();

    progressControl->statusTracker->getExtraStatuses()->addToAttributeValue(purchasable * 4 + playerCode, update);
}


/* Purchasable = 0 for road, = 1 for settlement. */
unsigned int Catan::countFreeStuff(unsigned int purchasable){

    int playerCode = accessOverride->playerAccess->getID()->getSerialID();

    return (unsigned int) progressControl->statusTracker->getExtraStatuses()->getAttributeValue(purchasable * 4 + playerCode);
}


void Catan::endTurn(){

    accessOverride->componentAccess->deactivate();
    progressControl->timeTracker->incrementTurn();
    accessOverride->playerAccess = accessOverride->playerGroupAccess->getPlayerAt(progressControl->timeTracker->turn);
}


std::string Catan::refreshStats(){

    std::stringstream ss;

    /* Gets each player's max road length, knights played and VP. */
    for (unsigned int i = 0; i < 4; i ++){
        Player* player = accessOverride->playerGroupAccess->getPlayerAt(i);
        ss << player->getAttributeList()->getAttributeValue(0) << ",";
        ss << player->getAttributeList()->getAttributeValue(1) << ",";
        ss << progressControl->scoreTracker->getPlayerScoreRecord(player->getID())->getAltScore1() << ",";
    }

    /* Gets current player's resource counts. */
    for (unsigned int i = 0; i < 5; i ++){
        ss << accessOverride->playerAccess->getCollected()->getComponentStackAt(i)->getComponentCount() << ",";
    }

    /* Gets current player's five development card counts. */
    for (unsigned int i = 8; i < 12; i ++){
        ss << accessOverride->playerAccess->getCollected()->getComponentStackAt(i)->getComponentCount() << ",";
    }

    ss << accessOverride->playerAccess->getCollected()->getComponentStackAt(12)->getComponentCount();

    return ss.str();
}

