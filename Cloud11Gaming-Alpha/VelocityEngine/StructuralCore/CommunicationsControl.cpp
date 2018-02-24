#include "CommunicationsControl.h"

/**
 * @brief CommunicationsControl::CommunicationsControl
 */
CommunicationsControl::CommunicationsControl(){

    this->internalMsgQueue = new std::deque<DataBundle*>;
    this->incomingMsgQueue = new std::deque<DataBundle*>;
    this->outgoingMsgQueue = new std::deque<DataBundle*>;
}

/**
 * @brief CommunicationsControl::~CommunicationsControl
 */
CommunicationsControl::~CommunicationsControl(){

    this->removeAllInternalMsg();
    this->removeAllIncomingMsg();
    this->removeAllOutgoingMsg();

    delete this->internalMsgQueue;
    delete this->incomingMsgQueue;
    delete this->outgoingMsgQueue;

    this->internalMsgQueue = NULL;
    this->incomingMsgQueue = NULL;
    this->outgoingMsgQueue = NULL;
}

/**
 * @brief CommunicationsControl::enqueueInternalMsg
 * @param message
 */
void CommunicationsControl::enqueueInternalMsg(DataBundle* message){

    this->internalMsgQueue->push_back(message);
}

/**
 * @brief CommunicationsControl::enqueueIncomingMsg
 * @param message
 */
void CommunicationsControl::enqueueIncomingMsg(DataBundle* message){

    this->incomingMsgQueue->push_back(message);
}

/**
 * @brief CommunicationsControl::enqueueOutgoingMsg
 * @param message
 */
void CommunicationsControl::enqueueOutgoingMsg(DataBundle* message){

    this->outgoingMsgQueue->push_back(message);
}

/**
 * @brief CommunicationsControl::dequeueInternalMsg
 * @return
 */
DataBundle* CommunicationsControl::dequeueInternalMsg(){

    DataBundle* db = this->internalMsgQueue->front();
    this->internalMsgQueue->pop_front();
    return db;
}

/**
 * @brief CommunicationsControl::dequeueIncomingMsg
 * @return
 */
DataBundle* CommunicationsControl::dequeueIncomingMsg(){

    DataBundle* db = this->incomingMsgQueue->front();
    this->incomingMsgQueue->pop_front();
    return db;
}

/**
 * @brief CommunicationsControl::dequeueOutgoingMsg
 * @return
 */
DataBundle* CommunicationsControl::dequeueOutgoingMsg(){

    DataBundle* db = this->outgoingMsgQueue->front();
    this->outgoingMsgQueue->pop_front();
    return db;
}

/**
 * @brief CommunicationsControl::removeAllInternalMsg
 */
void CommunicationsControl::removeAllInternalMsg(){

    this->internalMsgQueue->clear();
}

/**
 * @brief CommunicationsControl::removeAllIncomingMsg
 */
void CommunicationsControl::removeAllIncomingMsg(){

    this->incomingMsgQueue->clear();
}

/**
 * @brief CommunicationsControl::removeAllOutgoingMsg
 */
void CommunicationsControl::removeAllOutgoingMsg(){

    this->outgoingMsgQueue->clear();
}
