///General
#include <iostream>

///Included Classes

///Header
#include "gtest/gtest.h"
#include "../VelocityEngine/MathLibraries/Hexagon2D.h"
#include "../VelocityEngine/MathLibraries/Randomizer.h"

using namespace std;

//Instances


///start of LogicalCore

///                                      All Logical Core Methods are virtual

///end of Logical Core ////////////////////////////////////////////////////////////////

///start of Math Libraries

///                                     TESTS for dice starting HERE

/**
 * @brief TEST test the dice function 6 to 1 dice
 */
TEST(DICETEST, DICE)
{
   int rondo = rndm::dice(1);

   ASSERT_TRUE(rondo < 7 && rondo > 0);


}

///                                      TESTS for dice END HERE

///                                      TESTS for rndInc starting HERE

/**
* @brief TEST the random method within range
*/

TEST(RANDOMTEST, RND)
{
  int rondo = rndm::rndInc(1,6);

  ASSERT_TRUE(rondo < 7 && rondo > 0);


}
///                                      TESTS for rndInc END HERE

///                                      TESTS for rndInc END HERE

///end of Math Libraries /////////////////////////////////////////////////////////////////////

///start of Structural Core


///                                      TESTS for GamesPlayedList starting HERE

/**
* @brief TEST
*/
//TEST(DICETEST, DICE)
//{
//  int rondo = rndm::rndInc(1,6);

//  ASSERT_TRUE(rondo < 7 && rondo > 0);


//}

///                                      TESTS for GamesPlayedList END HERE

//-----------------VERTEX TESTS BEGINNING-------------------------------------------
TEST(VERTEXTESTS, X0)
{
    ASSERT_TRUE(hex2dvef0d::v0vx(0)==1);
}
TEST(VERTEXTESTS, Y0)
{
    ASSERT_TRUE(hex2dvef0d::v0vy(0)==-2);
}
TEST(VERTEXTESTS, Z0)
{
    ASSERT_TRUE(hex2dvef0d::v0vz()==1);
}
TEST(VERTEXTESTS, X120)
{
    ASSERT_TRUE(hex2dvef0d::v120vx(0)==1);
}
TEST(VERTEXTESTS, Y120)
{
    ASSERT_TRUE(hex2dvef0d::v120vy(0)==-1);
}
TEST(VERTEXTESTS, Z120)
{
    ASSERT_TRUE(hex2dvef0d::v120vz()==1);
}
TEST(VERTEXTESTS, X240)
{
    ASSERT_TRUE(hex2dvef0d::v240vx(0)==0);
}
TEST(VERTEXTESTS, Y240)
{
    ASSERT_TRUE(hex2dvef0d::v240vy(0)==-1);
}
TEST(VERTEXTESTS, Z240)
{
    ASSERT_TRUE(hex2dvef0d::v240vz()==1);
}
TEST(VERTEXTESTS, X60)
{
    ASSERT_TRUE(hex2dvef0d::v60vx(0)==0);
}
TEST(VERTEXTESTS, Y60)
{
    ASSERT_TRUE(hex2dvef0d::v60vy(0)==1);
}
TEST(VERTEXTESTS, Z60)
{
    ASSERT_TRUE(hex2dvef0d::v60vz()==0);
}
TEST(VERTEXTESTS, X180)
{
    ASSERT_TRUE(hex2dvef0d::v180vx(0)==-1);
}
TEST(VERTEXTESTS, Y180)
{
    ASSERT_TRUE(hex2dvef0d::v180vy(0)==2);
}
TEST(VERTEXTESTS, Z180)
{
    ASSERT_TRUE(hex2dvef0d::v180vz()==0);
}
TEST(VERTEXTESTS, X300)
{
    ASSERT_TRUE(hex2dvef0d::v300vx(0)==-1);
}
TEST(VERTEXTESTS, Y300)
{
    ASSERT_TRUE(hex2dvef0d::v300vy(0)==1);
}
TEST(VERTEXTESTS, Z300)
{
    ASSERT_TRUE(hex2dvef0d::v300vz()==0);
}
//------------------------EDGE TESTS BEGINNING< VERTEX TESTS ENDING--------------
TEST(EDGETESTS, X0)
{
    ASSERT_TRUE(hex2dvef0d::e0vx(0)==1);
}
TEST(EDGETESTS, Y0)
{
    ASSERT_TRUE(hex2dvef0d::e0vy(0)==-1);
}
TEST(EDGETESTS, Z0)
{
    ASSERT_TRUE(hex2dvef0d::e0vz()==1);
}
TEST(EDGETESTS, X120)
{
    ASSERT_TRUE(hex2dvef0d::e120vx(0)==0);
}
TEST(EDGETESTS, Y120)
{
    ASSERT_TRUE(hex2dvef0d::e120vy(0)==0);
}
TEST(EDGETESTS, Z120)
{
    ASSERT_TRUE(hex2dvef0d::e120vz()==1);
}
TEST(EDGETESTS, X240)
{
    ASSERT_TRUE(hex2dvef0d::e240vx(0)==0);
}
TEST(EDGETESTS, Y240)
{
    ASSERT_TRUE(hex2dvef0d::e240vy(0)==-1);
}
TEST(EDGETESTS, Z240)
{
    ASSERT_TRUE(hex2dvef0d::e240vz()==1);
}
TEST(EDGETESTS, X60)
{
    ASSERT_TRUE(hex2dvef0d::e60vx(0)==0);
}
TEST(EDGETESTS, Y60)
{
    ASSERT_TRUE(hex2dvef0d::e60vy(0)==0);
}
TEST(EDGETESTS, Z60)
{
    ASSERT_TRUE(hex2dvef0d::e60vz()==0);
}
TEST(EDGETESTS, X180)
{
    ASSERT_TRUE(hex2dvef0d::e180vx(0)==0);
}
TEST(EDGETESTS, Y180)
{
    ASSERT_TRUE(hex2dvef0d::e180vy(0)==1);
}
TEST(EDGETESTS, Z180)
{
    ASSERT_TRUE(hex2dvef0d::e180vz()==0);
}

