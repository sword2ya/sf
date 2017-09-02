#include "SortTest.h"
#include "sort.h"

namespace sorttest
{
	class CSortTestTemplate 
	{
	public:
		CSortTestTemplate(size_t nCount) : m_nCount(nCount)
		{
			m_pData = new int(nCount);
		}

		virtual void FillData(int* arrData, size_t nCount)
		{
			for (int i = 0; i < nCount; ++i)
			{
				arrData[i] = nCount - i;
			}
		}

		virtual bool Test()
		{
			FillData(m_pData, m_nCount);
			Sort();
			return Check();
		}

		virtual void Sort()= 0;

		virtual bool Check()
		{
			int nLast = m_pData[0];
			for (int i = 1; i < m_nCount; ++i)
			{
				if (nLast > m_pData[i])
				{
					return false;
				}
				nLast = m_pData[i];
			}
			return true;
		}

	protected:
		int* GetDataArr()
		{return m_pData;}
		const size_t GetCount()  
		{return m_nCount;}

	private:
		int * m_pData;
		size_t m_nCount;
	};

	class CInsertionSortTest_100_1_Less : public CSortTestTemplate
	{
	public:
		CInsertionSortTest_100_1_Less(size_t nCount) : CSortTestTemplate(nCount){} 
		virtual void Sort()
		{InsertionSort(GetDataArr(), GetCount());}
	};

	class CInsertionSortTest_1_100_Greater : public CSortTestTemplate
	{
	public:
		CInsertionSortTest_1_100_Greater(size_t nCount) : CSortTestTemplate(nCount){}
		virtual void FillData(int* arrData, size_t nCount)
		{
			for (int i = 0; i < nCount; ++i)
			{
				arrData[i] =  i;
			}
		}
		virtual bool Check()
		{
			int* arrData = GetDataArr();
			size_t nCount = GetCount();
			int nLast = arrData[0];
			for (int i = 0; i < nCount; ++i)
			{
				if (nLast < arrData[i])
				{
					return false;
				}
				nLast = arrData[i];
			}
			return true;
		}
		virtual void Sort()
		{
			InsertionSort(GetDataArr(), GetCount(), GreaterCompare<int>());
		}

	};

	class CSelectSortTest_100_1_Less : public CSortTestTemplate
	{
	public:
		CSelectSortTest_100_1_Less(size_t nCount) : CSortTestTemplate(nCount){}
		virtual void Sort()
		{
			SelectSort(GetDataArr(), GetCount());
		}

	};


}

using namespace sorttest;


bool InsertionSortTest_100_1_Less()
{
	return CInsertionSortTest_100_1_Less(100).Test();
}
bool InsertionSortTest_1_100_Greater()
{
	return CInsertionSortTest_1_100_Greater(100).Test();
}

bool SelectSortTest_100_1_Less()
{
	return CSelectSortTest_100_1_Less(100).Test();
}
