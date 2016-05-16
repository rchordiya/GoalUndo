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

//Doubt test case
TEST(GoalUndoTest,overloadedundoOps_Goalstatus)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str2="Business";
  string str3="Passion";
  string str4="politics";
  string str5="Support";
  string str6="";
  x.addOperation(str,str1);
  x.addOperation(str2,str3);
  x.addOperation(str4,str5);
  x.undoOperation(str5);
  ASSERT_EQ(str6,x.getGoal());

}

TEST(GoalUndoTest,overloaadedundoOps_OperationstatusSinlgeGoal)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str3="Passion";
  string str5="Support";
  string str6="";
  x.addOperation(str,str1);
  x.addOperation(str3);
  x.addOperation(str5);
  x.undoOperation(str5);
  string c="Hardwork Passion";
  ASSERT_EQ(c,x.getOperations());

}

TEST(GoalUndoTest,overloaadedundoOps_Operationnotfound)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str3="Passion";
  string str5="Support";
  string str6="Dedication";
  x.addOperation(str,str1);
  x.addOperation(str3);
  x.addOperation(str5);
  x.undoOperation(str6);
  string c="Hardwork Passion Support";
  ASSERT_EQ(c,x.getOperations());

}
TEST(GoalUndoTest,overloaadedundoOps_noGoals)
{
  GoalUndo x;
  string str="Job";
  x.undoOperation(str);
  string c="";
  ASSERT_EQ(c,x.getGoal());

}

TEST(GoalUndoTest,undoOpsnoGoals)
{
  GoalUndo x;
  x.undoOperation();
  string c="";
  ASSERT_EQ(c,x.getGoal());
}

TEST(GoalUndoTest,undoOps_singleGoalsingleOps)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  x.addOperation(str,str1);
  x.undoOperation();
  string c="";
  ASSERT_EQ(c,x.getGoal());
}

TEST(GoalUndoTest,undoOps_singleGoalmultipleOps)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str2="Dedication";
  string str3="Passion";
  x.addOperation(str,str1);
  x.addOperation(str2);
  x.addOperation(str3);
  x.undoOperation();
  x.undoOperation();
  string c="Hardwork";
  ASSERT_EQ(c,x.getOperations());
}

TEST(GoalUndoTest,undoOps_multipleGoalsmultipleOps)
{
  GoalUndo x;
  string str="Job";
  string s="Business";
  string str1="Hardwork";
  string str2="Dedication";
  string str3="Passion";
  string str4="Punctual";
  x.addOperation(str,str1);
  x.addOperation(str3);
  x.addOperation(s,str2);
  x.addOperation(str4);
  x.undoOperation();
  x.undoOperation();
  string c="Hardwork Passion";
  ASSERT_EQ(c,x.getOperations());
}

TEST(GoalUndoTest,undoGoalSinglegoalSingleOps)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  x.addOperation(str,str1);
  x.undoGoal();
  string c="";
  ASSERT_EQ(c,x.getGoal());
  ASSERT_EQ(c,x.getOperations());
}

TEST(GoalUndoTest,undoGoalEmptyGoal)
{
  GoalUndo x;
  x.undoGoal();
  string c="";
  ASSERT_EQ(c,x.getGoal());

}

TEST(GoalUndoTest,undoGoalSingleGoalMultipleOps)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str2="Passion";
  string str3="Dedication";
  x.addOperation(str,str1);
  x.addOperation(str2);
  x.addOperation(str3);
  x.undoGoal();
  string c="";
  ASSERT_EQ(c,x.getOperations());

}

TEST(GoalUndoTest,undoGoalMultipleGoals)
{
  GoalUndo x;
  string str="Job";
  string str1="Hardwork";
  string str2="Passion";
  string str3="Dedication";
  x.addOperation(str,str1);
  x.addOperation(str2,str3);
  x.undoGoal();
  string c="Hardwork";
  ASSERT_EQ(c,x.getOperations());

}
