#pragma once

class CMyNode
{
	friend class CMyList;
public:
	CMyNode(void);
	virtual ~CMyNode(void);

	CMyNode* getNext(void) const { return pNext; }

	// ������ �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const char* getKey(void) = 0;
	virtual void printNode(void) = 0;

private:
	// ���� ����Ʈ ��ü�� ���� ���
	CMyNode *pNext;
};
