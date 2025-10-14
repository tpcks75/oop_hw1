#include "IngredientData.h"
#include <cstdio>
#include <cstring>



int CIngredientData::nIngredientDataCounter = 0;

CIngredientData::CIngredientData(void)
{
	nIngredientDataCounter++;
}
CIngredientData::CIngredientData(const char* pszName,
	const char* pszIdt,
	const char* pszCategory,
	const char* pszExpr,
	const char* pszSupplier,
	const char* nCount,
	const char* nPrice)
	: strName(pszName),
	strIdt(pszIdt),
	strCategory(pszCategory),
	strExpr(pszExpr),
	strSupplier(pszSupplier),
	strCount(nCount),
	strPrice(nPrice)

{
	nIngredientDataCounter++;
}

CIngredientData::~CIngredientData(void)
{
	nIngredientDataCounter--;
}

const char* CIngredientData::getKey(void)
{
	return this->strIdt;
}

void CIngredientData::printNode(void)
{
#ifdef _DEBUG
	printf(" %-15s %-10s %-10s %-20s %-12s %5d개 %8d원 \n",
		(const char*)strName,
		(const char*)strIdt,
		(const char*)strCategory,
		(const char*)strExpr,
		(const char*)strSupplier,
		(const char*)strCount,
		(const char*)strPrice);

		getNext();
#else
	printf("%-15s %-10s %-10s %-20s %-12s\n",
		(const char*)strName,
		(const char*)strIdt,
		(const char*)strCategory,
		(const char*)strExpr,
		(const char*)strSupplier);
#endif
}

const char* CIngredientData::getAdmissionYear(void)
{
	static char szYear[5] = { 0 };  // 4자리 + null
	const char* id = strIdt.getString();

	if (id == nullptr || std::strlen(id) < 4)
		return "";

	strncpy_s(szYear, id, 4);  // 앞 4자리 복사
	szYear[4] = '\0';          // null terminator
	return szYear;
}