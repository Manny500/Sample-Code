#include "Tradable.h"

/**
 * @brief Tradable::Tradable
 */
Tradable::Tradable(){

    this->historyOwnerIDs =  new std::vector<ID*>;
}

/**
 * @brief Tradable::~Tradable
 */
Tradable::~Tradable(){

    removeAllHistoryOwnerIDs();

    delete this->historyOwnerIDs;
    this->historyOwnerIDs = NULL;
}

/**
 * @brief Tradable::setNextOwnerID
 * @param id
 */
void Tradable::setNextOwnerID(ID* id){

    this->nextOwnerID = id;
}

/**
 * @brief Tradable::setAllHistoryOwnerIDs
 * @param historyOwnerIDs
 */
void Tradable::setAllHistoryOwnerIDs(std::vector<ID*>* historyOwnerIDs){

    this->historyOwnerIDs = historyOwnerIDs;
}

/**
 * @brief Tradable::addRecentOwnerID
 * @param id
 */
void Tradable::addRecentOwnerID(ID* id){

    this->historyOwnerIDs->push_back(id);
}

/**
 * @brief Tradable::getNextOwnerID
 * @return
 */
ID* Tradable::getNextOwnerID(){

    return this->nextOwnerID;
}

/**
 * @brief Tradable::getHistoryOwnerIDCount
 * @return
 */
unsigned int Tradable::getHistoryOwnerIDCount(){

    return this->historyOwnerIDs->size();
}

/**
 * @brief Tradable::getAllHistoryOwnerIDs
 * @return
 */
std::vector<ID*>* Tradable::getAllHistoryOwnerIDs(){

    return this->historyOwnerIDs;
}

/**
 * @brief Tradable::getRecentOwnerID
 * @param stepsBack
 * @return
 */
ID* Tradable::getRecentOwnerID(unsigned int stepsBack){

    if (stepsBack < this->historyOwnerIDs->size())
        return this->historyOwnerIDs->at(this->historyOwnerIDs->size() - 1 - stepsBack);
    else
        return this->historyOwnerIDs->front();
}

/**
 * @brief Tradable::getRecentOwnerIDsBetween
 * @param stepsBack
 * @param moreStepsBack
 * @return
 */
std::vector<ID*>* Tradable::getRecentOwnerIDsBetween(unsigned int stepsBack, unsigned int moreStepsBack){

    std::vector<ID*>* recentOwnerIDs = new std::vector<ID*>;
    unsigned int latest = this->historyOwnerIDs->size() - 1 - stepsBack;
    unsigned int earliest = this->historyOwnerIDs->size() - 1 - moreStepsBack;

    for (unsigned int i = latest; i >= earliest; i--)
        recentOwnerIDs->push_back(this->historyOwnerIDs->at(i));

    return recentOwnerIDs;
}

/**
 * @brief Tradable::removeRecentOwnerIDsBetween
 * @param stepsBack
 * @param moreStepsBack
 */
void Tradable::removeRecentOwnerIDsBetween(unsigned int stepsBack, unsigned int moreStepsBack){

    unsigned int latest = this->historyOwnerIDs->size() - 1 - stepsBack;
    unsigned int earliest = this->historyOwnerIDs->size() - 1 - moreStepsBack;

    this->historyOwnerIDs->erase(this->historyOwnerIDs->begin() + earliest, this->historyOwnerIDs->begin() + latest + 1);
}

/**
 * @brief Tradable::removeAllHistoryOwnerIDs
 */
void Tradable::removeAllHistoryOwnerIDs(){

    this->historyOwnerIDs->clear();
}
