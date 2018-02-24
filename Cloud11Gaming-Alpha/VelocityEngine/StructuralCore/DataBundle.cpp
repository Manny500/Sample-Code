#include "DataBundle.h"

/**
 * @brief DataBundle::DataBundle
 */
DataBundle::DataBundle(){

    linkedBundle = NULL;
    dataType = "data";
    identifier = "";
}

/**
 * @brief DataBundle::~DataBundle
 */
DataBundle::~DataBundle(){

    removeLinkedBundle();
    this->dataType.clear();
    this->identifier.clear();
}

/**
 * @brief DataBundle::setIdentifier
 * @param identifier
 */
void DataBundle::setIdentifier(std::string identifier){

    this->identifier = identifier;
}

/**
 * @brief DataBundle::setLinkedBundle
 * @param linkedBundle
 */
void DataBundle::setLinkedBundle(DataBundle* linkedBundle){

    this->linkedBundle = linkedBundle;
}

/**
 * @brief DataBundle::getDataType
 * @return
 */
std::string DataBundle::getDataType(){

    return this->dataType;
}

/**
 * @brief DataBundle::getIdentifier
 * @return
 */
std::string DataBundle::getIdentifier(){

    return this->identifier;
}

/**
 * @brief DataBundle::getLinkedBundle
 * @return
 */
DataBundle* DataBundle::getLinkedBundle(){

    return this->linkedBundle;
}

/**
 * @brief DataBundle::removeLinkedBundle
 */
void DataBundle::removeLinkedBundle(){

    if (linkedBundle != NULL){
        delete this->linkedBundle;
        linkedBundle = NULL;
    }
}
