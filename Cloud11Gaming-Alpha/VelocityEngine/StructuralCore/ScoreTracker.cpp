#include "ScoreTracker.h"

/**
 * @brief ScoreTracker::ScoreTracker
 */
ScoreTracker::ScoreTracker(){

    this->playerScoreRecords = new std::vector<PlayerScoreRecord*>;
    this->groupScoreRecords = new std::vector<GroupScoreRecord*>;
    this->winners = new std::vector<ID*>;
    this->winningGroups = new std::vector<ID*>;
}

/**
 * @brief ScoreTracker::~ScoreTracker
 */
ScoreTracker::~ScoreTracker(){

    removeAllPlayerScoreRecords();
    removeAllGroupScoreRecords();
    removeWinners();
    removeWinningGroups();

    delete this->playerScoreRecords;
    delete this->groupScoreRecords;
    delete this->winners;
    delete this->winningGroups;

    this->playerScoreRecords = NULL;
    this->groupScoreRecords = NULL;
    this->winners = NULL;
    this->winningGroups = NULL;
}

/**
 * @brief ScoreTracker::addPlayerScoreRecord
 * @param playerScoreRecord
 */
void ScoreTracker::addPlayerScoreRecord(PlayerScoreRecord* playerScoreRecord){

    this->playerScoreRecords->push_back(playerScoreRecord);
}

/**
 * @brief ScoreTracker::addGroupScoreRecord
 * @param groupScoreRecord
 */
void ScoreTracker::addGroupScoreRecord(GroupScoreRecord* groupScoreRecord){

    this->groupScoreRecords->push_back(groupScoreRecord);
}

/**
 * @brief ScoreTracker::getPlayerScoreRecordAt
 * @param index
 * @return
 */
PlayerScoreRecord* ScoreTracker::getPlayerScoreRecordAt(unsigned int index){

    return playerScoreRecords->at(index);
}

/**
 * @brief ScoreTracker::getPlayerScoreRecord
 * @param playerID
 * @return
 */
PlayerScoreRecord* ScoreTracker::getPlayerScoreRecord(ID* playerID){

    for (unsigned int i = 0; i < this->playerScoreRecords->size(); i++){
        PlayerScoreRecord* record =  this->playerScoreRecords->at(i);
        if (record->getPlayerID() == playerID)
            return record;
    }

    return NULL;
}

/**
 * @brief ScoreTracker::getGroupPlayerRecordAt
 * @param index
 * @return
 */
GroupScoreRecord* ScoreTracker::getGroupPlayerRecordAt(unsigned int index){

    return groupScoreRecords->at(index);
}

/**
 * @brief ScoreTracker::getGroupPlayerRecord
 * @param groupID
 * @return
 */
GroupScoreRecord* ScoreTracker::getGroupPlayerRecord(ID* groupID){

    for (unsigned int i = 0; i < this->groupScoreRecords->size(); i++){
        GroupScoreRecord* record =  this->groupScoreRecords->at(i);
        if (record->getGroupID() == groupID)
            return record;
    }

    return NULL;
}

/**
 * @brief ScoreTracker::getWinnerCount
 * @return
 */
unsigned int ScoreTracker::getWinnerCount(){

    return this->winners->size();
}

/**
 * @brief ScoreTracker::getWinningGroupCount
 * @return
 */
unsigned int ScoreTracker::getWinningGroupCount(){

    return this->winningGroups->size();
}

/**
 * @brief ScoreTracker::getWinner
 * @param index
 * @return
 */
ID* ScoreTracker::getWinner(unsigned int index){

    return winners->at(index);
}

/**
 * @brief ScoreTracker::getWinningGroup
 * @param index
 * @return
 */
ID* ScoreTracker::getWinningGroup(unsigned int index){

    return winningGroups->at(index);
}

/**
 * @brief ScoreTracker::removePlayerScoreRecord
 * @param playerID
 */
void ScoreTracker::removePlayerScoreRecord(ID* playerID){

    for (unsigned int i = 0; i < this->playerScoreRecords->size(); i++){
        PlayerScoreRecord* record =  this->playerScoreRecords->at(i);
        if (record->getPlayerID() == playerID){
        delete record;
            this->playerScoreRecords->erase(this->playerScoreRecords->begin()+i);
        }
    }
}

/**
 * @brief ScoreTracker::removeGroupScoreRecord
 * @param groupID
 */
void ScoreTracker::removeGroupScoreRecord(ID* groupID){

    for (unsigned int i = 0; i < this->groupScoreRecords->size(); i++){
        GroupScoreRecord* record =  this->groupScoreRecords->at(i);
        if (record->getGroupID() == groupID)
           delete record;
        this->groupScoreRecords->erase(this->groupScoreRecords->begin()+i);
    }
}

/**
 * @brief ScoreTracker::removeAllPlayerScoreRecords
 */
void ScoreTracker::removeAllPlayerScoreRecords(){

    for (unsigned int i = 0; i < this->playerScoreRecords->size(); i++)
        delete this->playerScoreRecords->at(i);

    this->playerScoreRecords->clear();
}

/**
 * @brief ScoreTracker::removeAllGroupScoreRecords
 */
void ScoreTracker::removeAllGroupScoreRecords(){

    for (unsigned int i = 0; i < this->groupScoreRecords->size(); i++)
        delete this->groupScoreRecords->at(i);

    this->groupScoreRecords->clear();
}

/**
 * @brief ScoreTracker::removeWinners
 */
void ScoreTracker::removeWinners(){

    this->winners->clear();
}

/**
 * @brief ScoreTracker::removeWinningGroups
 */
void ScoreTracker::removeWinningGroups(){

    this->winningGroups->clear();
}
