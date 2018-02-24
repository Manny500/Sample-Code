#include "Randomizer.h"


namespace rndm {


/**
 * @brief dice will get a random number from 6 to 1 and add that number to all the rollls depending on how many dice there are
 * @param diceUsed is the number of dice to be rolled
 * @return
 */\
int dice(unsigned int diceUsed){

    unsigned sum = 0;

    for (unsigned int i = 0; i < diceUsed; i ++){

        sum += rand() % 6 + 1;
    }

    return sum;
}

/**
 * @brief rndInc will return a random number
 * @param min start of the range
 * @param max end of the range
 * @return random number between range
 */
int rndInc(unsigned int min, unsigned int max){

    return rand() % max + min;
}


}

