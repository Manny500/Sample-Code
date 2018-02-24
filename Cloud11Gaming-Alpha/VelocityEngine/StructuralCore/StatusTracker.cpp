#include "StatusTracker.h"

/**
 * @brief StatusTracker::StatusTracker
 */
StatusTracker::StatusTracker(){

    this->connecting = 0;
    this->connected = 0;
    this->disconnected = 1;
    this->addingPlayer = 0;
    this->addingComplete = 0;
    this->loading = 0;
    this->started = 0;
    this->paused = 0;
    this->waiting = 0;
    this->communicating = 0;
    this->toNextStage = 0;
    this->toNextRound = 0;
    this->toNextTurn = 0;
    this->toNextMove = 0;
    this->victoryMode1 = 0;
    this->victoryMode2 = 0;
    this->victoryMode3 = 0;
    this->draw = 0;
    this->ended = 0;
    this->extraStatuses = new AttributeList();
}

/**
 * @brief StatusTracker::~StatusTracker
 */
StatusTracker::~StatusTracker(){

    this->removeExtraStatuses();

    delete extraStatuses;

    this->extraStatuses = NULL;
}

/**
 * @brief StatusTracker::setExtraStatuses
 * @param attributeList
 */
void StatusTracker::setExtraStatuses(AttributeList* attributeList){

    delete this->extraStatuses;
    this->extraStatuses = attributeList;
}

/**
 * @brief StatusTracker::getExtraStatuses
 * @return
 */
AttributeList* StatusTracker::getExtraStatuses(){

    return this->extraStatuses;
}

/**
 * @brief StatusTracker::removeExtraStatuses
 */
void StatusTracker::removeExtraStatuses(){

    this->extraStatuses->removeAllAttributes();
}

