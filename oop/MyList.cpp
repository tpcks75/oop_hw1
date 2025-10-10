#include "MyList.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

CMyList::CMyList()
{
	m_pHead = new CUserData("Dummy", "Head");
}

CMyList::~CMyList(void)
{
	releaseList();
}

int CMyList::addNewNode(CMyNode *pNewNode)
{
	if (findNode(pNewNode->getKey()) != nullptr)
	{
		delete pNewNode;
		return 0;
	}

	if(onAddNewNode(pNewNode))
	{
		pNewNode->pNext = m_pHead->pNext;
		m_pHead->pNext = pNewNode;

		return 1;
	}

	return -1;
}

/*
void CMyList::printAll(void)
{
	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != NULL)
	{
		pTmp->printNode();
		pTmp = pTmp->pNext;
	}

	printf("CUserData Counter : %d\n",
		CUserData::GetUserDataCounter() - 1);

	_getch();
}
*/

CMyNode* CMyList::findNode(const char* pszKey)
{
	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != nullptr)
	{
		if (strcmp(pTmp->getKey(), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

int CMyList::removeNode(const char* pszKey)
{
	CMyNode *pPrevNode = m_pHead;
	CMyNode *pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->getKey(), pszKey) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}


void CMyList::sortByName()
{
	// 0�� �Ǵ� 1���� ���� ���ʿ�
	if (m_pHead == nullptr || m_pHead->pNext == nullptr || m_pHead->pNext->pNext == nullptr) {
		printf("������ �����Ͱ� �����ϴ�. (0�� �Ǵ� 1��)\n");
		_getch();
		return;
	}

	bool swapped;
	do {
		swapped = false;

		CMyNode* prev = m_pHead;          
		CMyNode* curr = m_pHead->pNext;  

		while (curr != nullptr && curr->pNext != nullptr)
		{
			CMyNode* next = curr->pNext;

			const char* a = static_cast<CUserData*>(curr)->getKey();
			const char* b = static_cast<CUserData*>(next)->getKey();

			if (std::strcmp(a, b) > 0)
			{
				// ��ũ ����: prev -> next -> curr -> ...
				curr->pNext = next->pNext;
				next->pNext = curr;
				prev->pNext = next;

				swapped = true;
				prev = next; 
			}
			else
			{
				
				prev = curr;
				curr = next;
			}
		}
	} while (swapped);

	// ===== ���� ��� ��� =====
	// (CMyList�� ������/���ͷ����͸� �̿��� ��ȸ ���)
	// makeIterator�� CMyList ����� ���ο��� �ٷ� ��� ���� :contentReference[oaicite:1]{index=1}
	CMyIterator it = makeIterator();
	CUserData* pNode = nullptr;

	printf("\n==== �̸� �������� ���� ��� ===============\n");
	while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
		pNode->printNode();   // �� ����� ��� ��ƾ ��� :contentReference[oaicite:2]{index=2}:contentReference[oaicite:3]{index=3}
		it.MoveNext();
	}
	printf("============================================\n");
	fflush(stdout);

	printf("�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n");
	_getch();
}


void CMyList::releaseList(void)
{
	CMyNode *pTmp = m_pHead;
	CMyNode *pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_pHead = NULL;
}



CMyIterator CMyList::makeIterator(void)
{
	CMyIterator it;
	it.m_pCurrent = m_pHead->pNext;
	it.m_pHead = m_pHead->pNext;

	return it;
}

int CMyList::onAddNewNode(CMyNode* pNewNode)
{
	return 1;
}