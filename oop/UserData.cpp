#include "UserData.h"
#include <cstdio>



int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
{
	nUserDataCounter++;
}
CUserData::CUserData(const char* pszName,
	const char* pszStudentID,
	const char* pszBirth,
	const char* pszDept,
	const char* pszTel)
	: strName(pszName),
	strStudentID(pszStudentID),
	strBirth(pszBirth),
	strDept(pszDept),
	strTel(pszTel) {
	nUserDataCounter++;
}

CUserData::~CUserData(void)
{
	nUserDataCounter--;
}

const char* CUserData::getKey(void)
{
	return this->strStudentID;
}

void CUserData::printNode(void)
{
#ifdef _DEBUG
	printf("[%p] %-15s %-10s %-10s %-20s %-12s [%p]\n",
		this,
		(const char*)strName,
		(const char*)strStudentID,
		(const char*)strBirth,
		(const char*)strDept,
		(const char*)strTel,
		getNext());
#else
	printf("%-15s %-10s %-10s %-20s %-12s\n",
		(const char*)strName,
		(const char*)strStudentID,
		(const char*)strBirth,
		(const char*)strDept,
		(const char*)strTel);
#endif
}