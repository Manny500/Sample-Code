#include "PhysicalSpaceManager.h"

/**
 * @brief PhysicalSpaceManager::PhysicalSpaceManager
 */
PhysicalSpaceManager::PhysicalSpaceManager(){

    this->physicalSpaces = new std::vector<PhysicalSpace*>;
}

/**
 * @brief PhysicalSpaceManager::~PhysicalSpaceManager
 */
PhysicalSpaceManager::~PhysicalSpaceManager(){

    removeAllPhysicalSpaces();
    delete this->physicalSpaces;
    this->physicalSpaces = NULL;
}

/**
 * @brief PhysicalSpaceManager::addPhysicalSpace
 * @param physicalSpace
 */
void PhysicalSpaceManager::addPhysicalSpace(PhysicalSpace* physicalSpace){

    this->physicalSpaces->push_back(physicalSpace);
}

/**
 * @brief PhysicalSpaceManager::getPhysicalSpaceAt
 * @param index
 * @return
 */
PhysicalSpace* PhysicalSpaceManager::getPhysicalSpaceAt(unsigned int index){

    return this->physicalSpaces->at(index);
}

/**
 * @brief PhysicalSpaceManager::getPhysicalSpace
 * @param label
 * @return
 */
PhysicalSpace* PhysicalSpaceManager::getPhysicalSpace(int label){

    PhysicalSpace* ps;

    for (unsigned int i = 0; i < this->physicalSpaces->size(); i++){
        ps = this->physicalSpaces->at(i);
        if (ps->getLabel() == label)
            return ps;
    }

    return NULL;
}

/**
 * @brief PhysicalSpaceManager::getPhysicalSpace
 * @param name
 * @return
 */
PhysicalSpace* PhysicalSpaceManager::getPhysicalSpace(std::string name){

    PhysicalSpace* ps;

    for (unsigned int i = 0; i < this->physicalSpaces->size(); i++){
        ps = this->physicalSpaces->at(i);
        if (ps->getName() == name)
            return ps;
    }

    return NULL;
}

/**
 * @brief PhysicalSpaceManager::removePhysicalSpaceAt
 * @param index
 */
void PhysicalSpaceManager::removePhysicalSpaceAt(unsigned int index){

    delete this->physicalSpaces->at(index);
    this->physicalSpaces->erase(this->physicalSpaces->begin()+index);
}

/**
 * @brief PhysicalSpaceManager::removePhysicalSpace
 * @param label
 */
void PhysicalSpaceManager::removePhysicalSpace(int label){

    PhysicalSpace* ps;

    for (unsigned int i = 0; i < this->physicalSpaces->size(); i++){
        ps = this->physicalSpaces->at(i);
        if (ps->getLabel() == label){
            delete ps;
            this->physicalSpaces->erase(this->physicalSpaces->begin()+i);
        }
    }

    ps = NULL;
}

/**
 * @brief PhysicalSpaceManager::removePhysicalSpace
 * @param name
 */
void PhysicalSpaceManager::removePhysicalSpace(std::string name){

    PhysicalSpace* ps;

    for (unsigned int i = 0; i < this->physicalSpaces->size(); i++){
        ps = this->physicalSpaces->at(i);
        if (ps->getName() == name){
            delete ps;
            this->physicalSpaces->erase(this->physicalSpaces->begin()+i);
        }
    }

    ps = NULL;
}

/**
 * @brief PhysicalSpaceManager::removeAllPhysicalSpaces
 */
void PhysicalSpaceManager::removeAllPhysicalSpaces(){

    for (unsigned int i = 0; i < this->physicalSpaces->size(); i++)
        delete this->physicalSpaces->at(i);

    this->physicalSpaces->clear();
}
