#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

//Project
#include "Accessible.h"


/**
 * @brief The Attribute class
 */
class Attribute : public Accessible{


private:

    int label;
    std::string name;
    double value;
    std::string description;


public:

    Attribute();
    Attribute(int label, double value);
    Attribute(int label, std::string description);
    Attribute(int label, double value, std::string description);
    Attribute(std::string name, double value);
    Attribute(std::string name, std::string description);
    Attribute(std::string name, double value, std::string description);
    Attribute(int label, std::string name, double value);
    Attribute(int label, std::string name, std::string description);
    Attribute(int label, std::string name, double value, std::string description);
    ~Attribute();

    void setLabel(int label);
    void setName(std::string name);
    void setValue(double value);
    void addToValue(double update);
    void setDescription(std::string description);

    int getLabel();
    std::string getName();
    double getValue();
    std::string getDescription();


};

#endif // ATTRIBUTE_H
