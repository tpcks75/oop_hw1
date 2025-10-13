#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode 클래스의 파생 클래스로 변경
class CUserData : public CMyNode
{
	//생성자
public:
	CUserData(void);
	CUserData(const char* pszName,
		const char* pszIdt,
		const char* pszCategory,
		const char* pszExpr,
		const char* pszSupplier);
	~CUserData(void);

	//getter
	const char* getName(void) const { return strName; }
	const char* getIdt(void) const { return strIdt; }
	const char* getCategorytmp(void) const { return strCategory; }
	const char* getDepartment(void) const { return strExpr; }
	const char* getSupplier(void) const { return strSupplier; }

	// 학번 앞4자리(입학년도) 문자열 반환
	const char* getAdmissionYear(void);


	static int getUserDataCounter(void) { return nUserDataCounter; }

	//객체 생성
protected:
	CMyString strName;        // 이름 (15char)
	CMyString strIdt;   // 학번 (10char)
	CMyString strCategory;   // 생년 (4char)
	CMyString strExpr;  // 학과명
	CMyString strSupplier;         // 전화번호 (최대 12자리)
	// 해당 유효값 충족하지 못할 시 다시 입력받기
	// 이름, 학번 공백이어선 안됨
	// 같은 학번 금지(key값)
	// 같은 학번일 시 Error : Already inserted 출력

	static int nUserDataCounter;

public:
	// 순수 가상 함수들 정의
	// 노드키(이름) 반환
	virtual const char* getKey(void);
	// 노드 정보 출력
	virtual void printNode(void);

};