#include "GroupScoreRecord.h"

/**
 * @brief GroupScoreRecord::GroupScoreRecord
 */
GroupScoreRecord::GroupScoreRecord(){

    this->score = 0.0;
    this->altScore1 = 0;
    this->altScore2 = 0;
}

/**
 * @brief GroupScoreRecord::GroupScoreRecord
 * @param groupID
 */
GroupScoreRecord::GroupScoreRecord(ID* groupID){

    this->groupID = groupID;
    this->score = 0.0;
    this->altScore1 = 0;
    this->altScore2 = 0;
}

/**
 * @brief GroupScoreRecord::GroupScoreRecord
 * @param groupID
 * @param score
 */
GroupScoreRecord::GroupScoreRecord(ID* groupID, double score){

    this->groupID = groupID;
    this->score = score;
    this->altScore1 = 0;
    this->altScore2 = 0;
}

/**
 * @brief GroupScoreRecord::GroupScoreRecord
 * @param groupID
 * @param altScore1
 */
GroupScoreRecord::GroupScoreRecord(ID* groupID, int altScore1){

    this->groupID = groupID;
    this->score = 0.0;
    this->altScore1 = altScore1;
    this->altScore2 = 0;
}

/**
 * @brief GroupScoreRecord::GroupScoreRecord
 * @param groupID
 * @param altScore1
 * @param altScore2
 */
GroupScoreRecord::GroupScoreRecord(ID* groupID, int altScore1, int altScore2){

    this->groupID = groupID;
    this->score = 0.0;
    this->altScore1 = altScore1;
    this->altScore2 = altScore2;
}

/**
 * @brief GroupScoreRecord::GroupScoreRecord
 * @param groupID
 * @param score
 * @param altScore1
 * @param altScore2
 */
GroupScoreRecord::GroupScoreRecord(ID* groupID, double score, int altScore1, int altScore2){

    this->groupID = groupID;
    this->score = score;
    this->altScore1 = altScore1;
    this->altScore2 = altScore2;
}

/**
 * @brief GroupScoreRecord::~GroupScoreRecord
 */
GroupScoreRecord::~GroupScoreRecord(){

    this->groupID = NULL;
}

/**
 * @brief GroupScoreRecord::setGroupID
 * @param groupID
 */
void GroupScoreRecord::setGroupID(ID* groupID){

    this->groupID = groupID;
}

/**
 * @brief GroupScoreRecord::setScore
 * @param score
 */
void GroupScoreRecord::setScore(double score){

    this->score = score;
}

/**
 * @brief GroupScoreRecord::setAltScore1
 * @param altScore1
 */
void GroupScoreRecord::setAltScore1(int altScore1){

    this->altScore1 = altScore1;
}

/**
 * @brief GroupScoreRecord::setAltScore2
 * @param altScore2
 */
void GroupScoreRecord::setAltScore2(int altScore2){

    this->altScore2 = altScore2;
}

/**
 * @brief GroupScoreRecord::addToScore
 * @param update
 */
void GroupScoreRecord::addToScore(double update){

    this->score += update;
}

/**
 * @brief GroupScoreRecord::addToAltScore1
 * @param update
 */
void GroupScoreRecord::addToAltScore1(int update){

    this->altScore1 += update;
}

/**
 * @brief GroupScoreRecord::addToAltScore2
 * @param update
 */
void GroupScoreRecord::addToAltScore2(int update){

    this->altScore2 += update;
}

/**
 * @brief GroupScoreRecord::getGroupID
 * @return
 */
ID* GroupScoreRecord::getGroupID(){

    return this->groupID;
}

/**
 * @brief GroupScoreRecord::getScore
 * @return
 */
double GroupScoreRecord::getScore(){

    return this->score;
}

/**
 * @brief GroupScoreRecord::getAltScore1
 * @return
 */
int GroupScoreRecord::getAltScore1(){

    return this->altScore1;
}

/**
 * @brief GroupScoreRecord::getAltScore2
 * @return
 */
int GroupScoreRecord::getAltScore2(){

    return this->altScore2;
}

