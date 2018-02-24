#ifndef GAMELOGIC_H
#define GAMELOGIC_H


class GameLogic{


public:

    virtual ~GameLogic() = 0;

    virtual void staticSettings() = 0;
    virtual void startCommunication() = 0;
    virtual void dynamicSettings() = 0;
    virtual void startProgress() = 0;
    virtual void buildGlossary() = 0;
    virtual void buildPlayerGroups() = 0;
    virtual void buildComponentStacks() = 0;
    virtual void buildPhysicalSpaces() = 0;

    virtual void startGame() = 0;
    virtual void stage() = 0;
    virtual void round() = 0;
    virtual void turn() = 0;
    virtual void move() = 0;
    virtual void updateScores() = 0;
    virtual void clearDeactivated() = 0;

    virtual void input() = 0;
    virtual void output() = 0;

    virtual void cleanUp() = 0;
    virtual void endGame() = 0;


};

#endif // GAMELOGIC_H
