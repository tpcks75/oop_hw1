#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode 클래스의 파생 클래스로 변경
class CUserData : public CMyNode
{
public:
	CUserData(void);
	CUserData(const char* pszName, const char* pszPhone);
	~CUserData(void);

	const char* getName(void) const { return strName; }
	const char*	getPhone(void) const { return strPhone; }
	static int getUserDataCounter(void) { return nUserDataCounter; }

protected:
	CMyString strName;
	CMyString strPhone;

	static int nUserDataCounter;

public:
	// 순수 가상 함수들 정의
	// 노드키(이름) 반환
	virtual const char* getKey(void);
	// 노드 정보 출력
	virtual void printNode(void);

};