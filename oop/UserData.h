#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode Ŭ������ �Ļ� Ŭ������ ����
class CUserData : public CMyNode
{
	//������
public:
	CUserData(void);
	CUserData(const char* pszName,
		const char* pszIdt,
		const char* pszCategory,
		const char* pszExpr,
		const char* pszSupplier,
		const char* nCount,
		const char* price);
	~CUserData(void);

	//getter
	const char* getName(void) const { return strName; }
	const char* getIdt(void) const { return strIdt; }
	const char* getCategorytmp(void) const { return strCategory; }
	const char* getDepartment(void) const { return strExpr; }
	const char* getSupplier(void) const { return strSupplier; }
	const char* getCount(void) const { return strCount; }
	const char* getPrice(void) const { return strPrice; }

	// �й� ��4�ڸ�(���г⵵) ���ڿ� ��ȯ
	const char* getAdmissionYear(void);

	static int getUserDataCounter(void) { return nUserDataCounter; }

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


	static int nUserDataCounter;

public:
	// ���� ���� �Լ��� ����
	// ���Ű(�̸�) ��ȯ
	virtual const char* getKey(void);
	// ��� ���� ���
	virtual void printNode(void);

};