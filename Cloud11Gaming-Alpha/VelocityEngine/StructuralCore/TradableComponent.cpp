#include "TradableComponent.h"

/**
 * @brief TradableComponent::TradableComponent
 */
TradableComponent::TradableComponent(){}

/**
 * @brief TradableComponent::TradableComponent
 * @param id
 */
TradableComponent::TradableComponent(ID* id)
    : Component(id){}

/**
 * @brief TradableComponent::TradableComponent
 * @param serialID
 */
TradableComponent::TradableComponent(unsigned int serialID)
    : Component(serialID){}

/**
 * @brief TradableComponent::TradableComponent
 * @param serialID
 * @param assignedID
 */
TradableComponent::TradableComponent(unsigned int serialID, int assignedID)
    : Component(serialID, assignedID){}

/**
 * @brief TradableComponent::TradableComponent
 * @param type
 */
TradableComponent::TradableComponent(Type* type)
    : Component(type){}

/**
 * @brief TradableComponent::TradableComponent
 * @param id
 * @param type
 */
TradableComponent::TradableComponent(ID* id, Type* type)
    : Component(id, type){}

/**
 * @brief TradableComponent::TradableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
TradableComponent::TradableComponent(unsigned int serialID, int assignedID, Type* type)
    : Component(serialID, assignedID, type){}

/**
 * @brief TradableComponent::~TradableComponent
 */
TradableComponent::~TradableComponent(){}
