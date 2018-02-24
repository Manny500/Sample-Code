#ifndef COORDINATES_H
#define COORDINATES_H

//Project
#include "Accessible.h"


/**
 * @brief The Coordinates class
 */
class Coordinates : public Accessible{


private:

    int x;
    int y;
    int z;
    int s;


public:

    Coordinates();
    Coordinates(int x, int y, int z, int s);
    ~Coordinates();

    void setX(int x);
    void setY(int y);
    void setZ(int z);
    void setS(int s);

    int getX();
    int getY();
    int getZ();
    int getS();


};

#endif // COORDINATES_H

