#include <iostream>
#include "Crazy.h"
#include "unistd.h"

using namespace std;

int main()
{
    cout <<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
    cout << " ----------------------------------- CRAZY! ----------------------------------- ";
    cout <<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
    Crazy* crazy = new Crazy();

    cout << "\n                           No. of Players: ";
    int count;

    do{
        cin >> count;
    }while(count <= 1);

    crazy->initiate(count);
    for(unsigned int i = 0; (int)i < crazy->settings->actualPlayers;i++){
        cout << "                           Player " << i+1 << " Name: ";
        string name;
        cin >> name;
        crazy->setPlayerID(i,name,i);
    }
    crazy->startGame();

    for(int j = 0; j < 50; j++){
        cout << endl;
    }
    while(crazy->progressControl->statusTracker->victoryMode1 == 0){
        while(crazy->progressControl->statusTracker->toNextRound == 0 && crazy->progressControl->statusTracker->victoryMode1 == 0){

            int i = crazy->progressControl->timeTracker->turn;
            string statusMessage = crazy->startTurn(i);
            crazy->statusPrinter();
            crazy->print(statusMessage,1);

            /************** If you've been skipped *************/
            if(crazy->skipNext)
            {
                crazy->skipNext = 0;
            }

            /************* If you've been attacked *************/
            else if(crazy->drawAndSkip)
            {
                bool defend = crazy->defendable();
                if(defend)
                {
                    vector<unsigned int>* ind = crazy->attackResponse(defend);
                    crazy->print("You can defend with: ",0);
                    crazy->printStack(ind);

                    int choice;
                    std::cin >> choice;
                    crazy->drop(choice);
                    crazy->defenseCounter();
                }
                else
                {
                    crazy->exDraw();
                    crazy->printHand();
                }
            }

            /******************* Neither **********************/
            else {
                crazy->print("Drop a card (1 or 0)? ", 0);

                int immediateDrop;
                std::cin >> immediateDrop;

                /***************************** DROPPING ***********************************/
                if(immediateDrop)
                {
                    crazy->print("Which card do you want to drop: ", 0);

                    unsigned int dropChoice;
                    std::cin >> dropChoice;
                    crazy->print(crazy->drop(dropChoice),1);

                    if(crazy->illegal)
                    {
                        crazy->draw(2);
                        crazy->illegal = 0;
                        crazy->printHand();
                    }
                    else if(crazy->suitChange)
                    {
                        crazy->printHand();
                        crazy->print("Change Suit to (1 - ♠, 2 - ♥, 3 - ♣, 4 - ♦) : ", 0);

                        unsigned int suitChoice;
                        std::cin >> suitChoice;
                        crazy->changeSuit(suitChoice);
                    }
                    else if(crazy->massDrop){
                        crazy->massDropper();
                        crazy->printHand();
                    }
                }

                /***************************** DRAWING ***********************************/
                else
                {
                    crazy->draw(1);
                    crazy->printHand();

                    crazy->print("Do You Want to Drop now? ", 0);
                    unsigned int drop;
                    std::cin >> drop;

                    /***************************** DROPPING ***********************************/
                    if(drop)
                    {
                        crazy->print("Which card do you want to drop: ", 0);

                        unsigned int dropChoice;
                        std::cin >> dropChoice;
                        crazy->print(crazy->drop(dropChoice),1);
                        crazy->printHand();

                        if(crazy->illegal)
                        {
                            crazy->draw(2);
                            crazy->illegal = 0;
                            crazy->printHand();
                        }
                        else if(crazy->suitChange)
                        {
                            crazy->print("Change Suit to: ", 0);

                            unsigned int suitChoice;
                            std::cin >> suitChoice;

                            crazy->changeSuit(suitChoice);
                        }
                        else if(crazy->massDrop){
                            crazy->massDropper();
                            crazy->printHand();
                        }
                    }
                }

            }
            crazy->endTurn();
            crazy->checkWin();
            usleep(900000);
            for(int j = 0; j < 50; j++){
                cout << endl;
            }
        }
    }
}
