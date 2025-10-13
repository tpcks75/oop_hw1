#include "UserData.h"
#include <cstdio>
#include <cstring>



int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
{
	nUserDataCounter++;
}
CUserData::CUserData(const char* pszName,
	const char* pszIdt,
	const char* pszCategory,
	const char* pszExpr,
	const char* pszSupplier)
	: strName(pszName),
	strIdt(pszIdt),
	strCategory(pszCategory),
	strExpr(pszExpr),
	strSupplier(pszSupplier) {
	nUserDataCounter++;
}

CUserData::~CUserData(void)
{
	nUserDataCounter--;
}

const char* CUserData::getKey(void)
{
	return this->strIdt;
}

void CUserData::printNode(void)
{
#ifdef _DEBUG
	printf(" %-15s %-10s %-10s %-20s %-12s \n",
		(const char*)strName,
		(const char*)strIdt,
		(const char*)strCategory,
		(const char*)strExpr,
		(const char*)strSupplier,
		getNext());
#else
	printf("%-15s %-10s %-10s %-20s %-12s\n",
		(const char*)strName,
		(const char*)strIdt,
		(const char*)strCategory,
		(const char*)strExpr,
		(const char*)strSupplier);
#endif
}

const char* CUserData::getAdmissionYear(void)
{
	static char szYear[5] = { 0 };  // 4자리 + null
	const char* id = strIdt.getString();

	if (id == nullptr || std::strlen(id) < 4)
		return "";

	strncpy_s(szYear, id, 4);  // 앞 4자리 복사
	szYear[4] = '\0';          // null terminator
	return szYear;
}