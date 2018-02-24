#include "Accessible.h"


Accessible::Accessible(){}


Accessible::~Accessible(){}

/**
 * @brief Accessible::address will reinterpret_cast an adress
 * @return is the reinterpreted adress
 */
unsigned long long Accessible::address(){

    return reinterpret_cast<unsigned long long>(this);
}

/**
 * @brief Accessible::addressValid will say if an adress is valid
 * @return bool if the adress is valid
 */
bool Accessible::addressValid(){

    if (address() != 0) return true;
    else return false;
}
