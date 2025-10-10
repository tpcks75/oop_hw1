#include "UserData.h"
#include <cstdio>



int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
{
	nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone)
	:strName(pszName), strPhone(pszPhone)
{
	nUserDataCounter++;
}

CUserData::~CUserData(void)
{
	nUserDataCounter--;
}

const char* CUserData::getKey(void)
{
	return this->strName;
}

void CUserData::printNode(void)
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n",
		this,
		// szName, szPhone,
		(const char*)strName,
		(const char*)strPhone,
		getNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}