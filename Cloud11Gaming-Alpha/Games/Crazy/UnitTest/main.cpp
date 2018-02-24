///General
#include <iostream>

///Included Classes
///#include "../cntl_model/Robot.h"

///Header
#include "gtest/gtest.h"

using namespace std;

std::string drop(unsigned int dropChoice);
/* #U *

void changeSuit(int choice);

bool defendable();

std::string massDropper(unsigned int suitChoice);

std::string attackResponse();

std::string exDraw();

// Skip
void skipSelf();

void endTurn();

// Checks if there is a winner. Returns 1 when there is, 0 when there is not. */
int foundWinner();


///                                      TESTS for enforcer starting HERE

TEST(FUNNYTEST, FORNUMBERS) {

    ASSERT_EQ(1, 2) << "1 and 2 are not equal!!!";

}

///                                      TESTS for enforcer END HERE

///                                      TESTS for defenseChecker starting HERE
///                                      TESTS for defenseChecker END HERE

///                                      TESTS for defenseCounter starting HERE
///                                      TESTS for defenseCounter END HERE

///                                      TESTS for draw starting HERE
///                                      TESTS for draw END HERE

///                                      TESTS for getAllOf starting HERE
///                                      TESTS for getAllOf END HERE

///                                      TESTS for checkWin starting HERE
///                                      TESTS for checkWin END HERE

///                                      TESTS for interpretMsg starting HERE
///                                      TESTS for interpretMsg END HERE

///                                      TESTS for printStatus starting HERE
///                                      TESTS for printStatus END HERE

///                                      TESTS for print starting HERE
///                                      TESTS for print END HERE

///                                      TESTS for printC starting HERE
///                                      TESTS for printC END HERE

///                                      TESTS for printCc starting HERE
///                                      TESTS for printCc END HERE

///                                      TESTS for printStack starting HERE
///                                      TESTS for printStack END HERE

///                                      TESTS for Trade starting HERE
///                                      TESTS for Trade END HERE

///                                      TESTS for draw starting HERE
///                                      TESTS for draw END HERE

///                                      TESTS for draw starting HERE
///                                      TESTS for draw END HERE

///                                      TESTS for draw starting HERE
///                                      TESTS for draw END HERE


///end of Crazy

int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
