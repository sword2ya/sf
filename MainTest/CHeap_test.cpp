/*
 * CHeap_test.cpp
 *
 *  Created on: 2017年9月7日
 *      Author: us
 */

#include <gtest/gtest.h>
#include <heap.h>

static const size_t TEST_COUNT = 1000;
void GenOrderedArray(int *arrData, size_t nCount) {
	for (size_t i = 0; i < nCount; ++i) {
		arrData[i] = i;
	}
}
void GenReverseOrderedArray(int* arrData, size_t nCount) {
	for (size_t i = 0; i < nCount; ++i) {
		arrData[i] = nCount - i - 1;
	}
}
void GenMiscOrderedArray(int *arrData, size_t nCount) {
	for (size_t i = 0; i < nCount; ++i) {
		arrData[i] = abs((int) i - (int) nCount / 2);
	}
}

typedef void (*GenArray)(int *arrData, size_t nCount);

class CHeapTest: public testing::Test {
protected:
	void BuildTest_Template(GenArray fnGenArray) {
		int arrData[TEST_COUNT];
		fnGenArray(arrData, TEST_COUNT);
		CHeap<int> oHeap;
		oHeap.Build(arrData, TEST_COUNT);

		TestHeapify(oHeap, TEST_COUNT);
	}
	void TestHeapify(CHeap<int> &oHeap, size_t nCount) {
		if (nCount == 0) {
			return;
		}
		int nLastData;
		ASSERT_TRUE(oHeap.ExtractTop(nLastData));
		size_t i = 0;
		while (i < nCount - 1) {
			int nData;
			ASSERT_TRUE(oHeap.ExtractTop(nData))<< " Index:"<< i+1;
			ASSERT_GE(nData, nLastData)<< " Index:"<< i+1;
			nLastData = nData;
			++i;
		}
		int x;
		ASSERT_FALSE(oHeap.ExtractTop(x));
	}
};

TEST_F(CHeapTest, BuildTest_1) {
	BuildTest_Template(GenOrderedArray);
}
TEST_F(CHeapTest, BuildTest_2) {
	BuildTest_Template(GenReverseOrderedArray);
}
TEST_F(CHeapTest, BuildTest_3) {
	BuildTest_Template(GenMiscOrderedArray);
}

TEST_F(CHeapTest, InsertTest_1) {
	int arrData[TEST_COUNT];
	GenOrderedArray(arrData, TEST_COUNT);
	CHeap<int> oHeap;
	oHeap.Build(arrData, TEST_COUNT);

	for (size_t i = 0; i < 2 * TEST_COUNT; ++i) {
		oHeap.Insert(i);
	}
	TestHeapify(oHeap, 3 * TEST_COUNT);
}

TEST_F(CHeapTest, IncreaseTest_1) {
	int arrData[TEST_COUNT];
	GenOrderedArray(arrData, TEST_COUNT);
	CHeap<int> oHeap;
	oHeap.Build(arrData, TEST_COUNT);

	for (size_t i = 0; i < TEST_COUNT; ++i) {
		ASSERT_TRUE(oHeap.Modify(i, i + arrData[TEST_COUNT - 1]));
	}
	TestHeapify(oHeap, TEST_COUNT);
}

