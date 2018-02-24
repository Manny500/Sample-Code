#ifndef ACCESSOVERRIDE_H
#define ACCESSOVERRIDE_H

//Project
#include "PlayerGroup.h"
#include "Location.h"


/**
 * @brief The AccessOverride class
 */
class AccessOverride : public Accessible{


public:

    Player* playerAccess;
    PlayerGroup* playerGroupAccess;
    Component* componentAccess;
    Location* locationAccess;
    ComponentStack* componentStackAccess;
    Accessible* access1;
    Accessible* access2;
    Accessible* access3;
    Accessible* access4;
    std::vector<Accessible*>* extraAccesses;

    AccessOverride();
    ~AccessOverride();

    Accessible* getExtraAccess(unsigned int index);

    /**
     * @brief addExtraAccess
     * @param accessible
     * @return index at which parameter:accessible is stored
     */
    unsigned int addExtraAccess(Accessible* accessible);

    void removeExtraAccessAt(unsigned int index);
    void removeAllExtraAccesses();


};

#endif // ACCESSOVERRIDE_H
