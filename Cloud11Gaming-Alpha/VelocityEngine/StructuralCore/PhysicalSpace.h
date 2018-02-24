#ifndef PHYSICALSPACE_H
#define PHYSICALSPACE_H

//Project
#include "Location.h"


/**
 * @brief The PhysicalSpace class
 */
class PhysicalSpace : public Accessible{


private:

    int label;
    std::string name;
    int formation;
    int layout;
    unsigned int xRange;
    unsigned int yRange;
    unsigned int zRange;
    int xOffset;
    int yOffset;
    int zOffset;
    Location**** locations;


public:

    PhysicalSpace();
    PhysicalSpace(int label, std::string name);
    ~PhysicalSpace();

    void defineSpace(int formation, int layout, unsigned int xRange, unsigned int yRange, unsigned int zRange);
    void offsetOrigin(int xOffset, int yOffset, int zOffset);
    void autoAssignLocations();
    void autoAssignLocations(Type* type);
    void assignLocation(int x, int y, int z, Type* type);
    void assignLocation(int x, int y, int z, Location* location);

    int getLabel();
    std::string getName();
    int getFormation();
    int getLayout();
    unsigned int getXRange();
    unsigned int getYRange();
    unsigned int getZRange();
    int getXOffset();
    int getYOffset();
    int getZOffset();
    Location* getLocation(int x, int y, int z);

    void removeLocation(int x, int y, int z);
    void removeAllLocations();


};

#endif // PHYSICALSPACE_H

