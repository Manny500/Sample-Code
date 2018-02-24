#include "Settings.h"

/**
 * @brief Settings::Settings
 */
Settings::Settings(){

    this->maxPlayers = -1;
    this->maxPlayerGroups = -1;
    this->maxComponentStacks = -1;
    this->maxPhysicalSpaces = -1;
    this->actualPlayers = 0;
    this->actualPlayerGroups = 0;
    this->actualComponentStacks = 0;
    this->actualPhysicalSpaces = 0;

    this->extraSettings = new AttributeList();
}

/**
 * @brief Settings::~Settings
 */
Settings::~Settings(){

    removeExtraSettings();

    delete extraSettings;

    this->extraSettings = NULL;
}

/**
 * @brief Settings::setExtraSettings
 * @param attributeList
 */
void Settings::setExtraSettings(AttributeList* attributeList){

    this->extraSettings = attributeList;
}

/**
 * @brief Settings::getExtraSettings
 * @return
 */
AttributeList* Settings::getExtraSettings(){

    return this->extraSettings;
}

/**
 * @brief Settings::removeExtraSettings
 */
void Settings::removeExtraSettings(){

    this->extraSettings->removeAllAttributes();
}
