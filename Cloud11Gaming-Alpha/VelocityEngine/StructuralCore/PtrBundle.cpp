#include "PtrBundle.h"

/**
 * @brief PtrBundle::PtrBundle
 */
PtrBundle::PtrBundle(){

    this->dataType = "ptr";
    this->data = new std::vector<unsigned long long>;
}

/**
 * @brief PtrBundle::~PtrBundle
 */
PtrBundle::~PtrBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief PtrBundle::addPtr
 * @param data
 */
void PtrBundle::addPtr(unsigned long long data){

    this->data->push_back(data);
}

/**
 * @brief PtrBundle::getPtr
 * @param index
 * @return
 */
unsigned long long PtrBundle::getPtr(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief PtrBundle::getSegmentCount
 * @return
 */
unsigned int PtrBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief PtrBundle::removeAllData
 */
void PtrBundle::removeAllData(){

    this->data->clear();
}
