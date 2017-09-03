#include "gtest/gtest.h"
#include "sort.h"
#include <math.h>

class CMergeTest : public testing::Test
{
protected:
	void Merge(int *arrData, size_t nLeft, size_t nMiddle, size_t nRight)
	{
		::Merge(arrData, nLeft, nMiddle, nRight, LessCompare<int>());
	}
};

/**
 * Test Merge:
 * A : 1,3,5,7,9
 * B : 2,4,6,8,10
 */
TEST_F(CMergeTest, TestMerge_1_9_2_10)
{
	int arrA[10];
	for (int i = 0; i < 5; ++i)
	{
		arrA[i] = 2*i+1;
		arrA[i+5] = 2*i+2;
	}
	Merge(arrA, 0, 4, 9);
	for (int i = 0; i < 10; ++i)
	{
		ASSERT_EQ(arrA[i], i+1);		
	}
}

/**
 * Test Merge
 * A : 1,2,3,4,5
 * B : 1,2,3,4,5
 */
TEST_F(CMergeTest, TestMerge_1_5_1_5)
{
	int arrA[10];
	for (int i = 0; i < 5; ++i)
	{
		arrA[i] = i+1;
		arrA[i+5] = i+1;
	}
	Merge(arrA, 0, 4, 9);
	for (int i = 0; i < 10; ++i)
	{
		ASSERT_EQ(arrA[i], i/2 + 1);	
	}
}

/**
 * Test Merge
 * A : 1,1,1,1,2
 * B : 1,1,1,1,3
 */
TEST_F(CMergeTest, TestMerge_112_113)
{
	int arrA[10];
	for (int i = 0; i < 4; ++i)
	{
		arrA[i] = 1;
		arrA[i+5] = 1;
	}
	arrA[4] = 2;
	arrA[9] = 3;
	Merge(arrA, 0, 4, 9);
	for (int i = 0; i < 8; ++i)
	{
		ASSERT_EQ(arrA[i], 1);	
	}
	ASSERT_EQ(2,arrA[8]);
	ASSERT_EQ(3,arrA[9]);
}

/**
 * Test Merge 
 * A : 1,2,3,...,50
 * B : 2,3,4,...,51
 */
TEST_F(CMergeTest, TestMerge_1_50_2_100)
{
	int arrA[100];
	for (int i = 0; i < 50; ++i)
	{
		arrA[i] = i+1;
		arrA[i+50] = i+2;
	}
	Merge(arrA, 0, 49, 99);
	for (int i = 0; i < 100; ++i)
	{
		ASSERT_EQ(arrA[i], (i+1)/2+1);	
	}
}

/**
 * Test Merge
 * A : 1,3,5,7,9
 * B : 2,4,6,8,10,12
 */
TEST_F(CMergeTest, TestMerge_1_3_2_6)
{
	int arrA[11];
	for (int i = 0; i < 5; ++i)
	{
		arrA[i] = 2*i+1;
		arrA[i+5] = 2*i+2;
	}
	arrA[10] = 12;
	Merge(arrA, 0, 4, 10);
	for (int i = 0; i < 10; ++i)
	{
		ASSERT_EQ(arrA[i], i+1);	
	}
	ASSERT_EQ(arrA[10], 12);
}

/**
 * Test Merge
 * A : 1,3,5,7,9,11
 * B : 2,4,6,8,10
 */
TEST_F(CMergeTest, TestMerge_1_11_2_10)
{
	int arrA[11];
	for (int i = 0; i < 5; ++i)
	{
		arrA[i] = 2*i+1;
		arrA[i+6] = 2*i+2;
	}
	arrA[5] = 11;
	Merge(arrA, 0, 5, 10);
	for (int i = 0; i < 11; ++i)
	{
		ASSERT_EQ(arrA[i], i+1);	
	}
}