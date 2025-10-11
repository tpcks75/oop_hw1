#include "MyList.h"
#include "UserData.h"
#include "CListFinder.h"
#include "CLIstPrinter.h"
#include "SortType.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <algorithm>       // std::sort
#include <vector>


CMyList::CMyList()
{
	m_pHead = new CUserData("aaaaaaaaaaaaaaa", "0000000000", "0000", "None", "000-00000000");
}

CMyList::~CMyList(void)
{
	releaseList();
}

int CMyList::addNewNode(CMyNode *pNewNode)
{
	CListFinder finder(*this);
	auto results = finder.findByStudentID(pNewNode->getKey());

	// StudentID ��� �ߺ� üũ ����� 1���� ������ �ߺ�
	if (!results.empty())
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

/* NodeList.cpp���� ����
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




CMyNode* CMyList::findNode(const char* pszKey)
{
	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != nullptr)
	{
		// StudentID�� key
		if (strcmp(pTmp->getKey(), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

*/



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
/*
void CMyList::sortByID()
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
*/

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

// ����Ʈ�� ���ͷ� ��ȯ
std::vector<CMyNode*> CMyList::toVector() {
	std::vector<CMyNode*> vec;
	for (CMyNode* p = m_pHead->getNext(); p != nullptr; p = p->getNext()) {
		vec.push_back(p);
	}
	return vec;
}

// ���͸� ����Ʈ�� ��ȯ
void CMyList::fromVector(const std::vector<CMyNode*>& vec) {
	if (vec.empty()) return;
	m_pHead->setNext(vec[0]);
	for (size_t i = 0; i < vec.size() - 1; ++i)
		vec[i]->setNext(vec[i + 1]);
	vec.back()->setNext(nullptr);
}

// ���� �Լ�
void CMyList::sortBy(SortType type) {
	// ��� ��ȸ, �����̳� ����
	auto nodes = toVector();

	std::sort(nodes.begin(), nodes.end(), [type](CMyNode* a, CMyNode* b) {
		// �������ʵ� ������ ���� �ٿ�ĳ����
		CUserData* ua = static_cast<CUserData*>(a);
		CUserData* ub = static_cast<CUserData*>(b);

		switch (type) {
		case SortType::NAME:
			return strcmp(ua->getName(), ub->getName()) < 0;
		case SortType::ID:
			return strcmp(ua->getStudentID(), ub->getStudentID()) < 0;
		case SortType::BIRTH:
			return strcmp(ua->getBirthYear(), ub->getBirthYear()) < 0;
		case SortType::DEPT:
			return _stricmp(ua->getDepartment(), ub->getDepartment()) < 0;
		}
		return false;
		});

	fromVector(nodes);

	printf("\nSorting Completed!\n");

	/* ����	���� ����
	CListPrinter printer(*this);
	printer.printNodes(nodes);

	
	int choice;
	printf("\n[1] �����ϰ� ���ư���\n[2] �׳� ���ư���\nSelect: ");
	scanf_s("%d", &choice);

	if (choice == 1) {
		printer.saveToFile(nodes, "file1.txt");  //  file1.txt�� ����
	}

	printf("\nReturning to main menu...\n");
	_getch(); */
}




/* CListFinder �������� ���� �ּ�ó��
/////////////////////////////////////////////////  find node
CMyNode* CMyList::findByName(const char* pszName)
{
	for (CMyNode* pTmp = m_pHead->pNext; pTmp != nullptr; pTmp = pTmp->pNext)
	{
		CUserData* pUser = static_cast<CUserData*>(pTmp);
		if (strcmp(pUser->getName(), pszName) == 0)
			return pTmp;
	}
	return nullptr;
}

CMyNode* CMyList::findByStudentID(const char* pszID)
{
	for (CMyNode* pTmp = m_pHead->pNext; pTmp != nullptr; pTmp = pTmp->pNext)
	{
		CUserData* pUser = static_cast<CUserData*>(pTmp);
		if (strcmp(pUser->getStudentID(), pszID) == 0)
			return pTmp;
	}
	return nullptr;
}

CMyNode* CMyList::findByAdmissionYear(const char* pszYear)
{
	// �й� �� 4�ڸ��� ���г⵵��� ���� (��: 2023xxxxxx)
	for (CMyNode* pTmp = m_pHead->pNext; pTmp != nullptr; pTmp = pTmp->pNext)
	{
		CUserData* pUser = static_cast<CUserData*>(pTmp);
		const char* id = pUser->getStudentID();
		if (strncmp(id, pszYear, 4) == 0)
			return pTmp;
	}
	return nullptr;
}

CMyNode* CMyList::findByBirth(const char* pszBirth)
{
	for (CMyNode* pTmp = m_pHead->pNext; pTmp != nullptr; pTmp = pTmp->pNext)
	{
		CUserData* pUser = static_cast<CUserData*>(pTmp);
		if (strcmp(pUser->getBirthYear(), pszBirth) == 0)
			return pTmp;
	}
	return nullptr;
}

CMyNode* CMyList::findByDept(const char* pszDept)
{
	for (CMyNode* pTmp = m_pHead->pNext; pTmp != nullptr; pTmp = pTmp->pNext)
	{
		CUserData* pUser = static_cast<CUserData*>(pTmp);
		if (strcmp(pUser->getDepartment(), pszDept) == 0)
			return pTmp;
	}
	return nullptr;
}
*/

/* ��� ���->CListPrinter�� �̰�
void CMyList::printAll()
{
	
	if (m_pHead->pNext == nullptr) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	printf("\n%-15s %-10s %-10s %-20s %-12s\n",
		"Name", "StudentID", "Birth", "Department", "Tel");
	printf("---------------------------------------------------------------\n");

	CMyIterator it = makeIterator();
	CUserData* pNode = nullptr;

	while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
		pNode->printNode();
		it.MoveNext();
	}
	_getch();
}
*/