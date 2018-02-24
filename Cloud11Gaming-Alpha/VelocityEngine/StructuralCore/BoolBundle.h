#ifndef BOOLBUNDLE_H
#define BOOLBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The BoolBundle class
 */
class BoolBundle : public DataBundle{


private:

    std::vector<bool>* data;


public:

    BoolBundle();
    ~BoolBundle();

    void addBool(bool data);

    bool getBool(unsigned int index);
    unsigned int getSegmentCount();

    void removeAllData();


};

#endif // BOOLBUNDLE_H
