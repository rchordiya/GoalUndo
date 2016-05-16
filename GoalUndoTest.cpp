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

TEST(GoalUndoTest,getOperationSingleOpsreturned)
{
  GoalUndo x;
  string str="Job";
  string str1="Hard work";
	x.addOperation(str,str1);
  ASSERT_EQ(str1,x.getOperations());
}

TEST(GoalUndoTest,getOperationTwoOpsreturned)
{
  GoalUndo x;
  string str="Job";
  string str1="Hard work";
  string str2="Passion";
  string str3="Hard work Passion";
	x.addOperation(str,str1);
  x.addOperation(str2);
  ASSERT_EQ(str3,x.getOperations());
}

TEST(GoalUndoTest,getOperationTwoOpsreturnedwithSpaceslast)
{
  GoalUndo x;
  string str="Job";
  string str1="Hard work";
  string str2="Passion";
  string str3="Hard work Passion ";
	x.addOperation(str,str1);
  x.addOperation(str2);
  ASSERT_NE(str3,x.getOperations());
}

TEST(GoalUndoTest,getOperationemptyreturned)
{
  GoalUndo x;
  string str="";
  string str1="";
	x.addOperation(str,str1);
  ASSERT_EQ(str1,x.getOperations());
}

TEST(GoalUndoTest,getGoalnogoalsadded)
{
  GoalUndo x;
  string str="";
  ASSERT_EQ(str,x.getGoal());
}

TEST(GoalUndoTest,getGoalrecentlyAdded)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str2="Business";
  string str3="Passion";
  string str4="";
  string str5="Support";
  x.addOperation(str,str1);
  x.addOperation(str2,str3);
  x.addOperation(str4,str5);
  ASSERT_EQ(str2,x.getGoal());
}
