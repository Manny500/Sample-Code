#include "LocatableTradableComponent.h"

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 */
LocatableTradableComponent::LocatableTradableComponent(){}

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 * @param id
 */
LocatableTradableComponent::LocatableTradableComponent(ID* id)
    : LocatableComponent(id){}

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 * @param serialID
 */
LocatableTradableComponent::LocatableTradableComponent(unsigned int serialID)
    : LocatableComponent(serialID){}

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 * @param serialID
 * @param assignedID
 */
LocatableTradableComponent::LocatableTradableComponent(unsigned int serialID, int assignedID)
    : LocatableComponent(serialID, assignedID){}

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 * @param type
 */
LocatableTradableComponent::LocatableTradableComponent(Type* type)
    : LocatableComponent(type){}

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 * @param id
 * @param type
 */
LocatableTradableComponent::LocatableTradableComponent(ID* id, Type* type)
    : LocatableComponent(id, type){}

/**
 * @brief LocatableTradableComponent::LocatableTradableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
LocatableTradableComponent::LocatableTradableComponent(unsigned int serialID, int assignedID, Type* type)
    : LocatableComponent(serialID, assignedID, type){}

/**
 * @brief LocatableTradableComponent::~LocatableTradableComponent
 */
LocatableTradableComponent::~LocatableTradableComponent(){}
