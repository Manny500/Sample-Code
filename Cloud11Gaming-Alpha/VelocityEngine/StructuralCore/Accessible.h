#ifndef ACCESSIBLE_H
#define ACCESSIBLE_H

//General
#include <iostream>
#include <string>


/**
 * @brief The Accessible class
 */
class Accessible{


public:

    Accessible();
    ~Accessible();

    unsigned long long address();
    bool addressValid();


};

#endif // ACCESSIBLE_H
