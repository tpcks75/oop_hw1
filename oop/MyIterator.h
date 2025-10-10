#pragma once
#include "MyNode.h"

class CMyIterator
{
	friend class CMyList;

public:
	CMyIterator();
	~CMyIterator();

	// �ݺ��� ��ȯ
	CMyNode* GetCurrent(void) const { return m_pCurrent; }
	// �ݺ��� ���� ���� �̵�
	void MoveNext(void)
	{
		if (m_pCurrent != nullptr)
			m_pCurrent = m_pCurrent->getNext();
	}

private:
	CMyNode *m_pHead;
	CMyNode *m_pCurrent;
};