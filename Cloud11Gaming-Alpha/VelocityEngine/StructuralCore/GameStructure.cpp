#include "GameStructure.h"

/**
 * @brief GameStructure::GameStructure
 */
GameStructure::GameStructure(){

    this->communicationControl = new CommunicationsControl();
    this->settings = new Settings();
    this->progressControl = new ProgressControl();
    this->glossary = new Glossary();
    this->playerGroupManager = new PlayerGroupManager();
    this->componentStackManager = new ComponentStackManager();
    this->physicalSpaceManager = new PhysicalSpaceManager();
    this->accessOverride = new AccessOverride();
}

/**
 * @brief GameStructure::~GameStructure
 */
GameStructure::~GameStructure(){

    cascade();
}

/**
 * @brief GameStructure::cascade
 */
void GameStructure::cascade(){

    delete this->accessOverride;
    delete this->physicalSpaceManager;
    delete this->componentStackManager;
    delete this->playerGroupManager;
    delete this->glossary;
    delete this->progressControl;
    delete this->settings;
    delete this->communicationControl;

    this->communicationControl = NULL;
    this->settings = NULL;
    this->progressControl = NULL;
    this->progressControl = NULL;
    this->glossary = NULL;
    this->playerGroupManager = NULL;
    this->componentStackManager = NULL;
    this->physicalSpaceManager = NULL;
    this->accessOverride = NULL;
}
