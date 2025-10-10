#include "MyListEx.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

CMyListEx::CMyListEx()
	: CMyList() ////  기본 생성자 호출 (더미 내부 생성)
{
}

CMyListEx::~CMyListEx(void)
{
}

int CMyListEx::OnAddNewNode(CMyNode* pNewNode)
{
	if (strcmp(pNewNode->getKey(), "바보") == 0)
		return 0;

	return 1;
}