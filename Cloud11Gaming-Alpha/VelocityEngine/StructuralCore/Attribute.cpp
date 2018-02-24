#include "Attribute.h"

/**
 * @brief Attribute::Attribute
 */
Attribute::Attribute(){}

/**
 * @brief Attribute::~Attribute
 */
Attribute::~Attribute(){

    this->name.clear();
    this->description.clear();
}


Attribute::Attribute(int label, double value){

    this->label = label;
    this->value = value;
}

/**
 * @brief Attribute::Attribute will set variables values
 * @param label set the label value to this
 * @param description set the description to this
 */
Attribute::Attribute(int label, std::string description){

    this->label = label;
    this->description = description;
}

/**
 * @brief Attribute::Attribute will set variables values
 * @param label set the label value to this
 * @param value will set value variable to this
 * @param description set the description to this
 */
Attribute::Attribute(int label, double value, std::string description){

    this->label = label;
    this->value = value;
    this->description = description;
}

/**
 * @brief Attribute::Attribute will set variables values
 * @param name will set variable name to this
 * @param value will set value variable to this
 */
Attribute::Attribute(std::string name, double value){

    this->name = name;
    this->value = value;
}

/**
 * @brief Attribute::Attribute Attribute will set variables values
 * @param name  will set variable name to this
 * @param description set the description to this
 */
Attribute::Attribute(std::string name, std::string description){

    this->name = name;
    this->description = description;
}

/**
 * @brief Attribute::Attribute Attribute will set variables values
 * @param name will set variable name to this
 * @param value will set value variable to this
 * @param description set the description to this
 */
Attribute::Attribute(std::string name, double value, std::string description){

    this->name = name;
    this->value = value;
    this->description = description;
}

/**
 * @brief Attribute::Attribute Attribute will set variables value
 * @param label set the label value to this
 * @param name will set variable name to this
 * @param value will set value variable to this
 */
Attribute::Attribute(int label, std::string name, double value){

    this->label = label;
    this->name = name;
    this->value = value;
}

/**
 * @brief Attribute::Attribute Attribute will set variables value
 * @param label set the label value to this
 * @param name will set variable name to this
 * @param description set the description to this
 */
Attribute::Attribute(int label, std::string name, std::string description){

    this->label = label;
    this->name = name;
    this->description = description;
}

/**
 * @brief Attribute::Attribute Attribute will set variables value
 * @param label set the label value to this
 * @param name will set variable name to this
 * @param value will set value variable to this
 * @param description set the description to this
 */
Attribute::Attribute(int label, std::string name, double value, std::string description){

    this->label = label;
    this->name = name;
    this->value = value;
    this->description = description;
}

/**
 * @brief Attribute::setLabel will set the label
 * @param label is to set it up to
 */
void Attribute::setLabel(int label){

    this->label = label;
}

/**
 * @brief Attribute::setName sets the name
 * @param name
 */
void Attribute::setName(std::string name){

    this->name = name;
}

/**
 * @brief Attribute::setValue sets the value
 * @param value
 */
void Attribute::setValue(double value){

    this->value = value;
}

/**
 * @brief Attribute::addToValue adds to the value
 * @param update
 */
void Attribute::addToValue(double update){

    this->value += update;
}


void Attribute::setDescription(std::string description){

    this->description = description;
}

/**
 * @brief Attribute::getLabel gets the label
 * @return
 */
int Attribute::getLabel(){

    return this->label;
}

/**
 * @brief Attribute::getName gets the name
 * @return
 */
std::string Attribute::getName(){

    return this->name;
}

/**
 * @brief Attribute::getValue
 * @return
 */
double Attribute::getValue(){

    return this->value;
}

/**
 * @brief Attribute::getDescription
 * @return
 */
std::string Attribute::getDescription(){

    return this->description;
}

