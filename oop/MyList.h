#pragma once
#include "MyNode.h"
#include "MyIterator.h"
#include "CListFinder.h"
#include "SortType.h"
#include <vector>

class CListFinder; // 전방 선언

class CMyList
{
	friend class CListFinder; // 리스트 검색 전용 클래스 (has-a 관계)

public:
	CMyList(void);
	~CMyList(void);

protected:
	// 리스트 해제
	void releaseList(void);
	// single linked list 구현을 위한 헤드 포인터
	CMyNode *m_pHead;
	CMyNode* m_pTail;

public:
	/* CListFinder 생성으로 인한 주석처리
	// Search를 위한 노드 검색
	CMyNode* findNode(const char* pszKey);
	CMyNode* findByName(const char* pszName);
	CMyNode* findByIdt(const char* pszID);
	CMyNode* findByAdmissionYear(const char* pszYear);
	CMyNode* findByCategory(const char* pszCategory);
	CMyNode* findByExpr(const char* pszExpr);
	*/

	// 리스트 노드포인터 반환 getter함수
	CMyNode* getHead() const { return m_pHead; }

	// 노드 추가 , 이미 존재 시 0, 이름 외의 문자 입력 시 -1 반환
	int addNewNode(CMyNode *pNewNode);

	//노드 삭제
	int removeNode(const char* pszKey);

	// 노드 이름기준 버블정렬
	//void sortByID();

	// 노드를 순회하기 위한 열거자를 생성
	CMyIterator makeIterator(void);

	// 데이터가 추가될 때마다 호출되는 가상 함수 기능 미구현
	virtual int onAddNewNode(CMyNode* pNewNode);

	//노드 출력
	void printAll();

	// 연결리스트 노드 -> 벡터노드 변환
	std::vector<CMyNode*> toVector();

	// 벡터노드 -> 연결리스트 노드 변환
	void fromVector(const std::vector<CMyNode*>& vec);

	//정렬
	void sortBy(SortType type);

};