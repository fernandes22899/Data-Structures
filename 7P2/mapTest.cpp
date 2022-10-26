/* These are test for map inerface methods using Google Test */
#include "map.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

/**
CS515 Assignment 5P
File: mapTest.cpp
Name: Jeffrey Fernandes
Section: 01
Date: 4/11/20
Collaboration Declaration: had to research some gtest functions
*/

//The constructor should create a map with zero size
TEST(MapTest, constructorCreatesZeroSizeMap)
{
  Map test;
  EXPECT_EQ( 0, test.size() );
}

//Inserting into an empty map should return true and result in a size of one
TEST(MapTest, insertWhileEmptyReturnsTrueAndMapSizeIsOne)
{
  Map test;

  EXPECT_TRUE( test.insert( "1", "Plumlee1" ) );
  EXPECT_EQ( 1, test.size() );
}

//Inserting a key that already exists should fail and not change the map size
TEST(MapTest, insertOfSameKeyReturnsFalseAndMapSizeRemainsSame)
{
  Map test;

  test.insert( "2", "Plumlee2" );
  EXPECT_FALSE( test.insert( "2", "Plumlee2" ) );
  EXPECT_EQ( 1, test.size() );
}

//Accessing an existing item using [] should return correct value and not
//change the map size
TEST(MapTest, indexOperatorOfExistingKeyReturnsProperValueAndSizeIsSame)
{
  Map test;

  test.insert( "3", "Plumlee3" );
  EXPECT_EQ( "Plumlee3", test["3"] );
  EXPECT_EQ( 1, test.size() );
}

//Using [] to set an item in an empty map should add the item with an
//appropriate value and increase the map size to one
TEST(MapTest, indexOperatorOnEmptyMapProperlySetsValueAndSizeIsOne)
{
  Map test;

  EXPECT_EQ( 0, test.size() );
  test["4"] = "Plumlee4PREZ";
  EXPECT_EQ( "Plumlee4PREZ", test["4"] );
  EXPECT_EQ( 1, test.size() );
}

//Using [] to set an item in a map that already contains other items
//inserts and updates the size appropriately
TEST(MapTest, indexOperatorOnMissingKeyProperlySetsValueAndIncrementsSize)
{
  Map test;

  test["5"] = "Plumlee5";
  EXPECT_EQ( 1, test.size() );
  EXPECT_EQ( "Plumlee5", test["5"] );

  test["6"] = "Plumlee6";
  EXPECT_EQ( 2, test.size() );
  EXPECT_EQ( "Plumlee6", test["6"] );

}
/*
//testing find
TEST(MapTest, findingAnElementInTheTree)
{
  Map test;

  test.insert( "5", "testingFind" );
  EXPECT_EQ( test[0], "testingFind" );

}
*/
//Erasing a key that exists in the map succeeds and decrements the map size
TEST(MapTest, eraseOfExistingKeyReturnsTrueAndDecrementsSize)
{
  Map test;

  test.insert( "7", "Plumlee7" );
  test.insert( "7B", "Plumlee7B" );
  test.insert( "7C", "Plumlee7C" );
  cout << test << endl;

  EXPECT_EQ( 3, test.size() );
  EXPECT_TRUE( test.erase("7") );

  EXPECT_EQ( 2, test.size() );
  EXPECT_TRUE( test.erase("7B") );

  EXPECT_EQ( 1, test.size() );
  EXPECT_TRUE( test.erase("7C") );

  EXPECT_EQ( 0, test.size() );
}

//Erase on an empty map fails and keeps the map size at zero
TEST(MapTest, eraseOnEmptyMapReturnsFalseAndSizeRemainsZero)
{
  Map test;

  EXPECT_FALSE( test.erase("8") );
  EXPECT_EQ( 0, test.size() );
}

//Erase of a non-existant key fails and does not change the map size
TEST(MapTest, eraseOfMissingKeyReturnsFalseAndSizeRemainsSame)
{
  Map test;

  test.insert( "9", "Plumlee9" );
  test.insert( "10", "Plumlee10" );

  EXPECT_FALSE( test.erase("a") );
  EXPECT_EQ( 2, test.size() );
}

//Using the copy constructor results in two maps of the same, correct size
TEST(MapTest, copyConstructorMakesCorrectSize)
{
  Map test;

  test.insert( "11", "Plumlee11" );
  test.insert( "12", "Plumlee12" );

  Map test2(test);

  EXPECT_EQ( test.size(), test2.size() );
  EXPECT_EQ( 2, test2.size() );
}

//Using the copy constructor with an existing map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, copyConstructorMakesSeparateCopy)
{
  Map test;

  test.insert( "13", "Plumlee13" );
  test.insert( "13B", "Plumlee13B" );
  test.insert( "13C", "Plumlee13C" );

  Map test2(test);

  test2["13"] = "Plumlee13";

  EXPECT_EQ( "Plumlee13", test["13"] );
  test2.insert( "13D", "Plumlee13D" );
  EXPECT_EQ( 3, test.size() );

  test2.erase( "13D" );
  EXPECT_EQ( 3, test.size() );

  test.insert( "13D", "Plumlee13D" );
  EXPECT_EQ( 3, test2.size() );

  test.erase("13D");
  EXPECT_EQ( 3, test2.size() );

}

//Using the assignment operator results in two maps of the same, correct size
TEST(MapTest, assignmentOperatorMakesCorrectSize)
{
  Map test;

  test.insert( "14", "Plumlee14" );
  test.insert( "15", "Plumlee15" );

  Map test2 = test;

  EXPECT_EQ( test.size(), test2.size() );
  EXPECT_EQ( 2, test.size() );
  EXPECT_EQ( 2, test2.size() );
}

//Using the assignment operator with an existing map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, assignmentMakesSeparateCopy)
{
  Map test;

  test.insert( "16", "Plumlee16" );
  test.insert( "17", "Plumlee17" );

  Map test2 = test;

  test2["18"] = "Plumlee18";
  EXPECT_EQ( "Plumlee16", test["16"] );
  test2.insert( "19", "Plumlee19" );
  EXPECT_EQ( 2, test.size() );
  test2.erase( "19" );

  EXPECT_EQ( 2, test.size() );
  test.insert( "20", "Plumlee20" );
  EXPECT_EQ( 3, test2.size() );
  test.erase( "20" );

  EXPECT_EQ( 3, test2.size() );
}

//Using the assignment operator with an existing map with over 1000 items
//makes a copy that has correct keys/values at a couple of places deep within
//the map (values that aren't at either end of the range of keys used).
TEST(MapTest, assignmentWithManyItemsHasCorrectValues)
{
  Map test, test2;
  string str, str2, str3;

  for( int i = 0; i < 1001; i++ ){
    str = to_string(i);
    str2 = to_string(i);
    test.insert( str, str2 );
  }

  EXPECT_EQ( test.size(), 1001 );
  test2 = test;
  EXPECT_EQ( test2.size(), 1001 );

  for( int i = 0; i < 10; i++ ){
    str3 = to_string(i);
    EXPECT_EQ( test2[str3], str3 );
    EXPECT_EQ( test2[str3], test[str3] );
  }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
