/*
 * heap.h
 *
 *  Created on: 2017年9月7日
 *      Author: us
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "sf_function.h"
#include <algorithm>
#include <cstddef>
#include <vector>

using std::swap;

inline int Heap_Left(size_t nIndex) {
	return 2 * nIndex + 1;
}
inline int Heap_Right(size_t nIndex) {
	return 2 * nIndex + 2;
}
inline int Heap_Parent(size_t nIndex) {
	if (nIndex == 0) {
		return -1;
	}
	return (nIndex - 1) / 2;
}

template<class T, class Comp>
void Heap_Heapify(T* arrData, size_t nCount, size_t nIndex) {
	Comp comp;
	while (nIndex < nCount) {
		T data = arrData[nIndex];
		int nLeft = Heap_Left(nIndex);
		int nRight = Heap_Right(nIndex);

		bool bLeftSwap = false;
		bool bRightSwap = false;
		if (nLeft < nCount) {
			if (comp(arrData[nLeft], data)) {
				bLeftSwap = true;
				data = arrData[nLeft];
			}
		}
		if (nRight < nCount) {
			if (comp(arrData[nRight], data)) {
				bRightSwap = true;
				data = arrData[nRight];
			}
		}
		using std::swap;
		if (bRightSwap) {
			swap(arrData[nRight], arrData[nIndex]);
			nIndex = nRight;
		} else if (bLeftSwap) {
			swap(arrData[nLeft], arrData[nIndex]);
			nIndex = nLeft;
		} else {
			return;
		}
	}
}

template<class T, class Comp>
void Heap_UperHeapify(T* arrData, size_t nIndex) {
	Comp comp;
	int n = (int) nIndex;
	while (n > 0) {
		int nParent = Heap_Parent(n);
		if (nParent > 0 && comp(arrData[n], arrData[nParent])) {
			using std::swap;
			swap(arrData[n], arrData[nParent]);
			n = nParent;
		} else {
			break;
		}
	}
}

template<class T, class Comp>
void Heap_Build(T* arrData, size_t nCount) {
	for (int n = (int) (nCount - 1) / 2; n >= 0; --n) {
		Heap_Heapify<T, Comp>(arrData, nCount, n);
	}
}

template<class T, class Comp>
bool Heap_Modify(T* arrData, size_t nCount, size_t nIndex, const T& data) {
	if (nIndex >= nCount) {
		return false;
	}
	arrData[nIndex] = data;
	Comp comp;
	int nParent = Heap_Parent(nIndex);
	if (nParent >= 0 && comp(arrData[nIndex], arrData[nParent])) {
		Heap_UperHeapify<T, Comp>(arrData, nIndex);
	} else {
		Heap_Heapify<T, Comp>(arrData, nCount, nIndex);
	}
	return true;
}

/**
 *  子节点和父节点满足 Comp(sub, parent)为false
 */
template<class T, class Comp = LessCompare<T> >
class CHeap {
public:
	CHeap() {
	}
	~CHeap() {
	}
public:
	void Build(T* arrData, size_t nCount) {
		m_vtData.clear();
		if (nCount == 0) {
			return;
		}
		for (size_t i = 0; i < nCount; ++i) {
			m_vtData.push_back(arrData[i]);
		}
		Heap_Build<T, Comp>(&m_vtData[0], nCount);
	}
	void Insert(const T& data) {
		m_vtData.push_back(data);
		size_t nIndex = m_vtData.size() - 1;
		Heap_UperHeapify<T, Comp>(&m_vtData[0], nIndex);
	}
	bool ExtractTop(T& data) {
		if (!Top(data)) {
			return false;
		}
		m_vtData[0] = m_vtData.back();
		m_vtData.pop_back();
		if (!m_vtData.empty())
		{
			Heap_Heapify<T, Comp>(&m_vtData[0], m_vtData.size(), 0);
		}

		return true;
	}
	bool Top(T& data) {
		if (m_vtData.empty()) {
			return false;
		}
		data = m_vtData[0];
		return true;
	}
	bool Modify(size_t nIndex, const T& data) {
		if (m_vtData.empty()) {
			return false;
		}
		return Heap_Modify<T, Comp>(&m_vtData[0], m_vtData.size(), nIndex, data);
	}
private:
	std::vector<T> m_vtData;
};

#endif /* HEAP_H_ */
