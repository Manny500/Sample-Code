#ifndef ATTRIBUTELIST_H
#define ATTRIBUTELIST_H

//General
#include <vector>

//Project
#include "Attribute.h"


/**
 * @brief The AttributeList class
 */
class AttributeList : public Accessible{


private:

    std::vector<Attribute*>* attributes;


public:

    AttributeList();
    ~AttributeList();

    void addAttribute(Attribute* attribute);
    void setAttributeValue(int label, double value);
    void setAttributeValue(std::string name, double value);
    void addToAttributeValue(int label, double value);
    void addToAttributeValue(std::string name, double value);
    void setAttributeDescription(int label, std::string description);
    void setAttributeDescription(std::string name, std::string description);
    void setAllAttributes(std::vector<Attribute*>* attributes);

    unsigned int getAttributeCount();
    std::vector<Attribute*>* getAllAttributes();
    Attribute* getAttributeAt(unsigned int index);
    Attribute* getAttribute(int label);
    Attribute* getAttribute(std::string name);
    double getAttributeValue(int label);
    double getAttributeValue(std::string name);
    std::string getAttributeDescription(int label);
    std::string getAttributeDescription(std::string name);

    void removeAttributeAt(unsigned int index);
    void removeAttribute(int label);
    void removeAttribute(std::string name);
    void removeAllAttributes();


};

#endif // ATTRIBUTELIST_H

