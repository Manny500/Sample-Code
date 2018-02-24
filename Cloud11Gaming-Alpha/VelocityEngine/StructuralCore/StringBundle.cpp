#include "StringBundle.h"

/**
 * @brief StringBundle::StringBundle
 */
StringBundle::StringBundle(){

    this->dataType = "string";
    this->data = new std::vector<std::string>;
}

/**
 * @brief StringBundle::~StringBundle
 */
StringBundle::~StringBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief StringBundle::addString
 * @param data
 */
void StringBundle::addString(std::string data){

    this->data->push_back(data);
}

/**
 * @brief StringBundle::getString
 * @param index
 * @return
 */
std::string StringBundle::getString(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief StringBundle::getSegmentCount
 * @return
 */
unsigned int StringBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief StringBundle::removeAllData
 */
void StringBundle::removeAllData(){

    for (unsigned int i = 0; i < this->data->size(); i++){
        this->data->at(i).clear();
    }

    this->data->clear();
}
