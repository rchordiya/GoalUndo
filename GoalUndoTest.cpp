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

TEST(GoalUndoTest,addOperationwith_bothStringsEmpty)
{
  GoalUndo x;
  string str="";
  string str1="";
  string test="";
	x.addOperation(str,str1);
  ASSERT_EQ(test,x.getGoal());
}

TEST(GoalUndoTest,addOperationwith_GoalStringEmpty)
{
  GoalUndo x;
  string str="";
  string str1="Intelligent";
  string test="";
	x.addOperation(str,str1);
  ASSERT_EQ(test,x.getOperations());
}

TEST(GoalUndoTest,addOperationwith_OpsStringEmpty)
{
  GoalUndo x;
  string str="Computer";
  string str1="";
  string test="";
	x.addOperation(str,str1);
  ASSERT_EQ(test,x.getGoal());
}

TEST(GoalUndoTest,addOperationwith_bothStringsValid)
{
  GoalUndo x;
  string str="Job";
  string str1="Hard work";
  string str3="Business";
	x.addOperation(str,str1);
  x.addOperation(str3,str1);
  ASSERT_EQ(str1,x.getOperations());
}
