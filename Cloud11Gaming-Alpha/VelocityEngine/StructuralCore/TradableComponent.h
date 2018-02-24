#ifndef TRADABLECOMPONENT_H
#define TRADABLECOMPONENT_H

//Project
#include "Component.h"
#include "Tradable.h"


/**
 * @brief The TradableComponent class
 */
class TradableComponent: public Component, public Tradable{


public:

    TradableComponent();
    TradableComponent(ID* id);
    TradableComponent(unsigned int serialID);
    TradableComponent(unsigned int serialID, int assignedID);
    TradableComponent(Type* type);
    TradableComponent(ID* id, Type* type);
    TradableComponent(unsigned int serialID, int assignedID, Type* type);
    ~TradableComponent();

};

#endif // TRADABLECOMPONENT_H
