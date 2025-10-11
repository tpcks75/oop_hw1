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

	CMyNode* findByName(const char* pszName);
	CMyNode* findByStudentID(const char* pszID);
	CMyNode* findByAdmissionYear(const char* pszYear);
	CMyNode* findByBirth(const char* pszBirth);
	CMyNode* findByDept(const char* pszDept);


	// ��� �߰� , �̹� ���� �� 0, �̸� ���� ���� �Է� �� -1 ��ȯ
	int addNewNode(CMyNode *pNewNode);

	//��� ����
	int removeNode(const char* pszKey);

	// ��� �̸����� ��������
	void sortByID();

	// ��带 ��ȸ�ϱ� ���� �����ڸ� ����
	CMyIterator makeIterator(void);

	// �����Ͱ� �߰��� ������ ȣ��Ǵ� ���� �Լ� ��� �̱���
	virtual int onAddNewNode(CMyNode* pNewNode);

	//��� ���
	void printAll();
};