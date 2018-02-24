#ifndef SETTINGS_H
#define SETTINGS_H

//Project
#include "Accessible.h"
#include "AttributeList.h"


/**
 * @brief The Settings class
 */
class Settings : public Accessible{


public:

    int maxPlayers;
    int maxPlayerGroups;
    int maxComponentStacks;
    int maxPhysicalSpaces;
    int actualPlayers;
    int actualPlayerGroups;
    int actualComponentStacks;
    int actualPhysicalSpaces;
    AttributeList* extraSettings;

    Settings();
    ~Settings();

    void setExtraSettings(AttributeList* attributeList);

    AttributeList* getExtraSettings();

    void removeExtraSettings();


};

#endif // SETTINGS_H
