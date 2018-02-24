#include "PhysicalSpace.h"

/**
 * @brief PhysicalSpace::PhysicalSpace
 */
PhysicalSpace::PhysicalSpace(){

    this->label = 0;
    this->name = "";
    this->xOffset = 0;
    this->yOffset = 0;
    this->zOffset = 0;
}

/**
 * @brief PhysicalSpace::PhysicalSpace
 * @param label
 * @param name
 */
PhysicalSpace::PhysicalSpace(int label, std::string name){

    this->label = label;
    this->name = name;
    this->xOffset = 0;
    this->yOffset = 0;
    this->zOffset = 0;
}

/**
 * @brief PhysicalSpace::~PhysicalSpace
 */
PhysicalSpace::~PhysicalSpace(){

    if (this->locations[0][0][0] != NULL)
        removeAllLocations();

    if (this->locations != NULL){
        for (unsigned int i = 0; i < zRange; i ++){
            for (unsigned int k = 0; k < yRange; k ++){
                delete [] locations[i][k];
            }
            delete [] locations[i];
        }
        delete [] locations;

        this->locations = NULL;
    }
}

/**
 * @brief PhysicalSpace::defineSpace
 * @param formation
 * @param layout
 * @param xRange
 * @param yRange
 * @param zRange
 */
void PhysicalSpace::defineSpace(int formation, int layout, unsigned int xRange, unsigned int yRange, unsigned int zRange){

    this->formation = formation;
    this->layout = layout;
    this->xRange = xRange;
    this->yRange = yRange;
    this->zRange = zRange;

    locations = new Location***[zRange];
    for (unsigned int i = 0; i < zRange; i ++){
        locations[i] = new Location**[yRange];
        for (unsigned int k = 0; k < yRange; k ++){
            locations[i][k] = new Location*[xRange];
        }
    }

    autoAssignLocations();
}

/**
 * @brief PhysicalSpace::offsetOrigin
 * @param xOffset
 * @param yOffset
 * @param zOffset
 */
void PhysicalSpace::offsetOrigin(int xOffset, int yOffset, int zOffset){

    this->xOffset = xOffset;
    this->yOffset = yOffset;
    this->zOffset = zOffset;
}

/**
 * @brief PhysicalSpace::autoAssignLocations
 */
void PhysicalSpace::autoAssignLocations(){

    for (unsigned int i = 0; i < zRange; i ++){
        for (unsigned int k = 0; k < yRange; k ++){
            for (unsigned int m = 0; m < xRange; m ++){
                locations[i][k][m] = new Location(m, k, i, this->label);
            }
        }
    }
}

/**
 * @brief PhysicalSpace::autoAssignLocations
 * @param type
 */
void PhysicalSpace::autoAssignLocations(Type* type){

    for (unsigned int i = 0; i < zRange; i ++){
        for (unsigned int k = 0; k < yRange; k ++){
            for (unsigned int m = 0; m < xRange; m ++){
                delete locations[i][k][m];
                locations[i][k][m] = new Location(m, k, i, this->label, type);
            }
        }
    }
}

/**
 * @brief PhysicalSpace::assignLocation
 * @param x
 * @param y
 * @param z
 * @param type
 */
void PhysicalSpace::assignLocation(int x, int y, int z, Type* type){

    removeLocation(x, y, z);
    this->locations[z+zOffset][y+yOffset][x+xOffset] = new Location(x, y, z, this->label, type);
}


/**
 * @brief PhysicalSpace::assignLocation
 * @param x
 * @param y
 * @param z
 * @param location
 */
void  PhysicalSpace::assignLocation(int x, int y, int z, Location* location){

    removeLocation(x, y, z);
    this->locations[z+zOffset][y+yOffset][x+xOffset] = location;
}


/**
 * @brief PhysicalSpace::getLabel
 * @return
 */
int PhysicalSpace::getLabel(){

    return this->label;
}


/**
 * @brief PhysicalSpace::getName
 * @return
 */
std::string PhysicalSpace::getName(){

    return this->name;
}


/**
 * @brief PhysicalSpace::getFormation
 * @return
 */
int PhysicalSpace::getFormation(){

    return this->formation;
}


/**
 * @brief PhysicalSpace::getLayout
 * @return
 */
int PhysicalSpace::getLayout(){

    return this->layout;
}

/**
 * @brief PhysicalSpace::getXRange
 * @return
 */
unsigned int PhysicalSpace::getXRange(){

    return this->xRange;
}

/**
 * @brief PhysicalSpace::getYRange
 * @return
 */
unsigned int PhysicalSpace::getYRange(){

    return this->yRange;
}

/**
 * @brief PhysicalSpace::getZRange
 * @return
 */
unsigned int PhysicalSpace::getZRange(){

    return this->zRange;
}

/**
 * @brief PhysicalSpace::getXOffset
 * @return
 */
int PhysicalSpace::getXOffset(){

    return this->xOffset;
}

/**
 * @brief PhysicalSpace::getYOffset
 * @return
 */
int PhysicalSpace::getYOffset(){

    return this->yOffset;
}

/**
 * @brief PhysicalSpace::getZOffset
 * @return
 */
int PhysicalSpace::getZOffset(){

    return this->zOffset;
}

/**
 * @brief PhysicalSpace::getLocation
 * @param x
 * @param y
 * @param z
 * @return
 */
Location* PhysicalSpace::getLocation(int x, int y, int z){

    return this->locations[z+zOffset][y+yOffset][x+xOffset];
}

/**
 * @brief PhysicalSpace::removeLocation
 * @param x
 * @param y
 * @param z
 */
void PhysicalSpace::removeLocation(int x, int y, int z){

    if (this->locations[z+zOffset][y+yOffset][x+xOffset] != NULL){
        delete this->locations[z+zOffset][y+yOffset][x+xOffset];
        this->locations[z+zOffset][y+yOffset][x+xOffset] = NULL;
    }
}

/**
 * @brief PhysicalSpace::removeAllLocations
 */
void PhysicalSpace::removeAllLocations(){

    for (unsigned int i = 0; i < zRange; i++){
        for (unsigned int k = 0; k < yRange; k++){
            for (unsigned int m = 0; m < xRange; m++){

                if (this->locations[i][k][m] != NULL){
                    delete this->locations[i][k][m];
                    this->locations[i][k][m] = NULL;
                }
            }
        }
    }
}
