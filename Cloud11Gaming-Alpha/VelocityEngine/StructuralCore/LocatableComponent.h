#ifndef LOCATABLECOMPONENT_H
#define LOCATABLECOMPONENT_H

//Project
#include "Coordinates.h"
#include "Component.h"


/**
 * @brief The LocatableComponent class
 */
class LocatableComponent : public Component{


private:

    Coordinates* coordinates;


public:

    LocatableComponent();
    LocatableComponent(ID* id);
    LocatableComponent(unsigned int serialID);
    LocatableComponent(unsigned int serialID, int assignedID);
    LocatableComponent(Type* type);
    LocatableComponent(ID* id, Type* type);
    LocatableComponent(unsigned int serialID, int assignedID, Type* type);
    ~LocatableComponent();

    void setCoordinates(Coordinates* coordinates);
    void setCoordinates(int x, int y, int z, int s);
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    void setS(int s);

    Coordinates* getCoordinates();
    int getX();
    int getY();
    int getZ();
    int getS();


};

#endif // LOCATABLECOMPONENT_H
