#ifndef TRADABLE_H
#define TRADABLE_H

//General
#include <vector>

//Project
#include "Collectable.h"


class Tradable: public Collectable{


protected:

    ID* nextOwnerID;
    std::vector<ID*>* historyOwnerIDs;

    Tradable();
    ~Tradable();


public:

    void setNextOwnerID(ID* id);
    void setAllHistoryOwnerIDs(std::vector<ID*>* historyOwnerIDs);
    void addRecentOwnerID(ID* id);

    ID* getNextOwnerID();
    unsigned int getHistoryOwnerIDCount();
    std::vector<ID*>* getAllHistoryOwnerIDs();
    ID* getRecentOwnerID(unsigned int stepsBack);
    std::vector<ID*>* getRecentOwnerIDsBetween(unsigned int stepsBack, unsigned int moreStepsBack);

    void removeRecentOwnerIDsBetween(unsigned int stepsBack, unsigned int moreStepsBack);
    void removeAllHistoryOwnerIDs();


};

#endif // TRADABLE_H
