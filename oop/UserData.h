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
		const char* pszStudentID,
		const char* pszBirth,
		const char* pszDept,
		const char* pszTel);
	~CUserData(void);

	//getter
	const char* getName(void) const { return strName; }
	const char* getStudentID(void) const { return strStudentID; }
	const char* getBirthYear(void) const { return strBirth; }
	const char* getDepartment(void) const { return strDept; }
	const char* getTel(void) const { return strTel; }

	// 학번 앞4자리(입학년도) 문자열 반환
	const char* getAdmissionYear(void);


	static int getUserDataCounter(void) { return nUserDataCounter; }

	//객체 생성
protected:
	CMyString strName;        // 이름 (15char)
	CMyString strStudentID;   // 학번 (10char)
	CMyString strBirth;   // 생년 (4char)
	CMyString strDept;  // 학과명
	CMyString strTel;         // 전화번호 (최대 12자리)
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