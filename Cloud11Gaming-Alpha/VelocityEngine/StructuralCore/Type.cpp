#include "Type.h"

/**
 * @brief Type::Type
 */
Type::Type(){

    this->attributeList =  new AttributeList();
}

/**
 * @brief Type::Type
 * @param label
 */
Type::Type(int label){

    this->label = label;
    this->attributeList = new AttributeList();
}

/**
 * @brief Type::Type
 * @param name
 */
Type::Type(std::string name){

    this->name = name;
    this->attributeList = new AttributeList();
}

/**
 * @brief Type::Type
 * @param label
 * @param name
 */
Type::Type(int label, std::string name){

    this->label = label;
    this->name = name;
    this->attributeList = new AttributeList();
}

/**
 * @brief Type::~Type
 */
Type::~Type(){

    removeAttributeList();

    delete this->attributeList;

    this->attributeList = NULL;
}

/**
 * @brief Type::setLabel
 * @param label
 */
void Type::setLabel(int label){

    this->label = label;
}

/**
 * @brief Type::setName
 * @param name
 */
void Type::setName(std::string name){

    this->name = name;
}

/**
 * @brief Type::setAttributeList
 * @param attributeList
 */
void Type::setAttributeList(AttributeList* attributeList){

    this->attributeList = attributeList;
}

/**
 * @brief Type::getLabel
 * @return
 */
int Type::getLabel(){

    return this->label;
}

/**
 * @brief Type::getName
 * @return
 */
std::string Type::getName(){

    return this->name;
}

/**
 * @brief Type::getAttributeList
 * @return
 */
AttributeList* Type::getAttributeList(){

    return this->attributeList;
}

/**
 * @brief Type::removeAttributeList
 */
void Type::removeAttributeList(){

    this->attributeList->removeAllAttributes();
}
