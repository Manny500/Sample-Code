#include "CharBundle.h"

/**
 * @brief CharBundle::CharBundle
 */
CharBundle::CharBundle(){

    this->dataType = "char";
    this->data = new std::vector<char>;
}

/**
 * @brief CharBundle::~CharBundle
 */
CharBundle::~CharBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief CharBundle::addChar
 * @param data
 */
void CharBundle::addChar(char data){

    this->data->push_back(data);
}

/**
 * @brief CharBundle::getChar
 * @param index
 * @return
 */
char CharBundle::getChar(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief CharBundle::getSegmentCount
 * @return
 */
unsigned int CharBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief CharBundle::removeAllData
 */
void CharBundle::removeAllData(){

    this->data->clear();
}
