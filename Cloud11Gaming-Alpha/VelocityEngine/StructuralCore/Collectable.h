#ifndef COLLECTABLE_H
#define COLLECTABLE_H

//Project
#include "ID.h"


/**
 * @brief The Collectable class
 */
class Collectable: public Accessible{


protected:

    ID* ownerID;

    Collectable();
    ~Collectable();


public:

    void setOwnerID(ID* ownerID);

    ID* getOwnerID();
    unsigned int getOwnerSerialID();
    int getOwnerAssignedID();


};

#endif // COLLECTABLE_H

