#include "LocatableComponent.h"

/**
 * @brief LocatableComponent::LocatableComponent
 */
LocatableComponent::LocatableComponent(){}

/**
 * @brief LocatableComponent::LocatableComponent
 * @param id
 */
LocatableComponent::LocatableComponent(ID* id)
    : Component(id){}

/**
 * @brief LocatableComponent::LocatableComponent
 * @param serialID
 */
LocatableComponent::LocatableComponent(unsigned int serialID)
    : Component(serialID){}

/**
 * @brief LocatableComponent::LocatableComponent
 * @param serialID
 * @param assignedID
 */
LocatableComponent::LocatableComponent(unsigned int serialID, int assignedID)
    : Component(serialID, assignedID){}

/**
 * @brief LocatableComponent::LocatableComponent
 * @param type
 */
LocatableComponent::LocatableComponent(Type* type)
    : Component(type){}

/**
 * @brief LocatableComponent::LocatableComponent
 * @param id
 * @param type
 */
LocatableComponent::LocatableComponent(ID* id, Type* type)
    : Component(id, type){}

/**
 * @brief LocatableComponent::LocatableComponent
 * @param serialID
 * @param assignedID
 * @param type
 */
LocatableComponent::LocatableComponent(unsigned int serialID, int assignedID, Type* type)
    : Component(serialID, assignedID, type){}

/**
 * @brief LocatableComponent::~LocatableComponent
 */
LocatableComponent::~LocatableComponent(){

    this->coordinates = NULL;
}

/**
 * @brief LocatableComponent::setCoordinates
 * @param coordinates
 */
void LocatableComponent::setCoordinates(Coordinates* coordinates){

    this->coordinates = coordinates;
}

/**
 * @brief LocatableComponent::setCoordinates
 * @param x
 * @param y
 * @param z
 * @param s
 */
void LocatableComponent::setCoordinates(int x, int y, int z, int s){

    this->coordinates = new Coordinates(x, y, z, s);
}

/**
 * @brief LocatableComponent::setX
 * @param x
 */
void LocatableComponent::setX(int x){

    this->coordinates->setX(x);
}

/**
 * @brief LocatableComponent::setY
 * @param y
 */
void LocatableComponent::setY(int y){

    this->coordinates->setY(y);
}

/**
 * @brief LocatableComponent::setZ
 * @param z
 */
void LocatableComponent::setZ(int z){

    this->coordinates->setZ(z);
}

/**
 * @brief LocatableComponent::setS
 * @param s
 */
void LocatableComponent::setS(int s){

    this->coordinates->setS(s);
}

/**
 * @brief LocatableComponent::getCoordinates
 * @return
 */
Coordinates* LocatableComponent::getCoordinates(){

    return this->coordinates;
}

/**
 * @brief LocatableComponent::getX
 * @return
 */
int LocatableComponent::getX(){

    return this->coordinates->getX();
}

/**
 * @brief LocatableComponent::getY
 * @return
 */
int LocatableComponent::getY(){

    return this->coordinates->getY();
}

/**
 * @brief LocatableComponent::getZ
 * @return
 */
int LocatableComponent::getZ(){

    return this->coordinates->getZ();
}

/**
 * @brief LocatableComponent::getS
 * @return
 */
int LocatableComponent::getS(){

    return this->coordinates->getS();
}
