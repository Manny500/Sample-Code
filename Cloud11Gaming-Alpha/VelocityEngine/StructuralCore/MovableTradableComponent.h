#ifndef MOVABLETRADABLECOMPONENT_H
#define MOVABLETRADABLECOMPONENT_H

//Project
#include "MovableComponent.h"
#include "Tradable.h"


/**
 * @brief The MovableTradableComponent class
 */
class MovableTradableComponent : public MovableComponent, public Tradable{


public:

    MovableTradableComponent();
    MovableTradableComponent(ID* id);
    MovableTradableComponent(unsigned int serialID);
    MovableTradableComponent(unsigned int serialID, int assignedID);
    MovableTradableComponent(Type* type);
    MovableTradableComponent(ID* id, Type* type);
    MovableTradableComponent(unsigned int serialID, int assignedID, Type* type);
    ~MovableTradableComponent();


};

#endif // MOVABLETRADABLECOMPONENT_H
