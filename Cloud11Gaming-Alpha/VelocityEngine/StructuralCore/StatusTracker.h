#ifndef STATUSTRACKER_H
#define STATUSTRACKER_H

//Project
#include "Accessible.h"
#include "AttributeList.h"


/**
 * @brief The StatusTracker class
 */
class StatusTracker : public Accessible{


public:

    int connecting;
    int connected;
    int disconnected;
    int addingPlayer;
    int addingComplete;
    int loading;
    int started;
    int paused;
    int waiting;
    int communicating;
    int toNextStage;
    int toNextRound;
    int toNextTurn;
    int toNextMove;
    int victoryMode1;
    int victoryMode2;
    int victoryMode3;
    int draw;
    int ended;
    AttributeList* extraStatuses;

    StatusTracker();
    ~StatusTracker();

    void setExtraStatuses(AttributeList* attributeList);

    AttributeList* getExtraStatuses();

    void removeExtraStatuses();


};

#endif // STATUSTRACKER_H
