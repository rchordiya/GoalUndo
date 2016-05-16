/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
#include<string>
using namespace std;

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest,addOperationwith_Noexistinggoal)
{
  GoalUndo x;
  string str="sucess";
	x.addOperation(str);
  ASSERT_EQ(str,x.getGoal());
}

TEST(GoalUndoTest,addOperationwith_emptyString)
{
  GoalUndo x;
  string str="";
	x.addOperation(str);
  ASSERT_EQ(str,x.getGoal());
}

TEST(GoalUndoTest,addOperationwith_existingGoal)
{
  GoalUndo x;
  string str="Computer";
  string str1="reliable";
	x.addOperation(str);
  x.addOperation(str1);
  ASSERT_EQ(str,x.getGoal());
}
