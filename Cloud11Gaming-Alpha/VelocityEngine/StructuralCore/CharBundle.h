#ifndef CHARBUNDLE_H
#define CHARBUNDLE_H

//Project
#include "DataBundle.h"


/**
 * @brief The CharBundle class
 */
class CharBundle : public DataBundle{


private:

    std::vector<char>* data;


public:

    CharBundle();
    ~CharBundle();

    void addChar(char data);

    char getChar(unsigned int index);
    unsigned int getSegmentCount();

    void removeAllData();


};

#endif // CHARBUNDLE_H
