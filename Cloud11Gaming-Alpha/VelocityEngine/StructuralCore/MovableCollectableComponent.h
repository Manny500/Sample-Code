#ifndef MOVABLECOLLECTABLECOMPONENT_H
#define MOVABLECOLLECTABLECOMPONENT_H

//Project
#include "MovableComponent.h"
#include "Collectable.h"


/**
 * @brief The MovableCollectableComponent class
 */
class MovableCollectableComponent : public MovableComponent, public Collectable{


public:

    MovableCollectableComponent();
    MovableCollectableComponent(ID* id);
    MovableCollectableComponent(unsigned int serialID);
    MovableCollectableComponent(unsigned int serialID, int assignedID);
    MovableCollectableComponent(Type* type);
    MovableCollectableComponent(ID* id, Type* type);
    MovableCollectableComponent(unsigned int serialID, int assignedID, Type* type);
    ~MovableCollectableComponent();


};

#endif // MOVABLECOLLECTABLECOMPONENT_H
