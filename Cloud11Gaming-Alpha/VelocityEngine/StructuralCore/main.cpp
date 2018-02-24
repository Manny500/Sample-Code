#include <iostream>

#include "GameStructure.h"

/**
 * @brief main
 * @return
 */
int main()
{
    IntBundle* input = new IntBundle();
    input->addInt(99);

    std::cout << sizeof(input) << std::endl;

//    CommunicationsControl cnt = CommunicationsControl();
//    cnt.enqueueIncomingMsg(input);
//    DataBundle get;
//    get = cnt.dequeueIncomingMsg();


//    IntBundle* getptr = static_cast<IntBundle*>(&get);
//    std::cout << getptr->getSegmentCount() << std::endl;
//    std::cout << getptr->getInt(0) << std::endl;
//    IntBundle out = *getptr;
//    std::cout << out.getSegmentCount() << std::endl;
//    std::cout << out.getInt(0) << std::endl;

    DataBundle* d = input;

    std::cout << sizeof(d) << std::endl;

//    std::cout << d.getDataType() << std::endl;

    IntBundle* intp = static_cast<IntBundle*>(d);

//    std::cout << intp->getSegmentCount();

//    IntBundle in = *intp;

    std::cout << intp->getInt(0) << std::endl;
}

