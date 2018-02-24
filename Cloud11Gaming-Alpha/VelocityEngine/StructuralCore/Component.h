#ifndef COMPONENT_H
#define COMPONENT_H

//Project
#include "ID.h"
#include "Type.h"


/**
 * @brief The Component class
 */
class Component : public Accessible{


protected:

    ID* id;
    Type* type;
    int deactivated;
    AttributeList* attributeList;


public:

    Component();
    Component(ID* id);
    Component(unsigned int serialID);
    Component(unsigned int serialID, int assignedID);
    Component(Type* type);
    Component(ID* id, Type* type);
    Component(unsigned int serialID, int assignedID, Type* type);
    ~Component();

    void setID(ID* id);
    void setID(unsigned int seriallID, int assignedID);
    void setSerialID(unsigned int seriallID);
    void setAssignedID(int assignedID);
    void setType(Type* type);
    void deactivate();
    void activate();
    void setAttributeList(AttributeList* attributeList);

    ID* getID();
    Type* getType();
    int isDeactivated();
    AttributeList* getAttributeList();


};

#endif // COMPONENT_H
