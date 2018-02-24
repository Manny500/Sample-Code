#ifndef INTBUNDLE_H
#define INTBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The IntBundle class
 */
class IntBundle : public DataBundle{


private:

    std::vector<int>* data;


public:

    IntBundle();
    ~IntBundle();

    void addInt(int data);

    int getInt(unsigned int index);
    unsigned int getSegmentCount();

    void removeAllData();


};

#endif // INTBUNDLE_H
