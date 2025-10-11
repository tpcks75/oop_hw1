#include "MyList.h"
#include "UserData.h"
#include "CListFinder.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

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

	// StudentID 기반 중복 체크 결과가 1개라도 있으면 중복
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

/* NodeList.cpp에서 구현
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
		// StudentID가 key
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


void CMyList::sortByID()
{
	// 0개 또는 1개면 정렬 불필요
	if (m_pHead == nullptr || m_pHead->pNext == nullptr || m_pHead->pNext->pNext == nullptr) {
		printf("정렬할 데이터가 없습니다. (0개 또는 1개)\n");
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
				// 링크 스왑: prev -> next -> curr -> ...
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

	// ===== 정렬 결과 출력 =====
	// (CMyList의 열거자/이터레이터를 이용해 순회 출력)
	// makeIterator는 CMyList 멤버라 내부에서 바로 사용 가능 :contentReference[oaicite:1]{index=1}
	CMyIterator it = makeIterator();
	CUserData* pNode = nullptr;

	printf("\n==== 이름 오름차순 정렬 결과 ===============\n");
	while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
		pNode->printNode();   // 각 노드의 출력 루틴 사용 :contentReference[oaicite:2]{index=2}:contentReference[oaicite:3]{index=3}
		it.MoveNext();
	}
	printf("============================================\n");
	fflush(stdout);

	printf("아무 키나 누르면 메뉴로 돌아갑니다...\n");
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

/* CListFinder 생성으로 인한 주석처리
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
	// 학번 앞 4자리를 입학년도라고 가정 (예: 2023xxxxxx)
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

/* 노드 출력->CListPrinter로 이관
void CMyList::printAll()
{
	
	if (m_pHead->pNext == nullptr) {
		printf("리스트가 비어 있습니다.\n");
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