TEST(EDGETESTS, X300)
{
    ASSERT_TRUE(hex2dvef0d::e300vx(0)==-1);
}
TEST(EDGETESTS, Y300)
{
    ASSERT_TRUE(hex2dvef0d::e300vy(0)==1);
}
TEST(EDGETESTS, Z300)
{
    ASSERT_TRUE(hex2dvef0d::e300vz()==0);
}
//-------------------------------FACE TESTS BEGINNING, EDGE TESTS ENDING----------------

TEST(FACETESTS, X0)
{
    ASSERT_TRUE(hex2dvef0d::f0vx(0)==0);
}
TEST(FACETESTS, Y0)
{
    ASSERT_TRUE(hex2dvef0d::f0vy(0)==0);
}
TEST(FACETESTS, Z0)
{
    ASSERT_TRUE(hex2dvef0d::f0vz()==0);
}
TEST(FACETESTS, X120)
{
    ASSERT_TRUE(hex2dvef0d::f120vx(0)==0);
}
TEST(FACETESTS, Y120)
{
    ASSERT_TRUE(hex2dvef0d::f120vy(0)==1);
}
TEST(FACETESTS, Z120)
{
    ASSERT_TRUE(hex2dvef0d::f120vz()==0);
}
TEST(FACETESTS, X240)
{
    ASSERT_TRUE(hex2dvef0d::f240vx(0)==-1);
}
TEST(FACETESTS, Y240)
{
    ASSERT_TRUE(hex2dvef0d::f240vy(0)==1);
}
TEST(FACETESTS, Z240)
{
    ASSERT_TRUE(hex2dvef0d::f240vz()==0);
}
TEST(FACETESTS, X60)
{
    ASSERT_TRUE(hex2dvef0d::f60vx(0)==1);
}
TEST(FACETESTS, Y60)
{
    ASSERT_TRUE(hex2dvef0d::f60vy(0)==-1);
}
TEST(FACETESTS, Z60)
{
    ASSERT_TRUE(hex2dvef0d::f60vz()==1);
}
TEST(FACETESTS, X180)
{
    ASSERT_TRUE(hex2dvef0d::f180vx(0)==0);
}
TEST(FACETESTS, Y180)
{
    ASSERT_TRUE(hex2dvef0d::f180vy(0)==0);
}
TEST(FACETESTS, Z180)
{
    ASSERT_TRUE(hex2dvef0d::f180vz()==1);
}

TEST(FACETESTS, X300)
{
    ASSERT_TRUE(hex2dvef0d::f300vx(0)==0);
}
TEST(FACETESTS, Y300)
{
    ASSERT_TRUE(hex2dvef0d::f300vy(0)==-1);
}
TEST(FACETESTS, Z300)
{
    ASSERT_TRUE(hex2dvef0d::f300vz()==1);
}

///end of Structural Core //////////////////////////////////////////////////////////////////////////


int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
