#include "AttributeList.h"

/**
 * @brief AttributeList::AttributeList
 */
AttributeList::AttributeList(){

    this->attributes = new std::vector<Attribute*>;
}

/**
 * @brief AttributeList::~AttributeList
 */
AttributeList::~AttributeList(){

    removeAllAttributes();
    delete this->attributes;
    this->attributes = NULL;
}

/**
 * @brief AttributeList::addAttribute add to the list
 * @param attribute the atrribute to add
 */
void AttributeList::addAttribute(Attribute* attribute){

    this->attributes->push_back(attribute);
}

/**
 * @brief AttributeList::setAttributeValue sets the att value usign label and valuie
 * @param label
 * @param value
 */
void AttributeList::setAttributeValue(int label, double value){


    Attribute* att = getAttribute(label);
    if (att != NULL) att->setValue(value);
}

/**
 * @brief AttributeList::setAttributeValue using string name and value
 * @param name
 * @param value
 */
void AttributeList::setAttributeValue(std::string name, double value){

    Attribute* att = getAttribute(name);
    if (att != NULL) att->setValue(value);
}

/**
 * @brief AttributeList::addToAttributeValue adds to att list
 * @param label
 * @param value
 */
void AttributeList::addToAttributeValue(int label, double value){

    Attribute* att = getAttribute(label);
    if (att != NULL) att->addToValue(value);
}

/**
 * @brief AttributeList::addToAttributeValue adds to att value
 * @param name
 * @param value
 */
void AttributeList::addToAttributeValue(std::string name, double value){

    Attribute* att = getAttribute(name);
    if (att != NULL) att->addToValue(value);
}

/**
 * @brief AttributeList::setAttributeDescription sets att description using label and value
 * @param label
 * @param description
 */
void AttributeList::setAttributeDescription(int label, std::string description){

    Attribute* att = getAttribute(label);
    if (att != NULL) att->setDescription(description);
}

/**
 * @brief AttributeList::setAttributeDescription using label and description
 * @param name
 * @param description
 */
void AttributeList::setAttributeDescription(std::string name, std::string description){

    Attribute* att = getAttribute(name);
    if (att != NULL) att->setDescription(description);
}

/**
 * @brief AttributeList::setAllAttributes uses attribute vector to set all atts
 * @param attributes
 */
void AttributeList::setAllAttributes(std::vector<Attribute*>* attributes){

    this->attributes = attributes;
}

/**
 * @brief AttributeList::getAttributeCount gets att count
 * @return
 */
unsigned int AttributeList::getAttributeCount(){

    return this->attributes->size();
}

/**
 * @brief AttributeList::getAllAttributes
 * @return
 */
std::vector<Attribute*>* AttributeList::getAllAttributes(){

    return this->attributes;
}

/**
 * @brief AttributeList::getAttributeAt the index
 * @param index
 * @return
 */
Attribute* AttributeList::getAttributeAt(unsigned int index){

    return this->attributes->at(index);
}

/**
 * @brief AttributeList::getAttribute uses label to get the attribute
 * @param label
 * @return
 */
Attribute* AttributeList::getAttribute(int label){

    for (unsigned int i = 0; i < this->attributes->size(); i++){
        Attribute* att = this->attributes->at(i);
        if (att->getLabel() == label)
            return att;
    }

    return NULL;
}

/**
 * @brief AttributeList::getAttribute uses name
 * @param name
 * @return
 */
Attribute* AttributeList::getAttribute(std::string name){

    for (unsigned int i = 0; i < this->attributes->size(); i++){
        Attribute* att = this->attributes->at(i);
        if (att->getName() == name)
            return att;
    }

    return NULL;
}

/**
 * @brief AttributeList::getAttributeValue using the label
 * @param label
 * @return
 */
double AttributeList::getAttributeValue(int label){

    return getAttribute(label)->getValue();
}

/**
 * @brief AttributeList::getAttributeValue
 * @param name
 * @return
 */
double AttributeList::getAttributeValue(std::string name){

    return getAttribute(name)->getValue();
}

/**
 * @brief AttributeList::getAttributeDescription
 * @param label
 * @return
 */
std::string AttributeList::getAttributeDescription(int label){

    return getAttribute(label)->getDescription();
}

/**
 * @brief AttributeList::getAttributeDescription
 * @param name
 * @return
 */
std::string AttributeList::getAttributeDescription(std::string name){

    return getAttribute(name)->getDescription();
}

/**
 * @brief AttributeList::removeAttributeAt the spot
 * @param index
 */
void AttributeList::removeAttributeAt(unsigned int index){

    delete this->attributes->at(index);
    this->attributes->at(index) = this->attributes->at(this->attributes->size() - 1);
    this->attributes->pop_back();
}

/**
 * @brief AttributeList::removeAttribute using the label
 * @param label
 */
void AttributeList::removeAttribute(int label){

    int removeIndex = -1;

    for (unsigned int i = 0; i < this->attributes->size(); i++){

        Attribute* att = this->attributes->at(i);
        if (att->getLabel() == label){
            removeIndex = i;
            break;
        }
    }

    if (removeIndex != -1)
        removeAttributeAt(removeIndex);
}

/**
 * @brief AttributeList::removeAttribute using the name
 * @param name
 */
void AttributeList::removeAttribute(std::string name){

    int removeIndex;

    for (unsigned int i = 0; i < this->attributes->size(); i++){

        Attribute* att = this->attributes->at(i);
        if (att->getName() == name){
            removeIndex = i;
            break;
        }
    }

    if (removeIndex != -1)
        removeAttributeAt(removeIndex);
}

/**
 * @brief AttributeList::removeAllAttributes
 */
void AttributeList::removeAllAttributes(){

    for (unsigned int i = 0; i < this->attributes->size(); i++)
        delete this->attributes->at(i);

    this->attributes->clear();
}
