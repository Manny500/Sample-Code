#ifndef DATABUNDLE_H
#define DATABUNDLE_H

//General
#include <vector>

//Project
#include "Accessible.h"


/**
 * @brief The DataBundle class
 */
class DataBundle : public Accessible{


protected:

    DataBundle* linkedBundle;
    std::string dataType;
    std::string identifier;


public:

    DataBundle();
    ~DataBundle();

    void setIdentifier(std::string identifier);
    void setLinkedBundle(DataBundle* linkedBundle);

    std::string getDataType();
    std::string getIdentifier();
    DataBundle* getLinkedBundle();

    void removeLinkedBundle();


};

#endif // DATABUNDLE_H
