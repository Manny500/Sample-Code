#include "Coordinates.h"

/**
 * @brief Coordinates::Coordinates
 */
Coordinates::Coordinates(){}

/**
 * @brief Coordinates::Coordinates
 * @param x
 * @param y
 * @param z
 * @param s
 */
Coordinates::Coordinates(int x, int y, int z, int s){

    this->x = x;
    this->y = y;
    this->z = z;
    this->s = s;
}

/**
 * @brief Coordinates::~Coordinates
 */
Coordinates::~Coordinates(){}

/**
 * @brief Coordinates::setX
 * @param x
 */
void Coordinates::setX(int x){
    this->x = x;
}

/**
 * @brief Coordinates::setY
 * @param y
 */
void Coordinates::setY(int y){
    this->y = y;
}

/**
 * @brief Coordinates::setZ
 * @param z
 */
void Coordinates::setZ(int z){
    this->z = z;
}

/**
 * @brief Coordinates::setS
 * @param x
 */
void Coordinates::setS(int x){
    this->s = x;
}

/**
 * @brief Coordinates::getX
 * @return
 */
int Coordinates::getX(){

    return this->x;
}

/**
 * @brief Coordinates::getY
 * @return
 */
int Coordinates::getY(){

    return this->y;
}

/**
 * @brief Coordinates::getZ
 * @return
 */
int Coordinates::getZ(){

    return this->z;
}

/**
 * @brief Coordinates::getS
 * @return
 */
int Coordinates::getS(){

    return this->s;
}



