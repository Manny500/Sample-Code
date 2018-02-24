#include "Location.h"

/**
 * @brief Location::Location
 * @param x
 * @param y
 * @param z
 * @param s
 */
Location::Location(int x, int y, int z, int s){

    this->coordinates = new Coordinates(x, y, z, s);
    this->attributeList = new AttributeList();
    this->locatableComponents = new std::vector<LocatableComponent*>;
}

/**
 * @brief Location::Location
 * @param x
 * @param y
 * @param z
 * @param s
 * @param type
 */
Location::Location(int x, int y, int z, int s, Type* type){

    this->coordinates = new Coordinates(x, y, z, s);
    this->type = type;
    this->attributeList = new AttributeList();
    this->locatableComponents = new std::vector<LocatableComponent*>;
}

/**
 * @brief Location::~Location
 */
Location::~Location(){

    removeAttributeList();
    removeAllLocatableComponents();

    delete this->coordinates;
    delete this->attributeList;
    delete this->locatableComponents;

    this->coordinates = NULL;
    this->type = NULL;
    this->attributeList = NULL;
    this->locatableComponents = NULL;
}

/**
 * @brief Location::setCoordinates
 * @param x
 * @param y
 * @param z
 * @param s
 */
void Location::setCoordinates(int x, int y, int z, int s){

    this->coordinates->setX(x);
    this->coordinates->setY(y);
    this->coordinates->setZ(z);
    this->coordinates->setS(s);
}

/**
 * @brief Location::setType
 * @param type
 */
void Location::setType(Type* type){

    this->type = type;
}

/**
 * @brief Location::setAttributeList
 * @param attributeList
 */
void Location::setAttributeList(AttributeList* attributeList){

    this->attributeList = attributeList;
}

/**
 * @brief Location::setAllLocatableComponents
 * @param locatableComponents
 */
void Location::setAllLocatableComponents(std::vector<LocatableComponent*>* locatableComponents){

    this->locatableComponents = locatableComponents;
}

/**
 * @brief Location::addLocatableComponent
 * @param locatableComponent
 */
void Location::addLocatableComponent(LocatableComponent* locatableComponent){

    locatableComponent->setCoordinates(this->coordinates);
    this->locatableComponents->push_back(locatableComponent);
}

/**
 * @brief Location::getCoordinates
 * @return
 */
Coordinates* Location::getCoordinates(){

    return this->coordinates;
}

/**
 * @brief Location::getType
 * @return
 */
Type* Location::getType(){

    return this->type;
}

/**
 * @brief Location::getAttributeList
 * @return
 */
AttributeList* Location::getAttributeList(){

    return this->attributeList;
}

/**
 * @brief Location::getLocatableComponentCount
 * @return
 */
unsigned int Location::getLocatableComponentCount(){

    return this->locatableComponents->size();
}

/**
 * @brief Location::getAllLocatableComponents
 * @return
 */
std::vector<LocatableComponent*>* Location::getAllLocatableComponents(){

    return this->locatableComponents;
}

/**
 * @brief Location::getLocatableComponentAt
 * @param index
 * @return
 */
LocatableComponent* Location::getLocatableComponentAt(unsigned int index){

    return this->locatableComponents->at(index);
}

/**
 * @brief Location::getLocatableComponentOfSerialID
 * @param serialID
 * @return
 */
LocatableComponent* Location::getLocatableComponentOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getID()->getSerialID() == serialID)
            return cmpt;
    }

    return NULL;
}

/**
 * @brief Location::getLocatableComponentOfAssignedID
 * @param assignedID
 * @return
 */
LocatableComponent* Location::getLocatableComponentOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getID()->getAssignedID() == assignedID)
            return cmpt;
    }

    return NULL;
}

/**
 * @brief Location::getLocatableComponentsOfType
 * @param type
 * @return
 */
std::vector<LocatableComponent*>* Location::getLocatableComponentsOfType(Type* type){

    std::vector<LocatableComponent*>* componentsOfType = new std::vector<LocatableComponent*>;

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getType() == type)
            componentsOfType->push_back(cmpt);
    }

    return componentsOfType;
}

/**
 * @brief Location::getLocatableComponentFromTop
 * @return
 */
LocatableComponent* Location::getLocatableComponentFromTop(){

    return this->locatableComponents->back();
}

/**
 * @brief Location::retrieveLocatableComponentAt
 * @param index
 * @return
 */
LocatableComponent* Location::retrieveLocatableComponentAt(unsigned int index){

    LocatableComponent* cmpt = this->locatableComponents->at(index);
    this->locatableComponents->erase(this->locatableComponents->begin()+index);
    return cmpt;
}

/**
 * @brief Location::retrieveLocatableComponentOfSerialID
 * @param serialID
 * @return
 */
LocatableComponent* Location::retrieveLocatableComponentOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getID()->getSerialID() == serialID){
            this->locatableComponents->erase(this->locatableComponents->begin()+i);
            return cmpt;
        }
    }

    return NULL;
}

/**
 * @brief Location::retrieveLocatableComponentOfAssignedID
 * @param assignedID
 * @return
 */
LocatableComponent* Location::retrieveLocatableComponentOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getID()->getAssignedID() == assignedID){
            this->locatableComponents->erase(this->locatableComponents->begin()+i);
            return cmpt;
        }
    }

    return NULL;
}

/**
 * @brief Location::retrieveLocatableComponentFromTop
 * @return
 */
LocatableComponent* Location::retrieveLocatableComponentFromTop(){

    LocatableComponent* cmpt = this->locatableComponents->back();
    this->locatableComponents->pop_back();
    return cmpt;
}

/**
 * @brief Location::isEmpty
 * @return
 */
bool Location::isEmpty(){

    if (this->locatableComponents->size() == 0) return true;
    else return false;
}

/**
 * @brief Location::removeAttributeList
 */
void Location::removeAttributeList(){

    this->attributeList->removeAllAttributes();
}

/**
 * @brief Location::removeDeactivated
 */
void Location::removeDeactivated(){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->isDeactivated()){
            this->locatableComponents->erase(this->locatableComponents->begin()+i);
            i --;
        }
    }
}

/**
 * @brief Location::removeLocatableComponentAt
 * @param index
 */
void Location::removeLocatableComponentAt(unsigned int index){

    this->locatableComponents->erase(this->locatableComponents->begin()+index);
}

/**
 * @brief Location::removeLocatableComponentOfSerialID
 * @param serialID
 */
void Location::removeLocatableComponentOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getID()->getSerialID() == serialID){
            this->locatableComponents->erase(this->locatableComponents->begin()+i);
            break;
        }
    }
}

/**
 * @brief Location::removeLocatableComponentOfAssignedID
 * @param assignedID
 */
void Location::removeLocatableComponentOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getID()->getAssignedID() == assignedID){
            this->locatableComponents->erase(this->locatableComponents->begin()+i);
        }
    }
}

/**
 * @brief Location::removeLocatableComponentsOfType
 * @param type
 */
void Location::removeLocatableComponentsOfType(Type* type){

    for (unsigned int i = 0; i < this->locatableComponents->size(); i++){
        LocatableComponent* cmpt =  this->locatableComponents->at(i);
        if (cmpt->getType() == type){
            this->locatableComponents->erase(this->locatableComponents->begin()+i);
            i --;
        }
    }

}

/**
 * @brief Location::removeAllLocatableComponents
 */
void Location::removeAllLocatableComponents(){

    this->locatableComponents->clear();
}
