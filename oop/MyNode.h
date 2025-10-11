#pragma once

class CMyNode
{
	friend class CMyList;
	friend class CListFinder; 
public:
	CMyNode(void);
	virtual ~CMyNode(void);

	// ������ �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const char* getKey(void) = 0;
	virtual void printNode(void) = 0;

	// pNext ������ ���� getter,setter �Լ�
	CMyNode* getNext() const { return pNext; }
	void setNext(CMyNode* p) { pNext = p; }

private:
	// ���� ����Ʈ ��ü�� ���� ���
	CMyNode *pNext;
};
