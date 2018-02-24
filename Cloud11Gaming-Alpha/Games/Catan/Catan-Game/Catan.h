#ifndef CATAN_H
#define CATAN_H

// General
#include <sstream>

// Project
#include "../../../VelocityEngine/LogicalCore/GameLogic.h"
#include "../../../VelocityEngine/StructuralCore/GameStructure.h"
#include "../../../VelocityEngine/MathLibraries/Hexagon2D.h"
#include "../../../VelocityEngine/MathLibraries/Randomizer.h"


class Catan : public GameStructure, public GameLogic{


private:



public:

     Catan();
    ~Catan();

    void staticSettings();
    void startCommunication();
    void dynamicSettings();
    void startProgress();
    void buildGlossary();
    void buildPlayerGroups();
    void buildComponentStacks();
    void buildPhysicalSpaces();

    void startGame();
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


    /* Incoming */


    /**
     * @brief setActualPlayers sets the actual number of players playing this game.
     * @param actualPlayers
     */
    void setActualPlayers(unsigned int actualPlayers);


    /**
     * @brief setPlayerName sets the name of the player identified by their index.
     * @param playerIndex
     * @param name
     */
    void setPlayerName(unsigned int playerIndex, std::string name);


    /**
     * @brief moveRobber moves the robber to a new place on the terrain map identified by x, y.
     * @param x
     * @param y
     */
    void moveRobber(int x, int y);

    /**
     * @brief makePayment takes a certain amount of player's resources to pay for the construction it purchased.
     * @param construction
     */
    void makePayment(unsigned int construction);


    /**
     * @brief bulkSendResources sends five types of resources from one player to another.
     * @param senderIndex
     * @param receiverIndex
     * @param brickAmount
     * @param sheepAmount
     * @param oreAmount
     * @param grainAmount
     * @param lumberAmount
     */
    void bulkSendResources(unsigned int senderIndex, unsigned int receiverIndex, unsigned int brickAmount,
                           unsigned int sheepAmount, unsigned int oreAmount, unsigned int grainAmount,
                           unsigned int lumberAmount);


    /**
     * @brief endTurn increments the turn number, deactivates the robber and points the current player to a new player.
     */
    void endTurn();


    /* Internal */
    int transfer(ComponentStack* sender, ComponentStack* receiver, unsigned int tranferAmount);
    void sendResources(unsigned int senderIndex, unsigned int receiverIndex, unsigned int rscCode, unsigned int sendAmount);
    void produceFromInitial(int x, int y, int z);
    void produceFromHex(int x, int y);
    void produceFromIntersection(Location* interLoc, int rscCode);
    void updateFreeStuff(unsigned int purchasable, int update);
    unsigned int countFreeStuff(unsigned int purchasable);
    void robIntersection(Location* interLoc);


    /* Responsive */
    unsigned int rollDice();
    int robberActivated();
    int affordable(unsigned int purchasable);
    int placeConstruction(int x, int y, int s, unsigned int construction);
    int buyDevelopment();
    int playKnight();
    int playRoadBuilding();
    int playYOP(int rscCode);
    int playMonopoly(int rscCode);
    int playVictoryPoint();
    std::string refreshStats();

};

#endif // CATAN_H
