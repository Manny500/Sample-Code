#ifndef ID_H
#define ID_H

//Project
#include "Accessible.h"


/**
 * @brief The ID class
 */
class ID : public Accessible{


private:

    unsigned int serialID;
    int assignedID;


public:

    ID();
    ID(unsigned int serialID);
    ID(unsigned int serialID, int assignedID);
    ~ID();

    void setSerialID(unsigned int serialID);
    void setAssignedID(int assignedID);

    unsigned int getSerialID();
    int getAssignedID();  


};

#endif // ID_H

