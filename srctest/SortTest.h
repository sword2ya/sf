#include "gtest/gtest.h"
#include "sort.h"


namespace sorttest
{
	typedef void (*SortFunc)(int *, size_t);
}

class CSortTest : public testing::Test
{
public:
	CSortTest();
	~CSortTest();
protected:
	void TestTemplate(sorttest::SortFunc pSortFunc, bool bLess );
	void InitData_Ordered(size_t nCount, int** pArrData, bool bLess );
	void InitData_ReverseOrdered(size_t nCount, int** pArrData, bool bLess );
	void InitData_Misc(size_t nCount, int ** pArrData);
	bool CheckOrder(const int* pArrData, size_t nCount, bool bLess);
};

