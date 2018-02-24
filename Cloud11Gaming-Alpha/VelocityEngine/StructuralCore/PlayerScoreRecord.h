#ifndef PLAYERSCORERECORD_H
#define PLAYERSCORERECORD_H

//Project
#include "ID.h"


/**
 * @brief The PlayerScoreRecord class
 */
class PlayerScoreRecord : public Accessible{


private:

    ID* playerID;
    double score;
    int altScore1;
    int altScore2;


public:

    PlayerScoreRecord();
    PlayerScoreRecord(ID* playerID);
    PlayerScoreRecord(ID* playerID, double score);
    PlayerScoreRecord(ID* playerID, int altScore1);
    PlayerScoreRecord(ID* playerID, int altScore1, int altScore2);
    PlayerScoreRecord(ID* playerID, double score, int altScore1, int altScore2);
    ~PlayerScoreRecord();

    void setPlayerID(ID* playerID);
    void setScore(double score);
    void setAltScore1(int altScore1);
    void setAltScore2(int altScore2);
    void addToScore(double update);
    void addToAltScore1(int update);
    void addToAltScore2(int update);

    ID* getPlayerID();
    double getScore();
    int getAltScore1();
    int getAltScore2();


};

#endif // PLAYERSCORERECORD_H
