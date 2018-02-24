#ifndef GLOBALCOUNTERS_H
#define GLOBALCOUNTERS_H

//Project
#include "Accessible.h"


/**
 * @brief The GlobalCounters class
 */
class GlobalCounters : public Accessible{


public:

    unsigned int typeCreatedCount;
    unsigned int playerCreatedCount;
    unsigned int componentCreatedCount;

    GlobalCounters();
    ~GlobalCounters();

    void incrementTypeCount();
    void incrementPlayerCount();
    void incrementComponentCount();


};

#endif // GLOBALCOUNTERS_H
