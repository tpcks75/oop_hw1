#pragma once
#include "MyNode.h"

class CMyIterator
{
	friend class CMyList;

public:
	CMyIterator();
	~CMyIterator();

	// 반복자 반환
	CMyNode* GetCurrent(void) const { return m_pCurrent; }
	// 반복자 다음 노드로 이동
	void MoveNext(void)
	{
		if (m_pCurrent != nullptr)
			m_pCurrent = m_pCurrent->getNext();
	}

private:
	CMyNode *m_pHead;
	CMyNode *m_pCurrent;
};