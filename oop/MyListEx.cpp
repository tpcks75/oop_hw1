#include "MyListEx.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

CMyListEx::CMyListEx(CMyNode *pHead)
	: CMyList(pHead)
{
}

CMyListEx::~CMyListEx(void)
{
}

int CMyListEx::OnAddNewNode(CMyNode* pNewNode)
{
	if (strcmp(pNewNode->getKey(), "�ٺ�") == 0)
		return 0;

	return 1;
}