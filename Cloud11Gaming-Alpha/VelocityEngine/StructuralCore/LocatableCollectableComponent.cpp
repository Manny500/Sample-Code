#include "LocatableCollectableComponent.h"

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 */
LocatableCollectableComponent::LocatableCollectableComponent(){}

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 * @param id
 */
LocatableCollectableComponent::LocatableCollectableComponent(ID* id)
    : LocatableComponent(id){}

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 * @param serialID
 */
LocatableCollectableComponent::LocatableCollectableComponent(unsigned int serialID)
    : LocatableComponent(serialID){}

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 * @param serialID
 * @param assignedID
 */
LocatableCollectableComponent::LocatableCollectableComponent(unsigned int serialID, int assignedID)
    : LocatableComponent(serialID, assignedID){}

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 * @param type
 */
LocatableCollectableComponent::LocatableCollectableComponent(Type* type)
    : LocatableComponent(type){}

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 * @param id
 * @param type
 */
LocatableCollectableComponent::LocatableCollectableComponent(ID* id, Type* type)
    : LocatableComponent(id, type){}

/**
 * @brief LocatableCollectableComponent::LocatableCollectableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
LocatableCollectableComponent::LocatableCollectableComponent(unsigned int serialID, int assignedID, Type* type)
    : LocatableComponent(serialID, assignedID, type){}

/**
 * @brief LocatableCollectableComponent::~LocatableCollectableComponent
 */
LocatableCollectableComponent::~LocatableCollectableComponent(){}
