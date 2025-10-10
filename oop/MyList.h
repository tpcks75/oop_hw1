#pragma once
#include "MyNode.h"
#include "MyIterator.h"

class CMyList
{
public:
	CMyList(void);
	~CMyList(void);

protected:
	// ����Ʈ ����
	void releaseList(void);
	// single linked list ������ ���� ��� ������
	CMyNode *m_pHead;

public:
	// ��� �˻�
	CMyNode* findNode(const char* pszKey);

	// ��� �߰� , �̹� ���� �� 0, �̸� ���� ���� �Է� �� -1 ��ȯ
	int addNewNode(CMyNode *pNewNode);

	//��� ����
	int removeNode(const char* pszKey);

	// ��� �̸����� ��������
	void sortByName();

	// ��带 ��ȸ�ϱ� ���� �����ڸ� ����
	CMyIterator makeIterator(void);

	// �����Ͱ� �߰��� ������ ȣ��Ǵ� ���� �Լ� ��� �̱���
	virtual int onAddNewNode(CMyNode* pNewNode);
};