#include "Crazy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

/**
 * @brief Crazy::Crazy
 */
Crazy::Crazy(){
    suitChange = 0;
    extraDraw = 0;
    skipNext = 0;
    faceSuit = 0;
    faceValue = 0;
    massDrop = 0;
    illegal = 0;
    equalSuit = 0;
    equalValue = 0;
    drawAndSkip = 0;
}

/**
 * @brief Crazy::~Crazy
 */
Crazy::~Crazy(){
    cascade();
}

/**
 * @brief Crazy::staticSettings
 */
void Crazy::staticSettings(){
    settings->maxPlayers = 10;
    settings->maxPlayerGroups = 1;
    settings->maxComponentStacks = 2;
    settings->maxPhysicalSpaces = 0;
}

/**
 * @brief Crazy::startCommunication
 */
void Crazy::startCommunication(){
    //get actual player
}

/**
 * @brief Crazy::dynamicSettings
 */
void Crazy::dynamicSettings(){

    settings->actualPlayerGroups = 1;
    settings->actualComponentStacks = 2;
    settings->actualPhysicalSpaces = 0;

    settings->extraSettings->addAttribute(new Attribute(0,"Number of Decks",(settings->actualPlayers + 2)/2));
}

/**
 * @brief Crazy::startProgress
 */
void Crazy::startProgress(){

    progressControl->timeTracker->turnPerRound = settings->actualPlayers;
    progressControl->statusTracker->connecting = 0;
    progressControl->statusTracker->connected = 1;
    progressControl->statusTracker->disconnected = 1;
    progressControl->statusTracker->loading = 1;
    progressControl->statusTracker->addingPlayer = 0;
    progressControl->statusTracker->addingComplete = 0;
    progressControl->statusTracker->started = 0;
    progressControl->statusTracker->paused = 1;
    progressControl->statusTracker->waiting = 0;

    progressControl->statusTracker->toNextTurn = 0;
    progressControl->statusTracker->toNextMove = 0;
    progressControl->statusTracker->toNextRound = 0;
    progressControl->statusTracker->toNextStage = 0;
    progressControl->statusTracker->victoryMode1 = 0;
    progressControl->statusTracker->victoryMode2 = 0;
    progressControl->statusTracker->victoryMode3 = 0;
    progressControl->statusTracker->draw = 0;
    progressControl->statusTracker->ended = 0;
}

/**
 * @brief Crazy::buildGlossary
 */
void Crazy::buildGlossary(){

    glossary->addComponentStackType(new Type(0, "Deck"));
    glossary->addComponentStackType(new Type(1, "Discard"));
}

/**
 * @brief Crazy::buildPlayerGroups
 */
void Crazy::buildPlayerGroups(){

    playerGroupManager->addPlayerGroup(new PlayerGroup());

    for(int i = 0; i < settings->actualPlayers; i++){

        Player* newPlayer = new Player(progressControl->globalCounters->playerCreatedCount,0);
        progressControl->globalCounters->incrementPlayerCount();

        newPlayer->getAttributeList()->addAttribute(new Attribute(0, "ACE O' SPADES", 0));
        newPlayer->getAttributeList()->addAttribute(new Attribute(1, "TWO O' SPADES", 0));
        newPlayer->getAttributeList()->addAttribute(new Attribute(2, "ANY OTHER TWO", 0));

        ComponentStackManager* playerComponentStackManager = newPlayer->getCollected();
        playerComponentStackManager->addComponentStack(new ComponentStack()); // Add hand for each player

        /******************** assign client ID to the players **********************************/

        playerGroupManager->getPlayerGroupAt(0)->addPlayer(newPlayer);
    }
    std::cout<< std::endl;
}

/**
 * @brief Crazy::buildComponentStacks
 */
