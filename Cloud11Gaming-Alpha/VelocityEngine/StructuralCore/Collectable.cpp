#include "Collectable.h"

/**
 * @brief Collectable::Collectable
 */
Collectable::Collectable(){}

/**
 * @brief Collectable::~Collectable
 */
Collectable::~Collectable(){

    this->ownerID = NULL;
}

/**
 * @brief Collectable::setOwnerID
 * @param ownerID
 */
void Collectable::setOwnerID(ID* ownerID){

    this->ownerID = ownerID;
}

/**
 * @brief Collectable::getOwnerID
 * @return
 */
ID* Collectable::getOwnerID(){

    return this->ownerID;
}

/**
 * @brief Collectable::getOwnerSerialID
 * @return
 */
unsigned int Collectable::getOwnerSerialID(){

    return this->ownerID->getSerialID();
}

/**
 * @brief Collectable::getOwnerAssignedID
 * @return
 */
int Collectable::getOwnerAssignedID(){

    return this->ownerID->getAssignedID();
}
