#ifndef SCORETRACKER_H
#define SCORETRACKER_H

//Project
#include "PlayerScoreRecord.h"
#include "GroupScoreRecord.h"
#include <vector>


/**
 * @brief The ScoreTracker class
 */
class ScoreTracker: public Accessible{


public:

    std::vector<PlayerScoreRecord*>* playerScoreRecords;
    std::vector<GroupScoreRecord*>* groupScoreRecords;
    std::vector<ID*>* winners;
    std::vector<ID*>* winningGroups;

    ScoreTracker();
    ~ScoreTracker();

    void addPlayerScoreRecord(PlayerScoreRecord* playerScoreRecord);
    void addGroupScoreRecord(GroupScoreRecord* groupScoreRecord);

    PlayerScoreRecord* getPlayerScoreRecordAt(unsigned int index);
    PlayerScoreRecord* getPlayerScoreRecord(ID* playerID);
    GroupScoreRecord* getGroupPlayerRecordAt(unsigned int index);
    GroupScoreRecord* getGroupPlayerRecord(ID* groupID);
    unsigned int getWinnerCount();
    unsigned int getWinningGroupCount();
    ID* getWinner(unsigned int index);
    ID* getWinningGroup(unsigned int index);

    void removePlayerScoreRecord(ID* playerID);
    void removeGroupScoreRecord(ID* groupID);

    void removeAllPlayerScoreRecords();
    void removeAllGroupScoreRecords();
    void removeWinners();
    void removeWinningGroups();


};

#endif // SCORETRACKER_H
