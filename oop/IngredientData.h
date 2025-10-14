#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode Ŭ������ �Ļ� Ŭ������ ����
class CIngredientData : public CMyNode
{
	//������
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

	// �й� ��4�ڸ�(���г⵵) ���ڿ� ��ȯ
	const char* getAdmissionYear(void);

	static int getIngredientDataCounter(void) { return nIngredientDataCounter; }

	//��ü ����
protected:
	CMyString strName;        // ����̸�
	CMyString strIdt;   // ��� �ĺ���
	CMyString strCategory;   // ��� �з�
	CMyString strExpr;  // �������
	CMyString strSupplier; //��� ����ó
	CMyString strCount; // ����
	CMyString strPrice; // �ܰ�

	// �̸�, �й� �����̾ �ȵ�
	// ���� �ĺ��� ���� - (key��)
	// ���� �ĺ����� �� Error : Already inserted ���


	static int nIngredientDataCounter;

public:
	// ���� ���� �Լ��� ����
	// ���Ű(�̸�) ��ȯ
	virtual const char* getKey(void);
	// ��� ���� ���
	virtual void printNode(void);

};