#include "DoubleBundle.h"

/**
 * @brief DoubleBundle::DoubleBundle
 */
DoubleBundle::DoubleBundle(){

    this->dataType = "double";
    this->data = new std::vector<double>;
}

/**
 * @brief DoubleBundle::~DoubleBundle
 */
DoubleBundle::~DoubleBundle(){

    removeAllData();
    delete this->data;
    this->data = NULL;
}

/**
 * @brief DoubleBundle::addDouble
 * @param data
 */
void DoubleBundle::addDouble(double data){

    this->data->push_back(data);
}

/**
 * @brief DoubleBundle::getDouble
 * @param index
 * @return
 */
double DoubleBundle::getDouble(unsigned int index){

    return this->data->at(index);
}

/**
 * @brief DoubleBundle::getSegmentCount
 * @return
 */
unsigned int DoubleBundle::getSegmentCount(){

    return this->data->size();
}

/**
 * @brief DoubleBundle::removeAllData
 */
void DoubleBundle::removeAllData(){

    this->data->clear();
}
