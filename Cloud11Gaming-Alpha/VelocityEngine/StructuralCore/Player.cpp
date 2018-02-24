#include "Player.h"

/**
 * @brief Player::Player
 */
Player::Player(){}

/**
 * @brief Player::Player
 * @param id
 */
Player::Player(ID* id)
    : Component(id){

    this->collected = new ComponentStackManager();
}

/**
 * @brief Player::Player
 * @param serialID
 */
Player::Player(unsigned int serialID)
    : Component(serialID){

    this->collected = new ComponentStackManager();
}

/**
 * @brief Player::Player
 * @param serialID
 * @param assignedID
 */
Player::Player(unsigned int serialID, int assignedID)
    : Component(serialID, assignedID){

    this->collected = new ComponentStackManager();
}

/**
 * @brief Player::Player
 * @param id
 * @param type
 */
Player::Player(ID* id, Type* type)
    : Component(id, type){

    this->collected = new ComponentStackManager();
}

/**
 * @brief Player::Player
 * @param serialID
 * @param assignedID
 * @param type
 */
Player::Player(unsigned int serialID, int assignedID, Type* type)
    : Component(serialID, assignedID, type){

    this->collected = new ComponentStackManager();
}

/**
 * @brief Player::~Player
 */
Player::~Player(){

    removeCollected();
    this->name.clear();

    delete collected;

    this->collected = NULL;
    this->scoreRecord = NULL;
    this->groupID = NULL;
}

/**
 * @brief Player::setName
 * @param name
 */
void Player::setName(std::string name){

    this->name = name;
}

/**
 * @brief Player::setGroupID
 * @param groupID
 */
void Player::setGroupID(ID* groupID){

    this->groupID = groupID;
}

/**
 * @brief Player::setWon
 */
void Player::setWon(){

    this->won = 1;
}

/**
 * @brief Player::setLost
 */
void Player::setLost(){

    this->lost = 1;
}

/**
 * @brief Player::setScoreRecord
 * @param scoreRecord
 */
void Player::setScoreRecord(PlayerScoreRecord* scoreRecord){

    this->scoreRecord = scoreRecord;
}

/**
 * @brief Player::setCollected
 * @param collected
 */
void Player::setCollected(ComponentStackManager* collected){

    this->collected = collected;
}

/**
 * @brief Player::getName
 * @return
 */
std::string Player::getName(){

    return this->name;
}

/**
 * @brief Player::getGroupID
 * @return
 */
ID* Player::getGroupID(){

    return this->groupID;
}

/**
 * @brief Player::hasWon
 * @return
 */
int Player::hasWon(){

    return this->won;
}

/**
 * @brief Player::hasLost
 * @return
 */
int Player::hasLost(){

    return this->lost;
}

/**
 * @brief Player::getScoreRecord
 * @return
 */
PlayerScoreRecord* Player::getScoreRecord(){

    return this->scoreRecord;
}

/**
 * @brief Player::getCollected
 * @return
 */
ComponentStackManager* Player::getCollected(){

    return this->collected;
}

/**
 * @brief Player::removeCollected
 */
void Player::removeCollected(){

    this->collected->removeAllComponentStacks();
}
