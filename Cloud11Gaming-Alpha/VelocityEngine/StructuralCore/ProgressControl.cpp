#include "ProgressControl.h"

/**
 * @brief ProgressControl::ProgressControl
 */
ProgressControl::ProgressControl(){

    this->timeTracker = new TimeTracker();
    this->scoreTracker = new ScoreTracker();
    this->statusTracker = new StatusTracker();
    this->globalCounters = new GlobalCounters();
}

/**
 * @brief ProgressControl::~ProgressControl
 */
ProgressControl::~ProgressControl(){

    delete this->timeTracker;
    delete this->scoreTracker;
    delete this->statusTracker;
    delete this->globalCounters;


    this->timeTracker = NULL;
    this->scoreTracker = NULL;
    this->statusTracker = NULL;
    this->globalCounters = NULL;
}
