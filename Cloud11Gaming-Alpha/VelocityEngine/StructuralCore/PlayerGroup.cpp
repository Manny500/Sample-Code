#include "PlayerGroup.h"

/**
 * @brief PlayerGroup::PlayerGroup
 */
PlayerGroup::PlayerGroup(){

    this->players = new std::vector<Player*>;
}

/**
 * @brief PlayerGroup::PlayerGroup
 * @param type
 */
PlayerGroup::PlayerGroup(Type *type){

    this->type = type;
    this->players = new std::vector<Player*>;
}

/**
 * @brief PlayerGroup::~PlayerGroup
 */
PlayerGroup::~PlayerGroup(){

    removeAllPlayers();

    delete this->players;

    this->type = NULL;
    this->players = NULL;
}

/**
 * @brief PlayerGroup::setType
 * @param type
 */
void PlayerGroup::setType(Type* type){

    this->type = type;

}

/**
 * @brief PlayerGroup::setPlayers
 * @param players
 */
void PlayerGroup::setPlayers(std::vector<Player*>* players){

    this->players = players;
}

/**
 * @brief PlayerGroup::addPlayer
 * @param player
 */
void PlayerGroup::addPlayer(Player* player){

    this->players->push_back(player);
}

/**
 * @brief PlayerGroup::getType
 * @return
 */
Type* PlayerGroup::getType(){

    return this->type;
}

/**
 * @brief PlayerGroup::getPlayCount
 * @return
 */
unsigned int PlayerGroup::getPlayCount(){

return this->players->size();
}

/**
 * @brief PlayerGroup::getAllPlayers
 * @return
 */
std::vector<Player*>* PlayerGroup::getAllPlayers(){

    return this->players;
}

/**
 * @brief PlayerGroup::getPlayerAt
 * @param index
 * @return
 */
Player* PlayerGroup::getPlayerAt(unsigned int index){

return this->players->at(index);
}

/**
 * @brief PlayerGroup::getPlayerOfSerialID
 * @param serialID
 * @return
 */
Player* PlayerGroup::getPlayerOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player =  this->players->at(i);
        if (player->getID()->getSerialID() == serialID)
            return player;
    }

    return NULL;
}

/**
 * @brief PlayerGroup::getPlayerOfAssignedID
 * @param assignedID
 * @return
 */
Player* PlayerGroup::getPlayerOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player =  this->players->at(i);
        if (player->getID()->getAssignedID() == assignedID)
            return player;
    }

    return NULL;
}

/**
 * @brief PlayerGroup::getPlayersOfType
 * @param type
 * @return
 */
std::vector<Player*>* PlayerGroup::getPlayersOfType(Type* type){

    std::vector<Player*>* playersOfType = new std::vector<Player*>;

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player = this->players->at(i);
        if (player->getType() == type)
            playersOfType->push_back(player);
    }

    return playersOfType;
}

/**
 * @brief PlayerGroup::getPlayerFromTop
 * @return
 */
Player* PlayerGroup::getPlayerFromTop(){

    return this->players->back();
}

/**
 * @brief PlayerGroup::removeDeactivated
 */
void PlayerGroup::removeDeactivated(){

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player = this->players->at(i);
        if (player->isDeactivated()){
            delete player;
            this->players->erase(this->players->begin()+i);
            i --;
        }

    }
}

/**
 * @brief PlayerGroup::removePlayerAt
 * @param index
 */
void PlayerGroup::removePlayerAt(unsigned int index){

delete this->players->at(index);
    this->players->erase(this->players->begin()+index);
}

/**
 * @brief PlayerGroup::removePlayerOfSerialID
 * @param serialID
 */
void PlayerGroup::removePlayerOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player =  this->players->at(i);
        if (player->getID()->getSerialID() == serialID){
            delete player;
            this->players->erase(this->players->begin()+i);
            break;
        }
    }
}

/**
 * @brief PlayerGroup::removePlayerOfAssignedID
 * @param assignedID
 */
void PlayerGroup::removePlayerOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player =  this->players->at(i);
        if (player->getID()->getAssignedID() == assignedID){
            delete player;
            this->players->erase(this->players->begin()+i);
            break;
        }
    }
}

/**
 * @brief PlayerGroup::removePlayersOfType
 * @param type
 */
void PlayerGroup::removePlayersOfType(Type* type){

    for (unsigned int i = 0; i < this->players->size(); i++){
        Player* player =  this->players->at(i);
        if (player->getType() == type){
            delete player;
            this->players->erase(this->players->begin()+i);
            i --;
        }
    }
}

/**
 * @brief PlayerGroup::removeAllPlayers
 */
void PlayerGroup::removeAllPlayers(){

    for (unsigned int i = 0; i < this->players->size(); i++)
        delete this->players->at(i);

    this->players->clear();
}
