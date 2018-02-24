#ifndef GROUPSCORERECORD_H
#define GROUPSCORERECORD_H

//Project
#include "ID.h"


/**
 * @brief The GroupScoreRecord class
 */
class GroupScoreRecord : public Accessible{


private:

    ID* groupID;
    double score;
    int altScore1;
    int altScore2;


public:

    GroupScoreRecord();
    GroupScoreRecord(ID* groupID);
    GroupScoreRecord(ID* groupID, double score);
    GroupScoreRecord(ID* groupID, int altScore1);
    GroupScoreRecord(ID* groupID, int altScore1, int altScore2);
    GroupScoreRecord(ID* groupID, double score, int altScore1, int altScore2);
    ~GroupScoreRecord();

    void setGroupID(ID* groupID);
    void setScore(double score);
    void setAltScore1(int altScore1);
    void setAltScore2(int altScore2);
    void addToScore(double update);
    void addToAltScore1(int update);
    void addToAltScore2(int update);

    ID* getGroupID();
    double getScore();
    int getAltScore1();
    int getAltScore2();


};

#endif // GROUPSCORERECORD_H
