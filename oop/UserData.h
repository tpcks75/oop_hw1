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

	// �й� ��4�ڸ�(���г⵵) ���ڿ� ��ȯ
	const char* getAdmissionYear(void);


	static int getUserDataCounter(void) { return nUserDataCounter; }

	//��ü ����
protected:
	CMyString strName;        // �̸� (15char)
	CMyString strStudentID;   // �й� (10char)
	CMyString strBirth;   // ���� (4char)
	CMyString strDept;  // �а���
	CMyString strTel;         // ��ȭ��ȣ (�ִ� 12�ڸ�)
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