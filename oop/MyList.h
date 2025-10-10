#pragma once
#include "MyNode.h"
#include "MyIterator.h"

class CMyList
{
public:
	CMyList(void);
	~CMyList(void);

protected:
	// 리스트 해제
	void releaseList(void);
	// single linked list 구현을 위한 헤드 포인터
	CMyNode *m_pHead;

public:
	// 노드 검색
	CMyNode* findNode(const char* pszKey);

	// 노드 추가 , 이미 존재 시 0, 이름 외의 문자 입력 시 -1 반환
	int addNewNode(CMyNode *pNewNode);

	//노드 삭제
	int removeNode(const char* pszKey);

	// 노드 이름기준 버블정렬
	void sortByName();

	// 노드를 순회하기 위한 열거자를 생성
	CMyIterator makeIterator(void);

	// 데이터가 추가될 때마다 호출되는 가상 함수 기능 미구현
	virtual int onAddNewNode(CMyNode* pNewNode);
};