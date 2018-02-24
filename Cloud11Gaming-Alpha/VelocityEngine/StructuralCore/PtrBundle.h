#ifndef PTRBUNDLE_H
#define PTRBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The PtrBundle class
 */
class PtrBundle : public DataBundle{


private:

    std::vector<unsigned long long>* data;


public:

    PtrBundle();
    ~PtrBundle();

    void addPtr(unsigned long long data);

    unsigned long long getPtr(unsigned int index);
    unsigned int getSegmentCount();

    void removeAllData();


};

#endif // PTRBUNDLE_H
