#include "Component.h"

/**
 * @brief Component::Component
 */
Component::Component(){

    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::Component
 * @param id
 */
Component::Component(ID* id){

    this->id = id;
    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::Component
 * @param serialID
 */
Component::Component(unsigned int serialID){

    this->id = new ID(serialID);
    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::Component
 * @param serialID
 * @param assignedID
 */
Component::Component(unsigned int serialID, int assignedID){

    this->id = new ID(serialID, assignedID);
    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::Component
 * @param type
 */
Component::Component(Type* type){

    this->type = type;
    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::Component
 * @param id
 * @param type
 */
Component::Component(ID* id, Type* type){

    this->id = id;
    this->type = type;
    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::Component
 * @param serialID
 * @param assignedID
 * @param type
 */
Component::Component(unsigned int serialID, int assignedID, Type* type){

    this->id = new ID(serialID, assignedID);
    this->type = type;
    this->deactivated = 0;
    this->attributeList = new AttributeList();
}

/**
 * @brief Component::~Component
 */
Component::~Component(){

    this->attributeList->removeAllAttributes();

    delete this->attributeList;

    this->id = NULL;
    this->type = NULL;
    this->attributeList = NULL;
}

/**
 * @brief Component::setID
 * @param id
 */
void Component::setID(ID* id){

    delete this->id;
    this->id = id;
}

/**
 * @brief Component::setID
 * @param seriallID
 * @param assignedID
 */
void Component::setID(unsigned int seriallID, int assignedID){

    this->id->setSerialID(seriallID);
    this->id->setAssignedID(assignedID);
}

/**
 * @brief Component::setSerialID
 * @param seriallID
 */
void Component::setSerialID(unsigned int seriallID){

    this->id->setSerialID(seriallID);
}

/**
 * @brief Component::setAssignedID
 * @param assignedID
 */
void Component::setAssignedID(int assignedID){

    this->id->setAssignedID(assignedID);
}

/**
 * @brief Component::setType
 * @param type
 */
void Component::setType(Type* type){

    this->type = type;
}

/**
 * @brief Component::deactivate
 */
void Component::deactivate(){

    this->deactivated = 1;
}

/**
 * @brief Component::activate
 */
void Component::activate(){

    this->deactivated = 0;
}

/**
 * @brief Component::setAttributeList
 * @param attributeList
 */
void Component::setAttributeList(AttributeList* attributeList){

    delete this->attributeList;
    this->attributeList = attributeList;
}

/**
 * @brief Component::getID
 * @return
 */
ID* Component::getID(){

    return this->id;
}

/**
 * @brief Component::getType
 * @return
 */
Type* Component::getType(){

    return this->type;
}

/**
 * @brief Component::isDeactivated
 * @return
 */
int Component::isDeactivated(){

    return this->deactivated;
}

/**
 * @brief Component::getAttributeList
 * @return
 */
AttributeList* Component::getAttributeList(){

    return this->attributeList;
}
