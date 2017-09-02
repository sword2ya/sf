#include "SortTest.h"
#include <time.h>
#include <stdio.h>

using namespace sorttest;

CSortTest::CSortTest()
{
}

CSortTest::~CSortTest()
{

}

void CSortTest::InitData_Ordered(size_t nCount, int** pArrData, bool bLess)
{
	*pArrData = new int[nCount];
	for (int i = 0; i < nCount; ++i)
	{
		(*pArrData)[i]  = bLess ?  i :  nCount-i-1;
	}
}

void CSortTest::InitData_ReverseOrdered(size_t nCount, int** pArrData, bool bLess )
{
	InitData_Ordered(nCount, pArrData, !bLess);
}

bool CSortTest::CheckOrder(const int* pArrData, size_t nCount, bool bLess)
{
	for (int i = 1; i < nCount ; ++i)
	{
		if (bLess != (pArrData[i-1] < pArrData[i]))
		{
			return false;
		}
	}
	return true;
}
void CSortTest::InitData_Misc(size_t nCount, int ** pArrData)
{
	srand(time(NULL));
}


void CSortTest::TestTemplate(SortFunc pSortFunc, bool bLess )
{
	int* pArrData = NULL;
	const size_t nCount = 100;

	{
		InitData_Ordered(nCount, &pArrData, bLess );
		pSortFunc(pArrData, nCount);
		ASSERT_TRUE(CheckOrder(pArrData, nCount, bLess ));
		delete pArrData;
		pArrData = NULL;
	}
	{
		InitData_ReverseOrdered(nCount, &pArrData, bLess );
		pSortFunc(pArrData, nCount);
		ASSERT_TRUE(CheckOrder(pArrData, nCount, bLess));
		delete pArrData; 
		pArrData = NULL;
	}
}

// Test Insertion Sort
void InsertionSortLess(int *pArrData, size_t nCount)
{
	InsertionSort(pArrData, nCount, LessCompare<int>());
}
void InsertionSortGreater(int *pArrData, size_t nCount)
{
	InsertionSort(pArrData, nCount, GreaterCompare<int>());
}
TEST_F(CSortTest, InsertionSort_Less)
{
	TestTemplate(InsertionSortLess, true);
}

TEST_F(CSortTest, InsertionSort_Greater)
{
	TestTemplate(InsertionSortGreater, false);
}


// Test Select Sort
void SelectSortLess(int *pArrData, size_t nCount)
{
	SelectSort(pArrData, nCount, LessCompare<int>());
}
void SelectSortGreater(int *pArrData, size_t nCount)
{
	SelectSort(pArrData, nCount, GreaterCompare<int>());
}

TEST_F(CSortTest, SelectSort_Less)
{
	TestTemplate(SelectSortLess, true);
}

TEST_F(CSortTest, SelectSort_Greater)
{
	TestTemplate(SelectSortGreater, false);
}