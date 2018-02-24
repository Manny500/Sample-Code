#ifndef TYPE_H
#define TYPE_H

// Project
#include "AttributeList.h"


/**
 * @brief The Type class
 */
class Type: public Accessible{


private:

    int label;
    std::string name;
    AttributeList* attributeList;


public:

    Type();
    Type(int label);
    Type(std::string name);
    Type(int label, std::string name);
    ~Type();

    void setLabel(int label);
    void setName(std::string name);
    void setAttributeList(AttributeList* attributeList);

    int getLabel();
    std::string getName();
    AttributeList* getAttributeList();

    void removeAttributeList();


};

#endif // TYPE_H

