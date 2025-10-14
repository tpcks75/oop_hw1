#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode 클래스의 파생 클래스로 변경
class CIngredientData : public CMyNode
{
	//생성자
public:
	CIngredientData(void);
	CIngredientData(const char* pszName,
		const char* pszIdt,
		const char* pszCategory,
		const char* pszExpr,
		const char* pszSupplier,
		const char* nCount,
		const char* price);
	~CIngredientData(void);

	//getter
	const char* getName(void) const { return strName; }
	const char* getIdt(void) const { return strIdt; }
	const char* getCategorytmp(void) const { return strCategory; }
	const char* getExpr(void) const { return strExpr; }
	const char* getSupplier(void) const { return strSupplier; }
	const char* getCount(void) const { return strCount; }
	const char* getPrice(void) const { return strPrice; }

	// 학번 앞4자리(입학년도) 문자열 반환
	const char* getAdmissionYear(void);

	static int getIngredientDataCounter(void) { return nIngredientDataCounter; }

	//객체 생성
protected:
	CMyString strName;        // 재료이름
	CMyString strIdt;   // 재료 식별자
	CMyString strCategory;   // 재료 분류
	CMyString strExpr;  // 유통기한
	CMyString strSupplier; //재료 공급처
	CMyString strCount; // 개수
	CMyString strPrice; // 단가

	// 이름, 학번 공백이어선 안됨
	// 같은 식별자 금지 - (key값)
	// 같은 식별자일 시 Error : Already inserted 출력


	static int nIngredientDataCounter;

public:
	// 순수 가상 함수들 정의
	// 노드키(이름) 반환
	virtual const char* getKey(void);
	// 노드 정보 출력
	virtual void printNode(void);

};