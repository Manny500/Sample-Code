#include "PlayerGroupManager.h"

/**
 * @brief PlayerGroupManager::PlayerGroupManager
 */
PlayerGroupManager::PlayerGroupManager(){

    this->playerGroups = new std::vector<PlayerGroup*>;
}

/**
 * @brief PlayerGroupManager::~PlayerGroupManager
 */
PlayerGroupManager::~PlayerGroupManager(){

    removeAllPlayerGroups();

    delete this->playerGroups;

    this->playerGroups = NULL;
}

/**
 * @brief PlayerGroupManager::addPlayerGroup
 * @param playerGroup
 */
void PlayerGroupManager::addPlayerGroup(PlayerGroup* playerGroup){

    this->playerGroups->push_back(playerGroup);
}

/**
 * @brief PlayerGroupManager::setPlayerGroups
 * @param playerGroups
 */
void PlayerGroupManager::setPlayerGroups(std::vector<PlayerGroup*>* playerGroups){

    this->playerGroups = playerGroups;
}

/**
 * @brief PlayerGroupManager::getPlayerGroupAt
 * @param index
 * @return
 */
PlayerGroup* PlayerGroupManager::getPlayerGroupAt(unsigned int index){

    return this->playerGroups->at(index);
}

/**
 * @brief PlayerGroupManager::getPlayerGroupsOfType
 * @param type
 * @return
 */
std::vector<PlayerGroup*>* PlayerGroupManager::getPlayerGroupsOfType(Type* type){

    std::vector<PlayerGroup*>* groupsOfType = new std::vector<PlayerGroup*>;

    for (unsigned int i = 0; i < this->playerGroups->size(); i++){
        PlayerGroup* group = this->playerGroups->at(i);
        if (group->getType() == type){
            groupsOfType->push_back(group);
        }
    }

    return groupsOfType;
}

/**
 * @brief PlayerGroupManager::removePlayerGroupAt
 * @param index
 */
void PlayerGroupManager::removePlayerGroupAt(unsigned int index){

    delete this->playerGroups->at(index);
    this->playerGroups->erase(this->playerGroups->begin()+index);
}

/**
 * @brief PlayerGroupManager::removePlayerGroupsOfType
 * @param type
 */
void PlayerGroupManager::removePlayerGroupsOfType(Type* type){

    for (unsigned int i = 0; i < this->playerGroups->size(); i++){
        PlayerGroup* group = this->playerGroups->at(i);
        if (group->getType() == type){
            delete group;
            this->playerGroups->erase(this->playerGroups->begin()+i);
            i --;
        }
    }
}

/**
 * @brief PlayerGroupManager::removeAllPlayerGroups
 */
void PlayerGroupManager::removeAllPlayerGroups(){

    for (unsigned int i = 0; i < this->playerGroups->size(); i++)
        delete this->playerGroups->at(i);

    this->playerGroups->clear();
}
