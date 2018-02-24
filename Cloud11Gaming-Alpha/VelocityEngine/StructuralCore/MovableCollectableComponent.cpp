#include "MovableCollectableComponent.h"

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 */
MovableCollectableComponent::MovableCollectableComponent(){}

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 * @param id
 */
MovableCollectableComponent::MovableCollectableComponent(ID* id)
    : MovableComponent(id){}

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 * @param serialID
 */
MovableCollectableComponent::MovableCollectableComponent(unsigned int serialID)
    : MovableComponent(serialID){}

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 * @param serialID
 * @param assignedID
 */
MovableCollectableComponent::MovableCollectableComponent(unsigned int serialID, int assignedID)
    : MovableComponent(serialID, assignedID){}

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 * @param type
 */
MovableCollectableComponent::MovableCollectableComponent(Type* type)
    : MovableComponent(type){}

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 * @param id
 * @param type
 */
MovableCollectableComponent::MovableCollectableComponent(ID* id, Type* type)
    : MovableComponent(id, type){}

/**
 * @brief MovableCollectableComponent::MovableCollectableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
MovableCollectableComponent::MovableCollectableComponent(unsigned int serialID, int assignedID, Type* type)\
    : MovableComponent(serialID, assignedID, type){}

/**
 * @brief MovableCollectableComponent::~MovableCollectableComponent
 */
MovableCollectableComponent::~MovableCollectableComponent(){}
