#include "UserData.h"
#include <cstdio>
#include <cstring>



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
	printf(" %-15s %-10s %-10s %-20s %-12s \n",
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

const char* CUserData::getAdmissionYear(void)
{
	static char szYear[5] = { 0 };  // 4자리 + null
	const char* id = strStudentID.getString();

	if (id == nullptr || std::strlen(id) < 4)
		return "";

	strncpy_s(szYear, id, 4);  // 앞 4자리 복사
	szYear[4] = '\0';          // null terminator
	return szYear;
}