#include "TimeTracker.h"

/**
 * @brief TimeTracker::TimeTracker
 */
TimeTracker::TimeTracker(){

    this->time = 0;
    this->stage = 0;
    this->round = 0;
    this->turn = 0;
    this->move = 0;
    this->roundPerStage = -1;
    this->turnPerRound = -1;
    this->movePerTurn = -1;
}

/**
 * @brief TimeTracker::TimeTracker
 * @param roundPerStage
 * @param turnPerRound
 * @param movePerTurn
 */
TimeTracker::TimeTracker(int roundPerStage, int turnPerRound, int movePerTurn){

    this->time = 0;
    this->stage = 0;
    this->round = 0;
    this->turn = 0;
    this->move = 0;
    this->roundPerStage = roundPerStage;
    this->turnPerRound = turnPerRound;
    this->movePerTurn = movePerTurn;
}

/**
 * @brief TimeTracker::~TimeTracker
 */
TimeTracker::~TimeTracker(){}

/**
 * @brief TimeTracker::incrementTime
 */
void TimeTracker::incrementTime(){

    this->time ++;
}

/**
 * @brief TimeTracker::incrementStage
 */
void TimeTracker::incrementStage(){

    this->stage ++;
}

/**
 * @brief TimeTracker::incrementRound
 */
void TimeTracker::incrementRound(){

    this->round ++;

    if (this->round == this->roundPerStage)
        this->round = 0;
}

/**
 * @brief TimeTracker::incrementTurn
 */
void TimeTracker::incrementTurn(){

    this->turn ++;

    if (this->turn == this->turnPerRound)
        this->turn = 0;
}

/**
 * @brief TimeTracker::incrementMove
 */
void TimeTracker::incrementMove(){

    this->move ++;

if (this->move == this->movePerTurn)
    this->move = 0;
}



