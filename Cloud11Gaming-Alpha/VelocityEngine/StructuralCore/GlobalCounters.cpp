#include "GlobalCounters.h"

/**
 * @brief GlobalCounters::GlobalCounters
 */
GlobalCounters::GlobalCounters(){

    this->typeCreatedCount = 0;
    this->playerCreatedCount = 0;
    this->componentCreatedCount = 0;
}

/**
 * @brief GlobalCounters::~GlobalCounters
 */
GlobalCounters::~GlobalCounters(){}

/**
 * @brief GlobalCounters::incrementTypeCount
 */
void GlobalCounters::incrementTypeCount(){

    this->typeCreatedCount ++;
}

/**
 * @brief GlobalCounters::incrementPlayerCount
 */
void GlobalCounters::incrementPlayerCount(){

    this->playerCreatedCount ++;
}

/**
 * @brief GlobalCounters::incrementComponentCount
 */
void GlobalCounters::incrementComponentCount(){

    this->componentCreatedCount ++;
}
