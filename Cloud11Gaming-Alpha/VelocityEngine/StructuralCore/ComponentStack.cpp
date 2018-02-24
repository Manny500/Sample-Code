#include "ComponentStack.h"

/**
 * @brief ComponentStack::ComponentStack
 */
ComponentStack::ComponentStack(){

    this->type = new Type();
    this->components = new std::vector<Component*>;
}

/**
 * @brief ComponentStack::ComponentStack
 * @param type
 */
ComponentStack::ComponentStack(Type* type){

    this->type = type;
    this->components = new std::vector<Component*>;
}

/**
 * @brief ComponentStack::~ComponentStack
 */
ComponentStack::~ComponentStack(){

    removeAllComponents();

    delete this->components;
    this->components = NULL;
}

/**
 * @brief ComponentStack::setComponentStackType
 * @param type
 */
void ComponentStack::setComponentStackType(Type* type){

    this->type = type;
}

/**
 * @brief ComponentStack::setAllComponents
 * @param components
 */
void ComponentStack::setAllComponents(std::vector<Component*>* components){

    this->components = components;
}

/**
 * @brief ComponentStack::addComponent
 * @param component
 */
void ComponentStack::addComponent(Component* component){

    this->components->push_back(component);
}

/**
 * @brief ComponentStack::randomizeOrder
 * @param iteration
 */
void ComponentStack::randomizeOrder(unsigned int iteration){

    unsigned int size = components->size();

    for (unsigned int r = 0; r < iteration; r ++){
        for (unsigned int i = 0; i < size; i ++){

            int swap = rndm::rndInc((unsigned)0, size - 1);
            Component* temp = components->at(swap);
            components->at(swap) =  components->at(i);
            components->at(i) = temp;

        }
    }
}

/**
 * @brief ComponentStack::sortBySerialID
 */
void ComponentStack::sortBySerialID(){}

/**
 * @brief ComponentStack::sortByAssignedID
 */
void ComponentStack::sortByAssignedID(){}

/**
 * @brief ComponentStack::sortByTypeLabel
 */
void ComponentStack::sortByTypeLabel(){}

/**
 * @brief ComponentStack::sortByAttributeValue
 */
void ComponentStack::sortByAttributeValue(){}

/**
 * @brief ComponentStack::getType
 * @return
 */
Type* ComponentStack::getType(){

    return this->type;
}

/**
 * @brief ComponentStack::getComponentCount
 * @return
 */
unsigned int ComponentStack::getComponentCount(){

    return this->components->size();
}

/**
 * @brief ComponentStack::getAllComponents
 * @return
 */
std::vector<Component*>* ComponentStack::getAllComponents(){

    return this->components;
}

/**
 * @brief ComponentStack::getComponentsOfType
 * @param type
 * @return
 */
std::vector<Component*>* ComponentStack::getComponentsOfType(Type* type){

    std::vector<Component*>* componentsOfType = new std::vector<Component*>;

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getType() == type)
            componentsOfType->push_back(cmpt);
    }

    return componentsOfType;
}

/**
 * @brief ComponentStack::getComponentAt
 * @param index
 * @return
 */
Component* ComponentStack::getComponentAt(unsigned int index){

    if (index > this->components->size() - 1) return NULL;

    return this->components->at(index);
}

/**
 * @brief ComponentStack::getComponentOfSerialID
 * @param serialID
 * @return
 */
Component* ComponentStack::getComponentOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getID()->getSerialID() == serialID)
            return cmpt;
    }

    return NULL;
}

/**
 * @brief ComponentStack::getComponentOfAssignedID
 * @param assignedID
 * @return
 */
Component* ComponentStack::getComponentOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getID()->getAssignedID() == assignedID)
            return cmpt;
    }

    return NULL;
}

/**
 * @brief ComponentStack::getComponentFromTop
 * @return
 */
