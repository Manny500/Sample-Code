#ifndef COMMUNICATIONSCONTROL_H
#define COMMUNICATIONSCONTROL_H

//General
#include <deque>

//Project
#include "BoolBundle.h"
#include "CharBundle.h"
#include "IntBundle.h"
#include "LongBundle.h"
#include "DoubleBundle.h"
#include "PtrBundle.h"
#include "StringBundle.h"


/**
 * @brief The CommunicationsControl class
 */
class CommunicationsControl : public Accessible{


public:

    std::deque<DataBundle*>* internalMsgQueue;
    std::deque<DataBundle*>* incomingMsgQueue;
    std::deque<DataBundle*>* outgoingMsgQueue;

    CommunicationsControl();
    ~CommunicationsControl();

    void enqueueInternalMsg(DataBundle* message);
    void enqueueIncomingMsg(DataBundle* message);
    void enqueueOutgoingMsg(DataBundle* message);

    DataBundle* dequeueInternalMsg();
    DataBundle* dequeueIncomingMsg();
    DataBundle* dequeueOutgoingMsg();

    void removeAllInternalMsg();
    void removeAllIncomingMsg();
    void removeAllOutgoingMsg();


};

#endif // COMMUNICATIONSCONTROL_H
