#include "MovableTradableComponent.h"

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 */
MovableTradableComponent::MovableTradableComponent(){}

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 * @param id
 */
MovableTradableComponent::MovableTradableComponent(ID* id)
    : MovableComponent(id){}

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 * @param serialID
 */
MovableTradableComponent::MovableTradableComponent(unsigned int serialID)
    : MovableComponent(serialID){}

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 * @param serialID
 * @param assignedID
 */
MovableTradableComponent::MovableTradableComponent(unsigned int serialID, int assignedID)
    : MovableComponent(serialID, assignedID){}

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 * @param type
 */
MovableTradableComponent::MovableTradableComponent(Type* type)
    : MovableComponent(type){}

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 * @param id
 * @param type
 */
MovableTradableComponent::MovableTradableComponent(ID* id, Type* type)
    : MovableComponent(id, type){}

/**
 * @brief MovableTradableComponent::MovableTradableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
MovableTradableComponent::MovableTradableComponent(unsigned int serialID, int assignedID, Type* type)\
    : MovableComponent(serialID, assignedID, type){}

/**
 * @brief MovableTradableComponent::~MovableTradableComponent
 */
MovableTradableComponent::~MovableTradableComponent(){}