void Crazy::buildComponentStacks(){
    deck = new ComponentStack(glossary->getComponentStackType(0));

    discard = new ComponentStack(glossary->getComponentStackType(1));

    // Loop through number of decks
    for(unsigned int i = 0; i < (unsigned int)settings->extraSettings->getAttributeValue(0);i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 13; k++){
                Component* newCard = new Component(progressControl->globalCounters->componentCreatedCount, 0);
                progressControl->globalCounters->incrementComponentCount();
                std::string suit;

                switch(j){
                case 0:
                    suit = "Spades";
                    break;
                case 1:
                    suit = "Hearts";
                    break;
                case 2:
                    suit = "Clubs";
                    break;
                case 3:
                    suit = "Diamonds";
                    break;
                default:
                    suit = "e";
                    break;
                }
                newCard->getAttributeList()->addAttribute(new Attribute(0, "Suit", j+1, suit));
                newCard->getAttributeList()->addAttribute(new Attribute(1, "Value", k+1));
                deck->addComponent(newCard);
            }
        }
    }
    componentStackManager->addComponentStack(deck);
    componentStackManager->addComponentStack(discard);
}

/**
 * @brief Crazy::buildPhysicalSpaces
 */
void Crazy::buildPhysicalSpaces(){}



/*********** Start Actual Game Process **************/

/**
 * @brief Crazy::startGame
 */
void Crazy::startGame(){

    shuffle();

    /*** 1 Card added to discard from deck to start the game ***/
    Component* firstCard = deck->retrieveComponentFromTop();
    discard->addComponent(firstCard);
    faceSuit = firstCard->getAttributeList()->getAttributeValue(0);
    faceValue = firstCard->getAttributeList()->getAttributeValue(1);

    for(int i = 0; i < settings->actualPlayers; i++){
        Player* currentPlayer = playerGroupManager->getPlayerGroupAt(0)->getPlayerAt(i);
        for(int j = 0; j < 12; j++){
            Component* currentCard = deck->retrieveComponentFromTop();
            defenseChecker(currentPlayer, currentCard);
            currentPlayer->getCollected()->getComponentStackAt(0)->addComponent(currentCard);
        }
    }
}

void Crazy::stage(){}

void Crazy::round(){}

void Crazy::turn(){}

void Crazy::move(){}

void Crazy::updateScores(){}

void Crazy::clearDeactivated(){}

void Crazy::input(){}

void Crazy::output(){}

void Crazy::cleanUp(){}


void Crazy::endGame(){}

/**
 * @brief Crazy::enforcer
 * @return
 */
std::string Crazy::enforcer(){
    std::string result = "Regular card played.";
    if(!illegal){
        switch(faceValue){
        case 1:
            if(faceSuit == 1){
                extraDraw = extraDraw + 5;
                drawAndSkip = 1;
                result = "A of ♠ played. Next player draws 5.";
            }
            else{
                extraDraw = 0;
                drawAndSkip = 0;
            }
            suitChange = 0;
            skipNext = 0;
            massDrop = 0;
            break;
        case 2:
            extraDraw = extraDraw + 2;
            drawAndSkip = 1;
            suitChange = 0;
            skipNext = 0;
            massDrop = 0;
            result = "2 played. Next player draws 2.";
            break;
        case 5:
            extraDraw = 0;
            drawAndSkip = 0;
            suitChange = 0;
            skipNext = 1;
            massDrop = 0;
            result = "5 played. Next player's turn is skipped.";
            break;
        case 7:
            extraDraw = 0;
            drawAndSkip = 0;
            suitChange = 0;
            skipNext = 0;
            massDrop = 1;
            result = "7 played. Player may drop all other cards of the same suit.";
            break;
        case 8:
            extraDraw = 0;
            drawAndSkip = 0;
            suitChange = 1;
            skipNext = 0;
            massDrop = 0;
            result = "8 played. Player changes suit.";
            break;
        case 11:
            extraDraw = 0;
            drawAndSkip = 0;
            suitChange = 1;
            skipNext = 0;
            massDrop = 0;
            result = "J played. Player changes suit.";
            break;
        default:
            extraDraw = 0;
            suitChange = 0;
            skipNext = 0;
            drawAndSkip = 0;
            massDrop = 0;
            break;
        }
    }
    else{
        result = "Illegal Card Played. Player draws 2 cards.";
    }
    return result;
}

/**
 * @brief Crazy::defenseCounter
 */
