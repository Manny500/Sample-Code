#ifndef LOCATABLETRADABLECOMPONENT_H
#define LOCATABLETRADABLECOMPONENT_H

//Project
#include "LocatableComponent.h"
#include "Tradable.h"


/**
 * @brief The LocatableTradableComponent class
 */
class LocatableTradableComponent : public LocatableComponent, public Tradable{


public:

    LocatableTradableComponent();
    LocatableTradableComponent(ID* id);
    LocatableTradableComponent(unsigned int serialID);
    LocatableTradableComponent(unsigned int serialID, int assignedID);
    LocatableTradableComponent(Type* type);
    LocatableTradableComponent(ID* id, Type* type);
    LocatableTradableComponent(unsigned int serialID, int assignedID, Type* type);
    ~LocatableTradableComponent();


};

#endif // LOCATABLETRADABLECOMPONENT_H
