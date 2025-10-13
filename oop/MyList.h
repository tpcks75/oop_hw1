#pragma once
#include "MyNode.h"
#include "MyIterator.h"
#include "CListFinder.h"
#include "SortType.h"
#include <vector>

class CListFinder; // ���� ����

class CMyList
{
	friend class CListFinder; // ����Ʈ �˻� ���� Ŭ���� (has-a ����)

public:
	CMyList(void);
	~CMyList(void);

protected:
	// ����Ʈ ����
	void releaseList(void);
	// single linked list ������ ���� ��� ������
	CMyNode *m_pHead;
	CMyNode* m_pTail;

public:
	/* CListFinder �������� ���� �ּ�ó��
	// Search�� ���� ��� �˻�
	CMyNode* findNode(const char* pszKey);
	CMyNode* findByName(const char* pszName);
	CMyNode* findByIdt(const char* pszID);
	CMyNode* findByAdmissionYear(const char* pszYear);
	CMyNode* findByCategory(const char* pszCategory);
	CMyNode* findByExpr(const char* pszExpr);
	*/

	// ����Ʈ ��������� ��ȯ getter�Լ�
	CMyNode* getHead() const { return m_pHead; }

	// ��� �߰� , �̹� ���� �� 0, �̸� ���� ���� �Է� �� -1 ��ȯ
	int addNewNode(CMyNode *pNewNode);

	//��� ����
	int removeNode(const char* pszKey);

	// ��� �̸����� ��������
	//void sortByID();

	// ��带 ��ȸ�ϱ� ���� �����ڸ� ����
	CMyIterator makeIterator(void);

	// �����Ͱ� �߰��� ������ ȣ��Ǵ� ���� �Լ� ��� �̱���
	virtual int onAddNewNode(CMyNode* pNewNode);

	//��� ���
	void printAll();

	// ���Ḯ��Ʈ ��� -> ���ͳ�� ��ȯ
	std::vector<CMyNode*> toVector();

	// ���ͳ�� -> ���Ḯ��Ʈ ��� ��ȯ
	void fromVector(const std::vector<CMyNode*>& vec);

	//����
	void sortBy(SortType type);

};