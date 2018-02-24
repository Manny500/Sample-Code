#ifndef PLAYER_H
#define PLAYER_H

//Project
#include "PlayerScoreRecord.h"
#include "ComponentStackManager.h"


/**
 * @brief The Player class
 */
class Player : public Component{


protected:

    std::string name;
    ID* groupID;
    int won;
    int lost;
    PlayerScoreRecord* scoreRecord;
    ComponentStackManager* collected;


public:

    Player();
    Player(ID* id);
    Player(unsigned int serialID);
    Player(unsigned int serialID, int assignedID);
    Player(ID* id, Type* type);
    Player(unsigned int serialID, int assignedID, Type* type);
    ~Player();

    void setName(std::string name);
    void setGroupID(ID* groupID);
    void setWon();
    void setLost();
    void setScoreRecord(PlayerScoreRecord* scoreRecord);
    void setCollected(ComponentStackManager* collected);

    std::string getName();
    ID* getGroupID();
    int hasWon();
    int hasLost();
    PlayerScoreRecord* getScoreRecord();
    ComponentStackManager* getCollected();

    void removeGroupID();
    void removeScoreRecord();
    void removeCollected();


};

#endif // PLAYER_H
