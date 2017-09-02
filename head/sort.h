#pragma once 

#include <cstddef>


template<class T>
class LessCompare
{
public:
	bool operator()(const T& left, const T& right) const 
	{
		return left < right;
	}
};

template<class T>
class GreaterCompare 
{
public:
	bool operator( )( const T& left, const T& right) const 
	{
		return left > right;
	}
};

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