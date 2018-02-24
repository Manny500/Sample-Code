#ifndef Crazy_H
#define Crazy_H

// Project
#include "../../../VelocityEngine/LogicalCore/GameLogic.h"
#include "../../../VelocityEngine/StructuralCore/GameStructure.h"

// Basic
#include <iostream>
#include <sstream>

class Crazy : public GameStructure, public GameLogic{


public:

    int extraDraw;
    int suitChange;
    int skipNext;
    int faceSuit;
    int faceValue;
    int massDrop;
    int illegal;
    int equalSuit;
    int equalValue;
    int drawAndSkip;

    Crazy();
    ~Crazy();

    ComponentStack* deck;
    ComponentStack* discard;
    Player* currentPlayer;
    ComponentStack* currentHand;

    void staticSettings();
    void startCommunication();
    void dynamicSettings();
    void startProgress();
    void buildGlossary();
    void buildPlayerGroups();
    void buildComponentStacks();
    void buildPhysicalSpaces();
    void linkScoreTracker();


    void stage();
    void round();
    void turn();
    void move();
    void updateScores();
    void clearDeactivated();

    void input();
    void output();

    void cleanUp();
    void endGame();

    std::string enforcer();
    void defenseChecker(Player* player, Component* card);
    void defenseCounter();
    void draw(int amount);
    std::vector<unsigned int>* getAllOf(int suit, int value);
    void checkWin();

    void print(std::string message, int i);
    void printCc(Component* card);
    void print(int i);
    void printStack(ComponentStack* stack);
    void printStack(std::vector<unsigned int>* printed);
    void print(int printed, int xxx);
    void shuffle();

    /* Following methods should be called in order by Server.
     * Methods that marked with #U are requested by user.
     * Methods without special marks are requested by server. */

    /* Builds the game. */
    void initiate(int playerCount);

    /* Gives assignedID and name to player identified by their index in storage. */
    void setPlayerID(int assignedID, std::string name, unsigned int index);

    /* Starts. */
    void startGame();

    /* Returns storage index of the player whose turn it is. */
    unsigned int getPlayerOfThisTurn();

    /* Checks the situation before the next player's turn and returns a descriptive message. */
    std::string startTurn(unsigned int playerIndex);

    /* Returns the ComponentStack that is the hand of the current player. */
    ComponentStack* reportHand();

    /* #U */
    std::string drop(unsigned int dropChoice);
    /* #U */
    void statusPrinter();

    void changeSuit(int choice);

    bool defendable();

    std::string massDropper(unsigned int suitChoice);

    void massDropper();

    std::string attackResponse();

    std::vector<unsigned int>* attackResponse(bool defend);

    std::string exDraw();

    /* Skip */
    void skipSelf();

    void endTurn();

    void printHand();

    /* Checks if there is a winner. Returns 1 when there is, 0 when there is not. */
    int foundWinner();

};

#endif // Crazy_H
