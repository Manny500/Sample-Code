#ifndef COLLECTABLECOMPONENT_H
#define COLLECTABLECOMPONENT_H

//Project
#include "Component.h"
#include "Collectable.h"


/**
 * @brief The CollectableComponent class
 */
class CollectableComponent: public Component, public Collectable{


public:

    CollectableComponent();
    CollectableComponent(ID* id);
    CollectableComponent(unsigned int serialID);
    CollectableComponent(unsigned int serialID, int assignedID);
    CollectableComponent(Type* type);
    CollectableComponent(ID* id, Type* type);
    CollectableComponent(unsigned int serialID, int assignedID, Type* type);
    ~CollectableComponent();


};

#endif // COLLECTABLECOMPONENT_H
