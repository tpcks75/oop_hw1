#pragma once

class CMyNode
{
	friend class CMyList;
	friend class CListFinder; 
public:
	CMyNode(void);
	virtual ~CMyNode(void);

	// 관리에 필요한 인터페이스 함수들을 순수 가상 함수로 선언
	virtual const char* getKey(void) = 0;
	virtual void printNode(void) = 0;

	// pNext 접근을 위한 getter,setter 함수
	CMyNode* getNext() const { return pNext; }
	void setNext(CMyNode* p) { pNext = p; }

private:
	// 연결 리스트 자체를 위한 멤버
	CMyNode *pNext;
};
