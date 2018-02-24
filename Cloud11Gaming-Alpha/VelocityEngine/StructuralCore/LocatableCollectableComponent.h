#ifndef LOCATABLECOLLECTABLECOMPONENT_H
#define LOCATABLECOLLECTABLECOMPONENT_H

//Project
#include "LocatableComponent.h"
#include "Collectable.h"


/**
 * @brief The LocatableCollectableComponent class
 */
class LocatableCollectableComponent : public LocatableComponent, public Collectable{


public:

    LocatableCollectableComponent();
    LocatableCollectableComponent(ID* id);
    LocatableCollectableComponent(unsigned int serialID);
    LocatableCollectableComponent(unsigned int serialID, int assignedID);
    LocatableCollectableComponent(Type* type);
    LocatableCollectableComponent(ID* id, Type* type);
    LocatableCollectableComponent(unsigned int serialID, int assignedID, Type* type);
    ~LocatableCollectableComponent();


};

#endif // LOCATABLECOLLECTABLECOMPONENT_H
