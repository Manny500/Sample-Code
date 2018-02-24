#ifndef LOCATION_H
#define LOCATION_H

//Project
#include "LocatableCollectableComponent.h"
#include "LocatableTradableComponent.h"
#include "MovableCollectableComponent.h"
#include "MovableTradableComponent.h"




class Location : public Accessible{


private:

    Coordinates* coordinates;
    Type* type;
    AttributeList* attributeList;
    std::vector<LocatableComponent*>* locatableComponents;


public:

    Location(int x, int y, int z, int s);
    Location(int x, int y, int z, int s, Type* type);
    ~Location();

    void setCoordinates(int x, int y, int z, int s);
    void setType(Type* type);
    void setAttributeList(AttributeList* attributeList);
    void setAllLocatableComponents(std::vector<LocatableComponent*>* locatableComponents);
    void addLocatableComponent(LocatableComponent* locatableComponent);

    Coordinates* getCoordinates();
    Type* getType();
    AttributeList* getAttributeList();
    unsigned int getLocatableComponentCount();
    std::vector<LocatableComponent*>* getAllLocatableComponents();
    LocatableComponent* getLocatableComponentAt(unsigned int index);
    LocatableComponent* getLocatableComponentOfSerialID(unsigned int serialID);
    LocatableComponent* getLocatableComponentOfAssignedID(int assignedID);
    std::vector<LocatableComponent*>* getLocatableComponentsOfType(Type* type);
    LocatableComponent* getLocatableComponentFromTop();
    LocatableComponent* retrieveLocatableComponentAt(unsigned int index);
    LocatableComponent* retrieveLocatableComponentOfSerialID(unsigned int serialID);
    LocatableComponent* retrieveLocatableComponentOfAssignedID(int assignedID);
    LocatableComponent* retrieveLocatableComponentFromTop();
    bool isEmpty();

    void removeCoordinates();
    void removeType();
    void removeAttributeList();
    void removeDeactivated();
    void removeLocatableComponentAt(unsigned int index);
    void removeLocatableComponentOfSerialID(unsigned int serialID);
    void removeLocatableComponentOfAssignedID(int assignedID);
    void removeLocatableComponentsOfType(Type* type);
    void removeLocatableComponentsOfType(int typeLabel);
    void removeLocatableComponentsOfType(std::string name);
    void removeAllLocatableComponents();


};

#endif // LOCATION_H
