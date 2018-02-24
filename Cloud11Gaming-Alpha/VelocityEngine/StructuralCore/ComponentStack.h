#ifndef COMPONENTSTACK_H
#define COMPONENTSTACK_H

//Project
#include "CollectableComponent.h"
#include "TradableComponent.h"
#include "../MathLibraries/Randomizer.h"


/**
 * @brief The ComponentStack class
 */
class ComponentStack: public Accessible{


private:

    Type* type;
    std::vector<Component*>* components;


public:

    ComponentStack();
    ComponentStack(Type* type);
    ~ComponentStack();

    void setComponentStackType(Type* type);
    void setAllComponents(std::vector<Component*>* components);
    void addComponent(Component* component);
    void randomizeOrder(unsigned iteration);
    void sortBySerialID();
    void sortByAssignedID();
    void sortByTypeLabel();
    void sortByAttributeValue();

    Type* getType();
    unsigned int getComponentCount();
    std::vector<Component*>* getAllComponents();
    std::vector<Component*>* getComponentsOfType(Type* type);
    Component* getComponentAt(unsigned int index);
    Component* getComponentOfSerialID(unsigned int serialID);
    Component* getComponentOfAssignedID(int assignedID);
    Component* getComponentFromTop();
    std::vector<Component*>* retrieveComponentsOfType(Type* type);
    Component* retrieveComponentAt(unsigned int index);
    Component* retrieveComponentOfSerialID(unsigned int serialID);
    Component* retrieveComponentOfAssignedID(int assignedID);
    Component* retrieveComponentFromTop();
    bool isEmpty();

    void removeDeactivated();
    void removeComponentFromTop();
    void removeComponentAt(unsigned int index);
    void removeComponentOfSerialID(unsigned int serialID);
    void removeComponentOfAssignedID(int assignedID);
    void removeComponentsOfType(Type* type);
    void removeAllComponents();


};

#endif // COMPONENTSTACK_H
