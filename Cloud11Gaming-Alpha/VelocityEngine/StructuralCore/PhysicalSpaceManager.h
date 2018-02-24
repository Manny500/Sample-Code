#ifndef PHYSICALSPACEMANAGER_H
#define PHYSICALSPACEMANAGER_H

//Project
#include "PhysicalSpace.h"


/**
 * @brief The PhysicalSpaceManager class
 */
class PhysicalSpaceManager : public Accessible{


public:

    PhysicalSpaceManager();
    ~PhysicalSpaceManager();

    std::vector<PhysicalSpace*>* physicalSpaces;

    void addPhysicalSpace(PhysicalSpace* physicalSpace);

    PhysicalSpace* getPhysicalSpaceAt(unsigned int index);
    PhysicalSpace* getPhysicalSpace(int label);
    PhysicalSpace* getPhysicalSpace(std::string name);

    void removePhysicalSpaceAt(unsigned int index);
    void removePhysicalSpace(int label);
    void removePhysicalSpace(std::string name);
    void removeAllPhysicalSpaces();


};

#endif // PHYSICALSPACEMANAGER_H

