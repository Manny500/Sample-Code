#include "CollectableComponent.h"

/**
 * @brief CollectableComponent::CollectableComponent
 */
CollectableComponent::CollectableComponent(){}

/**
 * @brief CollectableComponent::CollectableComponent
 * @param id
 */
CollectableComponent::CollectableComponent(ID* id)
    : Component(id){}

/**
 * @brief CollectableComponent::CollectableComponent
 * @param serialID
 */
CollectableComponent::CollectableComponent(unsigned int serialID)
    : Component(serialID){}

/**
 * @brief CollectableComponent::CollectableComponent
 * @param serialID
 * @param assignedID
 */
CollectableComponent::CollectableComponent(unsigned int serialID, int assignedID)
    : Component(serialID, assignedID){}

/**
 * @brief CollectableComponent::CollectableComponent
 * @param type
 */
CollectableComponent::CollectableComponent(Type* type)
    : Component(type){}

/**
 * @brief CollectableComponent::CollectableComponent
 * @param id
 * @param type
 */
CollectableComponent::CollectableComponent(ID* id, Type* type)
    : Component(id, type){}

/**
 * @brief CollectableComponent::CollectableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
CollectableComponent::CollectableComponent(unsigned int serialID, int assignedID, Type* type)
    : Component(serialID, assignedID, type){}

/**
 * @brief CollectableComponent::~CollectableComponent
 */
CollectableComponent::~CollectableComponent(){}

