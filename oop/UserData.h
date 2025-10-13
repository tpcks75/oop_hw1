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
		const char* pszSupplier);
	~CUserData(void);

	//getter
	const char* getName(void) const { return strName; }
	const char* getIdt(void) const { return strIdt; }
	const char* getCategorytmp(void) const { return strCategory; }
	const char* getDepartment(void) const { return strExpr; }
	const char* getSupplier(void) const { return strSupplier; }

	// �й� ��4�ڸ�(���г⵵) ���ڿ� ��ȯ
	const char* getAdmissionYear(void);


	static int getUserDataCounter(void) { return nUserDataCounter; }

	//��ü ����
protected:
	CMyString strName;        // �̸� (15char)
	CMyString strIdt;   // �й� (10char)
	CMyString strCategory;   // ���� (4char)
	CMyString strExpr;  // �а���
	CMyString strSupplier;         // ��ȭ��ȣ (�ִ� 12�ڸ�)
	// �ش� ��ȿ�� �������� ���� �� �ٽ� �Է¹ޱ�
	// �̸�, �й� �����̾ �ȵ�
	// ���� �й� ����(key��)
	// ���� �й��� �� Error : Already inserted ���

	static int nUserDataCounter;

public:
	// ���� ���� �Լ��� ����
	// ���Ű(�̸�) ��ȯ
	virtual const char* getKey(void);
	// ��� ���� ���
	virtual void printNode(void);

};