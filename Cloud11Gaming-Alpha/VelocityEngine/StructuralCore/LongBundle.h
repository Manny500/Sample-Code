#ifndef LONGBUNDLE_H
#define LONGBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The LongBundle class
 */
class LongBundle : public DataBundle{


private:

    std::vector<long>* data;


public:

    LongBundle();
    ~LongBundle();

    void addLong(long data);

    long getLong(unsigned int index);
    unsigned int getSegmentCount();

    void removeAllData();


};

#endif // LONGBUNDLE_H
