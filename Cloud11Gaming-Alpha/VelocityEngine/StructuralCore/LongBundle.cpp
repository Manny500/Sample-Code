#include "LongBundle.h"

/**
 * @brief LongBundle::LongBundle
 */
LongBundle::LongBundle(){

    this->dataType = "long";
    this->data = new std::vector<long>;
}

/**
 * @brief LongBundle::~LongBundle
 */
LongBundle::~LongBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief LongBundle::addLong
 * @param data
 */
void LongBundle::addLong(long data){

    this->data->push_back(data);
}

/**
 * @brief LongBundle::getLong
 * @param index
 * @return
 */
long LongBundle::getLong(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief LongBundle::getSegmentCount
 * @return
 */
unsigned int LongBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief LongBundle::removeAllData
 */
void LongBundle::removeAllData(){

    this->data->clear();
}
