#include "PlayerScoreRecord.h"

/**
 * @brief PlayerScoreRecord::PlayerScoreRecord
 */
PlayerScoreRecord::PlayerScoreRecord(){

    this->score = 0.0;
    this->altScore1 = 0;
    this->altScore2 = 0;
}

/**
 * @brief PlayerScoreRecord::PlayerScoreRecord
 * @param playerID
 */
PlayerScoreRecord::PlayerScoreRecord(ID* playerID){

    this->playerID =  playerID;
    this->score = 0.0;
    this->altScore1 = 0;
    this->altScore2 = 0;
}

/**
 * @brief PlayerScoreRecord::PlayerScoreRecord
 * @param playerID
 * @param score
 */
PlayerScoreRecord::PlayerScoreRecord(ID* playerID, double score){

    this->playerID =  playerID;
    this->score = score;
    this->altScore1 = 0;
    this->altScore2 = 0;
}

/**
 * @brief PlayerScoreRecord::PlayerScoreRecord
 * @param playerID
 * @param altScore1
 */
PlayerScoreRecord::PlayerScoreRecord(ID* playerID, int altScore1){

    this->playerID =  playerID;
    this->score = 0.0;
    this->altScore1 = altScore1;
    this->altScore2 = 0;
}

/**
 * @brief PlayerScoreRecord::PlayerScoreRecord
 * @param playerID
 * @param altScore1
 * @param altScore2
 */
PlayerScoreRecord::PlayerScoreRecord(ID* playerID, int altScore1, int altScore2){

    this->playerID =  playerID;
    this->score = 0.0;
    this->altScore1 = altScore1;
    this->altScore2 = altScore2;
}

/**
 * @brief PlayerScoreRecord::PlayerScoreRecord
 * @param playerID
 * @param score
 * @param altScore1
 * @param altScore2
 */
PlayerScoreRecord::PlayerScoreRecord(ID* playerID, double score, int altScore1, int altScore2){

    this->playerID =  playerID;
    this->score = score;
    this->altScore1 = altScore1;
    this->altScore2 = altScore2;
}

/**
 * @brief PlayerScoreRecord::~PlayerScoreRecord
 */
PlayerScoreRecord::~PlayerScoreRecord(){

    this->playerID = NULL;
}

/**
 * @brief PlayerScoreRecord::setPlayerID
 * @param playerID
 */
void PlayerScoreRecord::setPlayerID(ID* playerID){

    this->playerID =  playerID;
}

/**
 * @brief PlayerScoreRecord::setScore
 * @param score
 */
void PlayerScoreRecord::setScore(double score){

    this->score = score;
}

/**
 * @brief PlayerScoreRecord::setAltScore1
 * @param altScore1
 */
void PlayerScoreRecord::setAltScore1(int altScore1){

    this->altScore1 = altScore1;
}

/**
 * @brief PlayerScoreRecord::setAltScore2
 * @param altScore2
 */
void PlayerScoreRecord::setAltScore2(int altScore2){

    this->altScore2 = altScore2;
}

/**
 * @brief PlayerScoreRecord::addToScore
 * @param update
 */
void PlayerScoreRecord::addToScore(double update){

    this->score += update;
}

/**
 * @brief PlayerScoreRecord::addToAltScore1
 * @param update
 */
void PlayerScoreRecord::addToAltScore1(int update){

    this->altScore1 += update;
}

/**
 * @brief PlayerScoreRecord::addToAltScore2
 * @param update
 */
void PlayerScoreRecord::addToAltScore2(int update){

    this->altScore2 += update;
}

/**
 * @brief PlayerScoreRecord::getPlayerID
 * @return
 */
ID* PlayerScoreRecord::getPlayerID(){

    return this->playerID;
}

/**
 * @brief PlayerScoreRecord::getScore
 * @return
 */
double PlayerScoreRecord::getScore(){

    return this->score;
}

/**
 * @brief PlayerScoreRecord::getAltScore1
 * @return
 */
int PlayerScoreRecord::getAltScore1(){

    return this->altScore1;
}

/**
 * @brief PlayerScoreRecord::getAltScore2
 * @return
 */
int PlayerScoreRecord::getAltScore2(){

    return this->altScore2;
}
