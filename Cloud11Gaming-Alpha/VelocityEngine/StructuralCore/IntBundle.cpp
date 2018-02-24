#include "IntBundle.h"

/**
 * @brief IntBundle::IntBundle
 */
IntBundle::IntBundle(){

    this->dataType = "int";
    this->data = new std::vector<int>;
}

/**
 * @brief IntBundle::~IntBundle
 */
IntBundle::~IntBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief IntBundle::addInt
 * @param data
 */
void IntBundle::addInt(int data){

    this->data->push_back(data);
}

/**
 * @brief IntBundle::getInt
 * @param index
 * @return
 */
int IntBundle::getInt(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief IntBundle::getSegmentCount
 * @return
 */
unsigned int IntBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief IntBundle::removeAllData
 */
void IntBundle::removeAllData(){

    this->data->clear();
}
