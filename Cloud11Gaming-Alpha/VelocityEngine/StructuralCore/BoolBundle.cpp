#include "BoolBundle.h"

/**
 * @brief BoolBundle::BoolBundle
 */
BoolBundle::BoolBundle(){

    this->dataType = "bool";
    this->data = new std::vector<bool>;
}

/**
 * @brief BoolBundle::~BoolBundle
 */
BoolBundle::~BoolBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief BoolBundle::addBool adds to the bundle
 * @param data
 */
void BoolBundle::addBool(bool data){

    this->data->push_back(data);
}

/**
 * @brief BoolBundle::getBool
 * @param index
 * @return
 */
bool BoolBundle::getBool(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief BoolBundle::getSegmentCount
 * @return
 */
unsigned int BoolBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief BoolBundle::removeAllData
 */
void BoolBundle::removeAllData(){

    this->data->clear();
}
