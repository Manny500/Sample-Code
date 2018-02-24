#ifndef TIMETRACKER_H
#define TIMETRACKER_H

//Project
#include "Accessible.h"


/**
 * @brief The TimeTracker class
 */
class TimeTracker : public Accessible{


public:

    unsigned int time;
    unsigned int stage;
    unsigned int round;
    unsigned int turn;
    unsigned int move;
    unsigned int roundPerStage;
    unsigned int turnPerRound;
    unsigned int movePerTurn;

    TimeTracker();
    TimeTracker(int roundPerStage, int turnPerRound, int movePerTurn);
    ~TimeTracker();

    void incrementTime();
    void incrementMove();
    void incrementTurn();
    void incrementRound();
    void incrementStage();


};

#endif // TIMETRACKER_H
