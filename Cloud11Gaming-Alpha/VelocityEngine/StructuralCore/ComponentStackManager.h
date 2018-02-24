#ifndef COMPONENTSTACKMANAGER_H
#define COMPONENTSTACKMANAGER_H

//Project
#include "ComponentStack.h"


/**
 * @brief The ComponentStackManager class
 */
class ComponentStackManager : public Accessible{


public:

    std::vector<ComponentStack*>* componentStacks;

    ComponentStackManager();
    ~ComponentStackManager();

    void addComponentStack(ComponentStack* componentStack);

    ComponentStack* getComponentStackAt(unsigned int index);
    std::vector<ComponentStack*>* getComponentStacksOfType(Type* type);

    void removeComponentStackAt(unsigned int index);
    void removeComponentStacksOfType(Type* type);
    void removeAllComponentStacks();


};

#endif // COMPONENTSTACKMANAGER_H
