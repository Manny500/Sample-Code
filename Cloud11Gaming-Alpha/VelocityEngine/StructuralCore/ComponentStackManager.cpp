#include "ComponentStackManager.h"

/**
 * @brief ComponentStackManager::ComponentStackManager
 */
ComponentStackManager::ComponentStackManager(){

    this->componentStacks = new std::vector<ComponentStack*>;
}

/**
 * @brief ComponentStackManager::~ComponentStackManager
 */
ComponentStackManager::~ComponentStackManager(){

    removeAllComponentStacks();

    delete this->componentStacks;
    this->componentStacks = NULL;
}

/**
 * @brief ComponentStackManager::addComponentStack
 * @param componentStack
 */
void ComponentStackManager::addComponentStack(ComponentStack* componentStack){

    this->componentStacks->push_back(componentStack);
}

/**
 * @brief ComponentStackManager::getComponentStackAt
 * @param index
 * @return
 */
ComponentStack* ComponentStackManager::getComponentStackAt(unsigned int index){

    return this->componentStacks->at(index);
}

/**
 * @brief ComponentStackManager::getComponentStacksOfType
 * @param type
 * @return
 */
std::vector<ComponentStack*>* ComponentStackManager::getComponentStacksOfType(Type* type){

    std::vector<ComponentStack*>* stacksOfType = new std::vector<ComponentStack*>;

    for (unsigned int i = 0; i < this->componentStacks->size(); i++){
        ComponentStack* stack =  this->componentStacks->at(i);
        if (stack->getType() == type)
            stacksOfType->push_back(stack);
    }

    return stacksOfType;
}

/**
 * @brief ComponentStackManager::removeComponentStackAt
 * @param index
 */
void ComponentStackManager::removeComponentStackAt(unsigned int index){

    delete this->componentStacks->at(index);
    this->componentStacks->erase(this->componentStacks->begin()+index);
}

/**
 * @brief ComponentStackManager::removeComponentStacksOfType
 * @param type
 */
void ComponentStackManager::removeComponentStacksOfType(Type* type){

    for (unsigned int i = 0; i < this->componentStacks->size(); i++){
        ComponentStack* stack =  this->componentStacks->at(i);
        if (stack->getType() == type){
            delete stack;
            this->componentStacks->erase(this->componentStacks->begin()+i);
            i --;
        }
    }
}

/**
 * @brief ComponentStackManager::removeAllComponentStacks
 */
void ComponentStackManager::removeAllComponentStacks(){

    for (unsigned int i = 0; i < this->componentStacks->size(); i++)
        delete this->componentStacks->at(i);

    this->componentStacks->clear();
}
