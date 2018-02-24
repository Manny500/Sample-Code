#include "AccessOverride.h"

/**
 * @brief AccessOverride::AccessOverride
 */
AccessOverride::AccessOverride(){

    this->extraAccesses = new std::vector<Accessible*>;
}


AccessOverride::~AccessOverride(){

    removeAllExtraAccesses();

    delete this->extraAccesses;

    this->playerAccess = NULL;
    this->playerGroupAccess = NULL;
    this->componentAccess = NULL;
    this->locationAccess = NULL;
    this->componentStackAccess = NULL;
    this->access1 = NULL;
    this->access2 = NULL;
    this->access3 = NULL;
    this->access4 = NULL;
    this->extraAccesses = NULL;
}

/**
 * @brief AccessOverride::getExtraAccess will get the left over capacity in acess
 * @param index is the index to look for space
 * @return will return an accessable variable
 */
Accessible* AccessOverride::getExtraAccess(unsigned int index){

    return this->extraAccesses->at(index);
}

/**
 * @brief AccessOverride::addExtraAccess will add extra space
 * @param accessible is the space to be added
 * @return will return the size of the new space
 */
unsigned int AccessOverride::addExtraAccess(Accessible* accessible){

    this->extraAccesses->push_back(accessible);

    return this->extraAccesses->size()-1;
}

/**
 * @brief AccessOverride::removeExtraAccessAt will remove any extra spaces
 * @param index the space to be removed
 */
void AccessOverride::removeExtraAccessAt(unsigned int index){

    this->extraAccesses->at(index) = this->extraAccesses->at(this->extraAccesses->size() - 1);

    this->extraAccesses->pop_back();
}

/**
 * @brief AccessOverride::removeAllExtraAccesses will remove all extra spaceses
 */
void AccessOverride::removeAllExtraAccesses(){

    this->extraAccesses->clear();
}

