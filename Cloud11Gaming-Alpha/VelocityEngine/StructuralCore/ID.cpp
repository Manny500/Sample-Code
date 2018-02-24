#include "ID.h"

/**
 * @brief ID::ID
 */
ID::ID(){

    this->serialID = 0;
    this->assignedID = 0;
}

/**
 * @brief ID::ID
 * @param serialID
 */
ID::ID(unsigned int serialID){

    this->serialID = serialID;
    this->assignedID = 0;
}

/**
 * @brief ID::ID
 * @param serialID
 * @param assignedID
 */
ID::ID(unsigned int serialID, int assignedID){

    this->serialID = serialID;
    this->assignedID = assignedID;
}

/**
 * @brief ID::~ID
 */
ID::~ID(){}

/**
 * @brief ID::setSerialID
 * @param serialID
 */
void ID::setSerialID(unsigned int serialID){

    this->serialID = serialID;
}

/**
 * @brief ID::setAssignedID
 * @param assignedID
 */
void ID::setAssignedID(int assignedID){

    this->assignedID = assignedID;
}

/**
 * @brief ID::getSerialID
 * @return
 */
unsigned int ID::getSerialID(){

    return this->serialID;
}

/**
 * @brief ID::getAssignedID
 * @return
 */
int ID::getAssignedID(){

    return this->assignedID;
}
