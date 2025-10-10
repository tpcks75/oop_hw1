#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode Ŭ������ �Ļ� Ŭ������ ����
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
	// ���� ���� �Լ��� ����
	// ���Ű(�̸�) ��ȯ
	virtual const char* getKey(void);
	// ��� ���� ���
	virtual void printNode(void);

};