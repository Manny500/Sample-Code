#ifndef PLAYERGROUPMANAGER_H
#define PLAYERGROUPMANAGER_H

//Project
#include "PlayerGroup.h"


/**
 * @brief The PlayerGroupManager class
 */
class PlayerGroupManager : public Accessible{


public:

    std::vector<PlayerGroup*>* playerGroups;

    PlayerGroupManager();
    ~PlayerGroupManager();

    void addPlayerGroup(PlayerGroup* playerGroup);
    void setPlayerGroups(std::vector<PlayerGroup*>* playerGroups);

    PlayerGroup* getPlayerGroupAt(unsigned int index);
    std::vector<PlayerGroup*>* getPlayerGroupsOfType(Type* type);

    void removePlayerGroupAt(unsigned int index);
    void removePlayerGroupsOfType(Type* type);
    void removeAllPlayerGroups();


};

#endif // PLAYERGROUPMANAGER_H
