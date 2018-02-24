#ifndef STRINGBUNDLE_H
#define STRINGBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The StringBundle class
 */
class StringBundle : public DataBundle{


private:

    std::vector<std::string>* data;


public:

    StringBundle();
    ~StringBundle();

    std::string getString(unsigned int index);

    void addString(std::string data);
    unsigned int getSegmentCount();

    void removeAllData();


};

#endif // STRINGBUNDLE_H
