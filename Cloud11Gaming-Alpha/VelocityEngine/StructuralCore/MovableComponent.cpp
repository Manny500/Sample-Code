#include "MovableComponent.h"

/**
 * @brief MovableComponent::MovableComponent
 */
MovableComponent::MovableComponent(){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::MovableComponent
 * @param id
 */
MovableComponent::MovableComponent(ID* id)
    : LocatableComponent(id){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::MovableComponent
 * @param serialID
 */
MovableComponent::MovableComponent(unsigned int serialID)
    : LocatableComponent(serialID){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::MovableComponent
 * @param serialID
 * @param assignedID
 */
MovableComponent::MovableComponent(unsigned int serialID, int assignedID)
    : LocatableComponent(serialID, assignedID){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::MovableComponent
 * @param type
 */
MovableComponent::MovableComponent(Type* type)
    : LocatableComponent(type){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::MovableComponent
 * @param id
 * @param type
 */
MovableComponent::MovableComponent(ID* id, Type* type)
    : LocatableComponent(id, type){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::MovableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
MovableComponent::MovableComponent(unsigned int serialID, int assignedID, Type* type)
    :LocatableComponent(serialID, assignedID, type){

    this->historyCoordinates = new std::vector<Coordinates*>;
}

/**
 * @brief MovableComponent::~MovableComponent
 */
MovableComponent::~MovableComponent(){

    removeAllHistoryCoordinates();

    delete this->historyCoordinates;

    this->nextCoordinates = NULL;
    this->historyCoordinates = NULL;
}

/**
 * @brief MovableComponent::setNextCoordinates
 * @param nextCoordinates
 */
void MovableComponent::setNextCoordinates(Coordinates* nextCoordinates){

    this->nextCoordinates = nextCoordinates;
}

/**
 * @brief MovableComponent::setAllHistoryCoordinates
 * @param historyCoordinates
 */
void MovableComponent::setAllHistoryCoordinates(std::vector<Coordinates*>* historyCoordinates){

    this->historyCoordinates = historyCoordinates;
}

/**
 * @brief MovableComponent::addRecentCoordinates
 * @param coordinates
 */
void MovableComponent::addRecentCoordinates(Coordinates* coordinates){

    this->historyCoordinates->push_back(coordinates);
}

/**
 * @brief MovableComponent::getNextCoordinates
 * @return
 */
Coordinates* MovableComponent::getNextCoordinates(){

    return this->nextCoordinates;
}

/**
 * @brief MovableComponent::getHistoryCoordinatesCount
 * @return
 */
unsigned int MovableComponent::getHistoryCoordinatesCount(){

    return this->historyCoordinates->size();
}

/**
 * @brief MovableComponent::getAllHistoryCoordinates
 * @return
 */
std::vector<Coordinates*>* MovableComponent::getAllHistoryCoordinates(){

    return this->historyCoordinates;
}

/**
 * @brief MovableComponent::getRecentCoordinates
 * @param stepsBack
 * @return
 */
Coordinates* MovableComponent::getRecentCoordinates(unsigned int stepsBack){

    if (stepsBack < this->historyCoordinates->size())
        return this->historyCoordinates->at(this->historyCoordinates->size() - 1 - stepsBack);
    else
        return this->historyCoordinates->front();
}

/**
 * @brief MovableComponent::getRecentCoordinatesBetween
 * @param stepsBack
 * @param moreStepsBack
 * @return
 */
std::vector<Coordinates*>* MovableComponent::getRecentCoordinatesBetween(unsigned int stepsBack, unsigned int moreStepsBack){

    std::vector<Coordinates*>* recentCoordinates = new std::vector<Coordinates*>;
    unsigned int latest = this->historyCoordinates->size() - 1 - stepsBack;
    unsigned int earliest = this->historyCoordinates->size() - 1 - moreStepsBack;

    for (unsigned int i = latest; i >= earliest; i--)
        recentCoordinates->push_back(this->historyCoordinates->at(i));

    return recentCoordinates;
}

/**
 * @brief MovableComponent::removeRecentCoordinatesBetween
 * @param stepsBack
 * @param moreStepsBack
 */
void MovableComponent::removeRecentCoordinatesBetween(unsigned int stepsBack, unsigned int moreStepsBack){


    unsigned int latest = this->historyCoordinates->size() - 1 - stepsBack;
    unsigned int earliest = this->historyCoordinates->size() - 1 - moreStepsBack;

    this->historyCoordinates->erase(this->historyCoordinates->begin() + earliest, this->historyCoordinates->begin() + latest + 1);
}

/**
 * @brief MovableComponent::removeAllHistoryCoordinates
 */
void MovableComponent::removeAllHistoryCoordinates(){

    this->historyCoordinates->clear();
}
