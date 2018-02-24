#ifndef PROGRESSCONTROL_H
#define PROGRESSCONTROL_H

//Project
#include "TimeTracker.h"
#include "ScoreTracker.h"
#include "StatusTracker.h"
#include "GlobalCounters.h"


class ProgressControl : public Accessible{


public:

    TimeTracker* timeTracker;
    ScoreTracker* scoreTracker;
    StatusTracker* statusTracker;
    GlobalCounters* globalCounters;

    ProgressControl();
    ~ProgressControl();


};

#endif // PROGRESSCONTROL_H
