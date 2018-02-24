#ifndef PLAYERGROUP_H
#define PLAYERGROUP_H

//Project
#include "Player.h"


/**
 * @brief The PlayerGroup class
 */
class PlayerGroup : public Accessible{


private:

    Type* type;
    std::vector<Player*>* players;


public:

    PlayerGroup();
    PlayerGroup(Type* type);
    ~PlayerGroup();

    void setType(Type* type);
    void setPlayers(std::vector<Player*>* players);
    void addPlayer(Player* player);

    Type* getType();
    unsigned int getPlayCount();
    std::vector<Player*>* getAllPlayers();
    Player* getPlayerAt(unsigned int index);
    Player* getPlayerOfSerialID(unsigned int serialID);
    Player* getPlayerOfAssignedID(int assignedID);
    std::vector<Player*>* getPlayersOfType(Type* type);
    Player* getPlayerFromTop();

    void removeType();
    void removeDeactivated();
    void removePlayerAt(unsigned int index);
    void removePlayerOfSerialID(unsigned int serialID);
    void removePlayerOfAssignedID(int assignedID);
    void removePlayersOfType(Type* type);
    void removeAllPlayers();


};

#endif // PLAYERGROUP_H
