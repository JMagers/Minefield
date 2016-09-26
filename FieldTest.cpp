/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isSafeFalse)
{
	Field minefield;
	
	minefield.placeMine(3,3);
	ASSERT_FALSE( minefield.isSafe(3,3) );
}

TEST(FieldTest, isSafeTrue)
{
	Field minefield;
	
	minefield.placeMine(3,4);
	ASSERT_TRUE( minefield.isSafe(3,3) );
}

TEST(FieldTest, revealAdjacentCenter)
{
	Field minefield;
  minefield.revealAdjacent(2,2);
	
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(2,2) );
}

TEST(FieldTest, revealAdjacentRight)
{
	Field minefield;
  minefield.revealAdjacent(2,2);

	ASSERT_EQ( EMPTY_SHOWN, minefield.get(3,2) );
}

TEST(FieldTest, revealAdjacentLeft)
{
	Field minefield;
  minefield.revealAdjacent(2,2);

	ASSERT_EQ( EMPTY_SHOWN, minefield.get(1,2) );
}

TEST(FieldTest, revealAdjacentAbove)
{
	Field minefield;
  minefield.revealAdjacent(2,2);

	ASSERT_EQ( EMPTY_SHOWN, minefield.get(2,1) );
}

TEST(FieldTest, revealAdjacentBellow)
{
	Field minefield;
  minefield.revealAdjacent(2,2);

	ASSERT_EQ( EMPTY_SHOWN, minefield.get(2,3) );
}
