///General
#include <iostream>

///Included Classes
///#include "../cntl_model/Robot.h"
//#include "../Catan-Game/Catan-Game"

///Header
#include "gtest/gtest.h"

using namespace std;

///start of BoardGameTests


///                                      TESTS for Card starting HERE

TEST(FUNNYTEST, FORNUMBERS) {

    ASSERT_EQ(1, 2) << "1 and 2 are not equal!!!";

}

//---------------------------------

int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
