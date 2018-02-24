#ifndef DOUBLEBUNDLE_H
#define DOUBLEBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The DoubleBundle class
 */
class DoubleBundle : public DataBundle{


private:

    std::vector<double>* data;


public:

    DoubleBundle();
    ~DoubleBundle();

    void addDouble(double data);

    double getDouble(unsigned int index);
        unsigned int getSegmentCount();

    void removeAllData();


};

#endif // DOUBLEBUNDLE_H
