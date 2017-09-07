#pragma once 

#include <heap.h>
#include <cstddef>
#include "sf_function.h"

namespace sortutil
{
	template<class T>
	void swap(T& left, T& right)
	{
		T temp(left);
		left = right;
		right = temp;
	}
}



template<class T, class Comp>
void InsertionSort(T* arrData, size_t nCount,  Comp comp)
{
	if (nCount <= 1 || NULL == arrData)
	{
		return ;
	}
	for (int i = 1; i < nCount ; ++i)
	{
		const T key = arrData[i];
		int j = i - 1;
		while(j >= 0 && comp(key ,arrData[j]))
		{
			arrData[j+1] = arrData[j];
			--j;
		}
		arrData[j+1] = key;
	}
}

template<class T>
void InsertionSort(T* arrData, size_t nCount)
{
	InsertionSort(arrData, nCount, LessCompare<T>());
}


template<class T, class Comp>
void SelectSort(T* arrData, size_t nCount, Comp comp)
{
	for (int i = 0; i < nCount; ++i)	// n+1
	{
		int k = i;			// n
		for (int j = i; j < nCount ; ++j)	// (n+1) + n + (n-1) + (n-2) + ... + 1
		{
			if (comp(arrData[j], arrData[k]))	// n + (n-1) + ...+1
			{
				k = j;	// <= n + (n-1) + ...+1
			}
		}
		T temp = arrData[i];	// n 
		arrData[i] = arrData[k];
		arrData[k] = temp;
	}
}

template<class T>
void SelectSort(T* arrData, size_t nCount )
{
	SelectSort(arrData, nCount, LessCompare<T>());
}

template<class T, class Comp>
void Merge(T* pArrary, size_t left, size_t middle, size_t right, Comp comp)
{
	int nCountL = middle - left + 1;
	int nCountR = right - middle;
	int nCount = nCountL + nCountR;
	T* arrLeft = new T[nCountL];
	T* arrRight = new T[nCountR];
	for (int i = 0; i < nCountL; ++i)
	{
		arrLeft[i] = pArrary[left+i];
	}
	for (int i = 0; i < nCountR; ++i)
	{
		arrRight[i] = pArrary[middle+1+i];
	}

	int j = 0, k = 0;
	for (int i = 0; i < nCount; ++i)
	{
		if (j >= nCountL )
		{
			pArrary[left+i] = arrRight[k++];
		}
		else if (k >= nCountR || comp(arrLeft[j], arrRight[k]))
		{
			pArrary[left+i] = arrLeft[j++];
		}
		else 
		{
			pArrary[left+i] = arrRight[k++];
		}
	}
}

template<class T, class Comp>
class ReverseComp
{
public:
	ReverseComp(){
		this->comp = Comp();
	}
	const bool operator()(const T& left, const T& right) const
	{
		return !comp(left, right);
	}
private:
	Comp comp;
};

template<class T, class Comp>
void HeapSort(T* arrData, size_t nCount)
{
	typedef ReverseComp<T, Comp>  MyComp;
	Heap_Build<T, MyComp>(arrData, nCount);
	size_t nHeapSize = nCount;
	while (nHeapSize > 1)
	{
		using std::swap;
		swap(arrData[0], arrData[nHeapSize - 1]);
		Heap_Heapify<T, MyComp>(arrData, nHeapSize-1, 0);
		--nHeapSize;
	}
}