void Crazy::defenseCounter(){
    int size = currentHand->getComponentCount();

    currentPlayer->getAttributeList()->setAttributeValue(0, 0);
    currentPlayer->getAttributeList()->setAttributeValue(1, 0);
    currentPlayer->getAttributeList()->setAttributeValue(2, 0);

    for(int i = 0; i < size; i++){
        defenseChecker(currentPlayer, currentHand->getComponentAt(i));
    }
}

/**
 * @brief Crazy::defenseChecker
 * @param player is the player to be checked
 * @param card card played
 */
void Crazy::defenseChecker(Player* player, Component* card){
    int suit = (int)(card->getAttributeList()->getAttributeValue(0));
    int value =(int)(card->getAttributeList()->getAttributeValue(1));

    // Two O' Spades count
    if(value == 2){
        // 2 O' spades count
        if(suit == 1){
            int oldValue = (int)(player->getAttributeList()->getAttributeValue(1));
            player->getAttributeList()->setAttributeValue(1, oldValue + 1);
        }
        int oldValue = (int)(player->getAttributeList()->getAttributeValue(2));
        player->getAttributeList()->setAttributeValue(2, oldValue + 1);
    }
    // Ace O' Spades Count
    else if(value == 1 && suit == 1){
        int oldValue = (int)(player->getAttributeList()->getAttributeValue(0));
        player->getAttributeList()->setAttributeValue(0, oldValue + 1);
    }
}

/**
 * @brief Crazy::getAllOf
 * @param suit is the suit played
 * @param value the value of card
 * @return
 */
std::vector<unsigned int>* Crazy::getAllOf(int suit, int value){
    std::vector<unsigned int>* options = new std::vector<unsigned int>;
    unsigned int size = currentHand->getComponentCount();
    for(unsigned int i = 0; i < size; i++){
        Component* currentCard = currentHand->getComponentAt(i);
        int cardSuit = currentCard->getAttributeList()->getAttributeValue(0);
        int cardValue = currentCard->getAttributeList()->getAttributeValue(1);

        if(cardValue == value && cardSuit == suit){
            options->push_back(i);
        }
        else if(suit == 0){
            if(cardValue == value){
                options->push_back(i);
            }
        }
    }
    return options;
}

/**
 * @brief Crazy::checkWin
 */
void Crazy::checkWin(){
    if(currentHand->isEmpty()){
        progressControl->statusTracker->victoryMode1 = 1;
        currentPlayer->hasWon();
    }
}

/**
 * @brief Crazy::print
 * @param message to print out
 * @param i definition
 */
void Crazy::print(std::string message, int i){
    if(i){
        std::cout << message << std::endl;
    }
    else{
        std::cout << message;
    }
}

/**
 * @brief Crazy::print
 * @param i
 */
void Crazy::print(int i){
    std::cout << i << std::endl;
}

/**
 * @brief Crazy::print
 * @param printed thing to print
 * @param xxx
 */
void Crazy::print(int printed, int xxx){
    if(xxx != 10023){
        std::cout << printed << " ";
    }
}

/**
 * @brief Crazy::printCc
 * @param card to print
 */
void Crazy::printCc(Component* card){
    int cardSuit = card->getAttributeList()->getAttributeValue(0);
    int cardValue = card->getAttributeList()->getAttributeValue(1);
    std::string suit;
    std::string value;

    switch(cardSuit){
    case 1:
        suit = "♠";
        break;
    case 2:
        suit = "♥";
        break;
    case 3:
        suit = "♣";
        break;
    case 4:
        suit = "♦";
        break;
    default:
        suit = "e";
        break;
    }

    switch(cardValue){
    case 1:
        value = "A";
        break;
    case 2:
        value = "2";
        break;
    case 3:
        value = "3";
        break;
    case 4:
        value = "4";
        break;
    case 5:
        value = "5";
        break;
    case 6:
        value = "6";
        break;
    case 7:
        value = "7";
        break;
    case 8:
        value = "8";
        break;
    case 9:
        value = "9";
        break;
    case 10:
        value = "10";
        break;
    case 11:
        value = "J";
        break;
    case 12:
        value = "Q";
        break;
    case 13:
        value = "K";
        break;
    default:
        value = "e";
        break;
    }
    std::cout << "[" << value << " " << suit << "]";
}