Component* ComponentStack::getComponentFromTop(){

    if (this->components->empty()) return NULL;

    return this->components->back();
}

/**
 * @brief ComponentStack::retrieveComponentsOfType
 * @param type
 * @return
 */
std::vector<Component*>* ComponentStack::retrieveComponentsOfType(Type* type){

    std::vector<Component*>* componentsOfType = new std::vector<Component*>;

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getType() == type){
            componentsOfType->push_back(cmpt);
            this->components->erase(this->components->begin()+i);
            i --;
        }
    }

    return componentsOfType;
}

/**
 * @brief ComponentStack::retrieveComponentAt
 * @param index
 * @return
 */
Component* ComponentStack::retrieveComponentAt(unsigned int index){

    if (index > this->components->size() - 1) return NULL;

    Component* cmpt = this->components->at(index);
    this->components->erase(this->components->begin()+index);
    return cmpt;
}

/**
 * @brief ComponentStack::retrieveComponentOfSerialID
 * @param serialID
 * @return
 */
Component* ComponentStack::retrieveComponentOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getID()->getSerialID() == serialID){
            this->components->erase(this->components->begin()+i);
            return cmpt;
        }
    }

    return NULL;
}

/**
 * @brief ComponentStack::retrieveComponentOfAssignedID
 * @param assignedID
 * @return
 */
Component* ComponentStack::retrieveComponentOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getID()->getAssignedID() == assignedID){
            this->components->erase(this->components->begin()+i);
            return cmpt;
        }
    }

    return NULL;
}

/**
 * @brief ComponentStack::retrieveComponentFromTop
 * @return
 */
Component* ComponentStack::retrieveComponentFromTop(){

    if (this->components->empty()) return NULL;

    Component* cmpt = this->components->back();
    this->components->pop_back();
    return cmpt;
}

/**
 * @brief ComponentStack::isEmpty
 * @return
 */
bool ComponentStack::isEmpty(){

    if (this->components->size() == 0) return true;
    else return false;
}

/**
 * @brief ComponentStack::removeDeactivated
 */
void ComponentStack::removeDeactivated(){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->isDeactivated()){
            delete cmpt;
            this->components->erase(this->components->begin()+i);
            i --;
        }
    }
}

/**
 * @brief ComponentStack::removeComponentFromTop
 */
void ComponentStack::removeComponentFromTop(){

    removeComponentAt(this->components->size() - 1);
}

/**
 * @brief ComponentStack::removeComponentAt
 * @param index
 */
void ComponentStack::removeComponentAt(unsigned int index){

    if (index < this->components->size()){
        delete this->components->at(index);
        this->components->erase(this->components->begin()+index);
    }
}

/**
 * @brief ComponentStack::removeComponentOfSerialID
 * @param serialID
 */
void ComponentStack::removeComponentOfSerialID(unsigned int serialID){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getID()->getSerialID() == serialID){
            delete cmpt;
            this->components->erase(this->components->begin()+i);
            break;
        }
    }
}

/**
 * @brief ComponentStack::removeComponentOfAssignedID
 * @param assignedID
 */
void ComponentStack::removeComponentOfAssignedID(int assignedID){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getID()->getAssignedID() == assignedID){
            delete cmpt;
            this->components->erase(this->components->begin()+i);
            break;
        }
    }
}

/**
 * @brief ComponentStack::removeComponentsOfType
 * @param type
 */
void ComponentStack::removeComponentsOfType(Type* type){

    for (unsigned int i = 0; i < this->components->size(); i++){
        Component* cmpt =  this->components->at(i);
        if (cmpt->getType() == type){
            delete cmpt;
            this->components->erase(this->components->begin()+i);
            i --;
        }
    }
}

/**
 * @brief ComponentStack::removeAllComponents
 */
void ComponentStack::removeAllComponents(){

    for (unsigned int i = 0; i < this->components->size(); i++)
        delete this->components->at(i);

    this->components->clear();
}