/**
 * @brief Crazy::printStack
 * @param stack to print
 */
void Crazy::printStack(ComponentStack* stack){

    int size = stack->getComponentCount();
    std::cout << " ";
    for(int i = 0; i < size;i++){
        printCc(stack->getComponentAt(i));
        std::cout << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Crazy::printStack
 * @param stack to print
 */
void Crazy::printStack(std::vector<unsigned int>* printed){

    int size = printed->size();
    std::cout << "(";
    for(int i = 0; i < size;i++){
        std::cout << printed->at(i) << " - ";
        printCc(currentHand->getComponentAt(printed->at(i)));
        std::cout << "; ";
    }
    std::cout << ") \n";
}

/**
 * @brief Crazy::shuffle
 */
void Crazy::shuffle(){
    Component* temp;
    unsigned int randIndex;
    int size = deck->getComponentCount();

    srand (time(NULL));
    randIndex = rand() % (size-1) + 0;
    int count = 0;

    while(count != 250){
        temp = deck->retrieveComponentAt(randIndex);
        deck->addComponent(temp);
        randIndex = rand() % (size-1) + 0;
        count++;
    }
}

/**
 * @brief Crazy::initiate
 * @param playerCount
 */
void Crazy::initiate(int playerCount){
    staticSettings();
    settings->actualPlayers = playerCount;
    startCommunication();
    dynamicSettings();
    startProgress();
    buildPlayerGroups();
    buildComponentStacks();
}

/**
 * @brief Crazy::setPlayerID
 * @param assignedID to the player
 * @param name of string
 * @param index  of spot
 */
void Crazy::setPlayerID(int assignedID, std::string name, unsigned int index){

    accessOverride->playerAccess = playerGroupManager->getPlayerGroupAt(0)->getPlayerAt(index);

    accessOverride->playerAccess->setAssignedID(assignedID);
    accessOverride->playerAccess->setName(name);

    accessOverride->playerAccess = NULL;
}


unsigned int Crazy::getPlayerOfThisTurn(){
    return progressControl->timeTracker->turn;
}

/**
 * @brief Crazy::startTurn
 * @param playerIndex
 * @return
 */
std::string Crazy::startTurn(unsigned int playerIndex){

    std::string turnInfo;

    currentPlayer = playerGroupManager->getPlayerGroupAt(0)->getPlayerAt(playerIndex);
    currentHand = currentPlayer->getCollected()->getComponentStackAt(0);

    if (skipNext) turnInfo = "You have been skipped.";
    if (drawAndSkip){
        std::stringstream ss;
        ss << extraDraw;
        turnInfo = " You must draw " + ss.str() + " more cards.";
    }

    return turnInfo;
}

/**
 * @brief Crazy::drop
 * @param dropChoice card to drop
 * @return
 */
std::string Crazy::drop(unsigned int dropChoice){

    Component* dropped = currentHand->retrieveComponentAt(dropChoice-1);
    discard->addComponent(dropped);

    int topSuit = dropped->getAttributeList()->getAttributeValue(0);
    int topValue = dropped->getAttributeList()->getAttributeValue(1);

    if(topValue != 8 && topValue != 11){
        if(topSuit != faceSuit && topValue != faceValue){
            illegal = 1;
        }
    }
    faceSuit = topSuit;
    faceValue = topValue;
    return enforcer();
}

/**
 * @brief Crazy::massDropper
 * @param suitChoice to drop
 * @return
 */
std::string Crazy::massDropper(unsigned int suitChoice){
    std::stringstream ss;

    unsigned int handSize = currentHand->getComponentCount();
    std::string result;

    for(unsigned int i = 0; i < handSize; i++){
        if(currentHand->getComponentAt(i)->getAttributeList()->getAttributeValue(0) == suitChoice){
            ss << i;
            result = result + ss.str() + ",";
            ss.str(std::string());
            ss.clear();
        }
    }
    massDrop = 0;
    return result;
}

/**
 * @brief Crazy::massDropper
 */
void Crazy::massDropper(){

    unsigned int handSize = currentHand->getComponentCount();

    print("You Can Drop: ",0);
    for(unsigned int i = 0; i < handSize;i++){
        if(currentHand->getComponentAt(i)->getAttributeList()->getAttributeValue(0) == faceSuit){
            printCc(currentHand->getComponentAt(i));
        }
    }
    print(".",1);

    print("How many extra do You Want to Drop? ", 0);

    unsigned int extraDrop;
    std::cin >> extraDrop;

    print("Cards to Drop: ", 0);

    for(unsigned int b = 0; b < extraDrop; b++){
        int choices;
        std::cin >> choices;
        for(unsigned int i = 0; i < currentHand->getComponentCount();i++){
            if(currentHand->getComponentAt(i)->getAttributeList()->getAttributeValue(1) == choices && currentHand->getComponentAt(i)->getAttributeList()->getAttributeValue(0) == faceSuit){
                Component* dropp = currentHand->retrieveComponentAt(i);
                if(dropp->getAttributeList()->getAttributeValue(1) == 5){
                    skipNext = 1;
                }
                discard->addComponent(dropp);
                print("Dropped: ",0);
                printCc(dropp);
                std::cout << std::endl;
                break;
            }
        }
    }
    massDrop = 0;
}

/**
 * @brief Crazy::draw
 * @param amount to draw
 */
void Crazy::draw(int amount){
    for(int i = 0; i < amount; i++){
        currentHand->addComponent(deck->retrieveComponentFromTop());
    }
    defenseCounter();
}

/**
 * Choice - Defend or not, Type - Type of defense, Another Ace or A 2 of spades
 */
std::string Crazy::attackResponse(){
    std::stringstream ss;
    std::string result;
    std::vector<unsigned int>* allAos = getAllOf(1,1);
    std::vector<unsigned int>* allTos = getAllOf(1,2);
    std::vector<unsigned int>* allTwo = getAllOf(0,2);

    if(faceValue == 1 && faceSuit == 1){
        int sizeAOS = allAos->size();
        int sizeTOS = allTos->size();
        for(int i = 0; i < sizeAOS; i++){
            ss << allAos->at(i);
            result = result + ","+ ss.str();
        }
        for(int i = 0; i < sizeTOS; i++){
            ss << allTos->at(i);
            result = result + ","+ ss.str();
        }
    }
    else if(faceValue == 2 && faceSuit == 1){
        int sizeAOS = allAos->size();
        int sizeTWS = allTwo->size();
        for(int i = 0; i < sizeAOS; i++){
            ss << allAos->at(i);
            result = result + ss.str() + ",";
            ss.str(std::string());
            ss.clear();
        }
        for(int i = 0; i < sizeTWS; i++){
            ss << allTwo->at(i);
            result = result + ss.str() + ",";
            ss.str(std::string());
            ss.clear();
        }
    }
    else if(faceValue == 2){
        int size = allTwo->size();
        for(int i = 0; i < size; i++){
            ss << allTwo->at(i);
            result = result + ss.str() + ",";
            ss.str(std::string());
            ss.clear();
        }
    }
    return result;
}

/**
 * Choice - Defend or not, Type - Type of defense, Another Ace or A 2 of spades
 */
std::vector<unsigned int>* Crazy::attackResponse(bool defend){
    std::vector<unsigned int>* options = new std::vector<unsigned int>;

    if(defend){

        std::vector<unsigned int>* allAos = getAllOf(1,1);
        std::vector<unsigned int>* allTos = getAllOf(1,2);
        std::vector<unsigned int>* allTwo = getAllOf(0,2);

        if(faceValue == 1 && faceSuit == 1){
            int sizeAOS = allAos->size();
            int sizeTOS = allTos->size();
            for(int i = 0; i < sizeAOS; i++){
                options->push_back(allAos->at(i));
            }
            for(int i = 0; i < sizeTOS; i++){
                options->push_back(allTos->at(i));
            }
        }
        else if(faceValue == 2 && faceSuit == 1){
            int sizeAOS = allAos->size();
            int sizeTWS = allTwo->size();
            for(int i = 0; i < sizeAOS; i++){
                options->push_back(allAos->at(i));
            }
            for(int i = 0; i < sizeTWS; i++){
                options->push_back(allTwo->at(i));
            }
        }
        else if(faceValue == 2){
            int size = allTwo->size();
            for(int i = 0; i < size; i++){
                options->push_back(allTwo->at(i));
            }
        }
    }

    return options;
}

/**
 * @brief Crazy::defendable
 * @return is it was defended
 */
bool Crazy::defendable(){
    bool result = false;

    int aceSpade = (int)currentPlayer->getAttributeList()->getAttributeValue(0);
    int twoSpade = (int)currentPlayer->getAttributeList()->getAttributeValue(1);
    int anyTwo = (int)currentPlayer->getAttributeList()->getAttributeValue(2);

    if(faceValue == 2){
        if(anyTwo){
            result = true;
        }
        if(faceSuit == 1){
            if(aceSpade){
                result = true;
            }
        }
    }
    if(faceValue == 1 && faceSuit == 1){
        if(aceSpade || twoSpade){
            result = true;
        }
    }
    return result;
}

/**
 * @brief Crazy::exDraw
 * @return  string to draw
 */
std::string Crazy::exDraw(){
    draw(extraDraw);
    extraDraw = 0;
    drawAndSkip = 0;
    std::string str = "You now draw.";
    return str;
}

/**
 * @brief Crazy::changeSuit
 * @param choice
 */
void Crazy::changeSuit(int choice){
    faceSuit = choice;
    suitChange = 0;
}

/**
 * @brief Crazy::skipSelf
 */
void Crazy::skipSelf(){
    endTurn();
}

/**
 * @brief Crazy::endTurn
 */
void Crazy::endTurn(){
    progressControl->statusTracker->toNextTurn = 1;
    progressControl->timeTracker->incrementTurn();
}

/**
 * @brief Crazy::foundWinner
 * @return if won
 */
int Crazy::foundWinner(){
    return progressControl->statusTracker->victoryMode1;
}

/**
 * @brief Crazy::statusPrinter
 */
void Crazy::statusPrinter(){

        int aceSpade = (int)currentPlayer->getAttributeList()->getAttributeValue(0);
        int twoSpade = (int)currentPlayer->getAttributeList()->getAttributeValue(1);
        int anyTwo = (int)currentPlayer->getAttributeList()->getAttributeValue(2);

        std::string standIn;
        switch(faceSuit){
        case 1:
            standIn = "♠";
            break;
        case 2:
            standIn = "♥";
            break;
        case 3:
            standIn = "♣";
            break;
        case 4:
            standIn = "♦";
            break;
        default:
            standIn = "e";
            break;
        }
        std::string stander;
        switch(faceValue){
        case 1:
            stander = "A";
            break;
        case 2:
            stander = "2";
            break;
        case 3:
            stander = "3";
            break;
        case 4:
            stander = "4";
            break;
        case 5:
            stander = "5";
            break;
        case 6:
            stander = "6";
            break;
        case 7:
            stander = "7";
            break;
        case 8:
            stander = "8";
            break;
        case 9:
            stander = "9";
            break;
        case 10:
            stander = "10";
            break;
        case 11:
            stander = "J";
            break;
        case 12:
            stander = "Q";
            break;
        case 13:
            stander = "K";
            break;
        default:
            stander = "e";
            break;
        }

        /**********/
        int deckSize = deck->getComponentCount();
        int discardSize = discard->getComponentCount();
        print("--------------------------------------------------------------------------------",0);

        std::cout << std::endl << "  " << currentPlayer->getName() <<" -> [Top-No:" << stander << " Top-Suit:"<< standIn << "] [Discarded: " << discardSize << "] [In Deck: "<< deckSize <<"] [Top Card: ";
        printCc(discard->getComponentFromTop());
        print("]",1);

        print("--------------------------------------------------------------------------------",0);
        std::cout << std::endl << std::endl;
        printHand();
        std::cout << " Defenses -> " << aceSpade << " : " << twoSpade << " : " << anyTwo << std::endl;
}

/**
 * @brief Crazy::printHand
 */
void Crazy::printHand(){
    print("                           YOUR HAND", 1);
    std::cout << "|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 |  12 |" << std::endl;
    printStack(currentHand);
}
